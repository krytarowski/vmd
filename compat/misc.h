#ifndef _COMPAT_MISC_H_
#define _COMPAT_MISC_H_

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

#endif
