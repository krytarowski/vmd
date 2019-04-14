#define	SO_PEERCRED LOCAL_PEEREID

struct sockpeercred {
	pid_t pid;		/* process id */
	uid_t uid;		/* effective user id */
	gid_t gid;		/* effective group id */
};
