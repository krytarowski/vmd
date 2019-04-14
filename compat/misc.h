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

#endif
