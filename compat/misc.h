#ifndef _COMPAT_MISC_H_
#define _COMPAT_MISC_H_

#include <sys/param.h>
#include <sys/types.h>

#include <limits.h>
#include <unistd.h>

#define setresgid(a,b,c) setgid(a)
#define setresuid(a,b,c) setuid(a)
#define nitems(_a)      (sizeof((_a)) / sizeof((_a)[0]))

static inline int pledge(const char *a, const char *b){return 0;}

#define	PCI_CONFIG_SPACE_SIZE		0x100
#define PAGE_SIZE getpagesize()
#define	PAGE_MASK	(PAGE_SIZE - 1)


#define PT_OPENBSD_RANDOMIZE	0x65a3dbe6	/* fill with random data */
#define ELF_CTF		".SUNW_ctf"	/* CTF data */

#define	PCI_VENDOR_OPENBSD	0x0b5d		/* OpenBSD */

/* OpenBSD VMM products */
#define	PCI_PRODUCT_OPENBSD_PCHB	0x0666		/* VMM Host */
#define	PCI_PRODUCT_OPENBSD_CONTROL	0x0777		/* VMM Control */

#define PCI_EXROMADDR_0	0x30

#define PTMGET /* OpenBSD name */ TIOCPTMGET /* NetBSD name */
#define PATH_PTMDEV "/dev/ptm.h"

#define	PCI_PRODUCT_QUMRANET_VIO_RNG	0x1005		/* Virtio RNG */
#define	PCI_PRODUCT_QUMRANET_VIO_NET	0x1000		/* Virtio Network */
#define	PCI_PRODUCT_QUMRANET_VIO_BLOCK	0x1001		/* Virtio Storage */
#define	PCI_PRODUCT_QUMRANET_VIO_MEM	0x1002		/* Virtio Memory Balloon */
#define	PCI_PRODUCT_QUMRANET_VIO_CONS	0x1003		/* Virtio Console */
#define	PCI_PRODUCT_QUMRANET_VIO_SCSI	0x1004		/* Virtio SCSI */

#define		TIOCUCNTL_CBRK (TIOCCBRK & 0xff)/* clear break bit, usr ctnl */
#define		TIOCUCNTL_SBRK (TIOCSBRK & 0xff)/* set break bit, usr ctnl */

typedef	int32_t		daddr32_t;

#define strnvis_openbsd(a,b,c,d) strnvis(a,c,b,d)

#define RB_CONFIG RB_USERCONF

struct dos_partition {
        u_int8_t        dp_flag;        /* bootstrap flags */
        u_int8_t        dp_shd;         /* starting head */   
        u_int8_t        dp_ssect;       /* starting sector */
        u_int8_t        dp_scyl;        /* starting cylinder */
        u_int8_t        dp_typ;         /* partition type (see below) */
        u_int8_t        dp_ehd;         /* end head */
        u_int8_t        dp_esect;       /* end sector */
        u_int8_t        dp_ecyl;        /* end cylinder */
        u_int32_t       dp_start;       /* absolute starting sector number */
        u_int32_t       dp_size;        /* partition size in sectors */
};


/* Known DOS partition types. */
#define DOSPTYP_UNUSED  0x00            /* Unused partition */
#define DOSPTYP_FAT12   0x01            /* 12-bit FAT */
#define DOSPTYP_FAT16S  0x04            /* 16-bit FAT, less than 32M */                                                                                      
#define DOSPTYP_EXTEND  0x05            /* Extended; contains sub-partitions */
#define DOSPTYP_FAT16B  0x06            /* 16-bit FAT, more than 32M */
#define DOSPTYP_NTFS    0x07            /* NTFS */
#define DOSPTYP_FAT32   0x0b            /* 32-bit FAT */
#define DOSPTYP_FAT32L  0x0c            /* 32-bit FAT, LBA-mapped */
#define DOSPTYP_FAT16L  0x0e            /* 16-bit FAT, LBA-mapped */
#define DOSPTYP_EXTENDL 0x0f            /* Extended, LBA-mapped; (sub-partitions) */
#define DOSPTYP_ONTRACK 0x54
#define DOSPTYP_LINUX   0x83            /* That other thing */                                                                                               
#define DOSPTYP_FREEBSD 0xa5            /* FreeBSD partition type */
#define DOSPTYP_OPENBSD 0xa6            /* OpenBSD partition type */
#define DOSPTYP_NETBSD  0xa9            /* NetBSD partition type */
#define DOSPTYP_EFI     0xee            /* EFI Protective Partition */
#define DOSPTYP_EFISYS  0xef            /* EFI System Partition */

/* DOS partition table -- located at start of some disks. */
#define DOS_LABELSECTOR 1
#define DOSBBSECTOR     0               /* DOS boot block relative sector # */
#define DOSPARTOFF      446
#define DOSDISKOFF      444
#define NDOSPART        4
#define DOSACTIVE       0x80 

#define DOSMBR_SIGNATURE        (0xaa55)
#define DOSMBR_SIGNATURE_OFF    (0x1fe)

/* Maximum number of Extended Boot Records (EBRs) to traverse. */
#define DOS_MAXEBR      256

struct dos_mbr {
        u_int8_t                dmbr_boot[DOSPARTOFF];
        struct dos_partition    dmbr_parts[NDOSPART];                                                                                                        
        u_int16_t               dmbr_sign;
} __packed;

#define NIADDR	3 /* Indirect addresses in inode. */

typedef u_int32_t	ufsino_t;

#define	ROOTINO	((ufsino_t)2)

#define	SYMLOOP_MAX		   sysconf(_SC_SYMLOOP_MAX)

#define fsbtodb(fs, b)	((b) << (fs)->fs_fsbtodb)
#define NDADDR	12 /* Direct addresses in inode. */ 
#define FS_MAGIC	0x011954 /* the fast filesystem magic number */ 
#define SBSIZE	8192
#define BBSIZE		8192
#define	BBOFF		((off_t)(0))
#define	SBOFF		((off_t)(BBOFF + BBSIZE))
#define	BBLOCK		((daddr_t)(0))
#define	SBLOCK		((daddr_t)(BBLOCK + BBSIZE / DEV_BSIZE))

#define blkoff(fs, loc)		/* calculates (loc % fs->fs_bsize) */ \
	((loc) & (fs)->fs_qbmask)

#define lblkno(fs, loc)		/* calculates (loc / fs->fs_bsize) */ \
	((loc) >> (fs)->fs_bshift)

#define fragroundup(fs, size)	/* calculates roundup(size, fs->fs_fsize) */ \
	(((size) + (fs)->fs_qfmask) & (fs)->fs_fmask)

#define dblksize(fs, dip, lbn) \
	(((lbn) >= NDADDR || (dip)->di_size >= ((lbn) + 1) << (fs)->fs_bshift) \
	    ? (u_int64_t)(fs)->fs_bsize \
	    : (fragroundup(fs, blkoff(fs, (dip)->di_size))))

#define	NINDIR(fs)	((fs)->fs_nindir)
#define	di_shortlink	di_db

int scan_scaled(char *scaled, long long *result);

#define RT_TABLEID_MAX	255 

#endif
