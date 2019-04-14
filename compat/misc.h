#ifndef _COMPAT_MISC_H_
#define _COMPAT_MISC_H_

#define setresgid(a,b,c) setgid(a)
#define setresuid(a,b,c) setuid(a)

#endif
