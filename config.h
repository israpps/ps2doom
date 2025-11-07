/* config.h.  Generated automatically by configure.  */
/* config.h.in.  Generated automatically from configure.in by autoheader.  */

/* Define to empty if the keyword does not work.  */
/* #undef const */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef gid_t */

/* Define as __inline if that's what the C compiler calls it.  */
/* #undef inline */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef pid_t */

/* Define to `unsigned' if <sys/types.h> doesn't define.  */
/* #undef size_t */

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if `sys_siglist' is declared by <signal.h>.  */
/* #undef SYS_SIGLIST_DECLARED */

/* Define to `int' if <sys/types.h> doesn't define.  */
/* #undef uid_t */

/* Define to strcasecmp, if we have it */
#define stricmp strcasecmp

/* Define to strncasecmp, if we have it */
#define strnicmp strncasecmp

/* Define for gnu-linux target */
/* #undef LINUX */

/* Define for freebsd target */
/* #undef FREEBSD */

/* Define on I386 target */
/* #define I386 1 */

/* Define for high resolution support */
#define HIGHRES 1

/* Define to enable internal range checking */
/* #undef RANGECHECK */

/* Define this to see real-time memory allocation
 * statistics, and enable extra debugging features 
 */
/* #undef INSTRUMENTED */

/* Uncomment this to exhaustively run memory checks
 * while the game is running (this is EXTREMELY slow).
 * Only useful if INSTRUMENTED is also defined.
 */
/* #undef CHECKHEAP */

/* Uncomment this to perform id checks on zone blocks,
 * to detect corrupted and illegally freed blocks
 */
#define ZONEIDCHECK 1

/* CPhipps - some debugging macros for the new wad lump handling code */
/* Defining this causes quick checks which only impose an overhead if a 
 *  posible error is detected. */
#define SIMPLECHECKS 1

/* Defining this causes time stamps to be created each time a lump is locked, and 
 *  lumps locked for long periods of time are reported */
/* #undef TIMEDIAG */

/* Define this to revoke any setuid status at startup (except to be reenabled 
 * when SVGALib needs it). Ony relevant to the SVGALib/Linux version */
/* #undef SECURE_UID */

/* Define to be the path where Doom WADs are stored */
#define DOOMWADDIR ""

/* Define if you have the inet_aton function.  */
#define HAVE_INET_ATON 1

/* Define if you have the snprintf function.  */
#define HAVE_SNPRINTF 1

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1

/* Define if you have the <linux/joystick.h> header file.  */
/* #undef HAVE_LINUX_JOYSTICK_H */

/* Define if you have the <sys/filio.h> header file.  */
/* #undef HAVE_SYS_FILIO_H */

/* Define if you have the <sys/ioctl.h> header file.  */
#define HAVE_SYS_IOCTL_H 1

/* Name of package */
#define PACKAGE "PS2Doom"

/* Version number of package */
#define VERSION "1.0"

