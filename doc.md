# Allowed functions
## readline
```c
char *readline (const char *prompt);
```
get a line from a user with editing

---

## rl_clear_history
```c
void rl_clear_history (void)
```
Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list.

---

## rl_on_new_line
```c
int rl_on_new_line(void);
```
Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.


---

## rl_replace_line
```c
void rl_replace_line (const char *text, int clear_undo)
```
Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.

---

## rl_redisplay
```c
void rl_replace_line (const char *text, int clear_undo)
```
Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.

---

## add_history
```c
void add_history (char *string);
```
Place string at the end of the history list. The associated data field (if any) is set to NULL.

---

## printf
```c
int printf( const char *format, ... );
```


---

## malloc
```c
void *malloc(size_t size);
```
The C library function void *malloc(size_t size) allocates the requested memory and returns a pointer to it.

---

## free
```c
void free(void *ptr);
```
The C library function void free(void *ptr) deallocates the memory previously allocated by a call to calloc, malloc, or realloc.

---

## write
```c
ssize_t write(int fd, const void *buf, size_t count);
```

---

## access
```c
int access(const char *pathname, int mode);
```
access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.

---

## open
```c
int open(const char *pathname, int flags);
```

---

## read
```c
ssize_t read(int fd, void *buf, size_t count);
```
read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

---

## close
```c
int close(int fd);
```
close() closes a file descriptor, so that it no longer refers to any file and may be reused.  Any record locks (see fcntl(2)) held on the file it was associated with, and owned by the process, are removed (regardless of the file descriptor that was used to obtain the lock).

---

## fork
```c
pid_t fork(void);
```
fork() creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.

---

## wait, waitpid
```c
pid_t wait(int *wstatus);
pid_t waitpid(pid_t pid, int *wstatus, int options);
```
All of these system calls are used to wait for state changes in a child of the calling process, and obtain information about the child whose state has changed.  A state change is considered to be: the child terminated; the child was stopped by a signal; or the child was resumed by a signal.  In the case of a terminated child, performing a wait allows the system to release the resources associated with the child; if a wait is not performed, then the terminated child remains in a "zombie" state.

If a child has already changed state, then these calls return immediately.  Otherwise, they block until either a child changes state or a signal handler interrupts the call (assuming that system calls are not automatically restarted using the SA_RESTART flag of sigaction(2)).  In the remainder of this page, a child whose state has changed and which has not yet been waited upon by one of these system calls is termed waitable.

---

## wait3, wait4
```c
pid_t wait3(int *wstatus, int options, struct rusage *rusage);
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);
```
The wait3() and wait4() system calls are similar to waitpid(2),
but additionally return resource usage information about the
child in the structure pointed to by rusage.

Other than the use of the rusage argument, the following wait3()
call:
```c
wait3(wstatus, options, rusage);
```
is equivalent to:
```c
waitpid(-1, wstatus, options);
```

Similarly, the following wait4() call:
```c
wait4(pid, wstatus, options, rusage);
```
is equivalent to:
```c
waitpid(pid, wstatus, options);
```
In other words, wait3() waits of any child, while wait4() can be
used to select a specific child, or children, on which to wait.
See wait(2) for further details.

If rusage is not NULL, the struct rusage to which it points will
be filled with accounting information about the child.  See
getrusage(2) for details.

---
## signal
```c
typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);
```
signal() sets the disposition of the signal signum to handler, which is either SIG_IGN, SIG_DFL, or the address of a programmer-defined function (a "signal handler").

---

## sigaction
```c
int sigaction(int signum, const struct sigaction *restrict act, struct sigaction *restrict oldact);
```
The sigaction() system call is used to change the action taken by a process on receipt of a specific signal.  (See signal(7) for an overview of signals.)

---

## sigemptyset
```c
int sigemptyset(sigset_t *set);
```
The sigemptyset() function initializes the signal set pointed to by set, such that all signals defined in POSIX.1‐2008 are excluded.

---

## sigaddset
```c
int sigaddset(sigset_t *set, int signo);
```
The sigaddset() function adds the individual signal specified by the signo to the signal set pointed to by set.

---

## kill
```c
int kill(pid_t pid, int sig);
```
The kill() system call can be used to send any signal to any process group or process.

---

## exit
```c
noreturn void exit(int status);
```
The exit() function causes normal process termination and the least significant byte of status (i.e., status & 0xFF) is returned to the parent (see wait(2)).

---

## getcwd
```c
char *getcwd(char *buf, size_t size);
```
These functions return a null-terminated string containing an absolute pathname that is the current working directory of the calling process.  The pathname is returned as the function result and via the argument buf, if present.

---

## chdir
```c
int chdir(const char *path);
```
chdir() changes the current working directory of the calling process to the directory specified in path.

---

## stat, lstat, fstat
```c
int stat(const char *restrict pathname, struct stat *restrict statbuf);
int lstat(const char *restrict pathname, struct stat *restrict statbuf);
int fstat(int fd, struct stat *statbuf);
```
These functions return information about a file, in the buffer
pointed to by statbuf.  No permissions are required on the file
itself, but—in the case of stat(), fstatat(), and lstat()—execute
(search) permission is required on all of the directories in
pathname that lead to the file.

stat() and fstatat() retrieve information about the file pointed
to by pathname; the differences for fstatat() are described
below.

lstat() is identical to stat(), except that if pathname is a
symbolic link, then it returns information about the link itself,
not the file that the link refers to.

fstat() is identical to stat(), except that the file about which
information is to be retrieved is specified by the file
descriptor fd.

---

## unlink
```c
int unlink(const char *pathname);
```
unlink() deletes a name from the filesystem.  If that name was
the last link to a file and no processes have the file open, the
file is deleted and the space it was using is made available for
reuse.

---

## execve
```c
int execve(const char *pathname, char *const argv[], char *const envp[]);
```
execve() executes the program referred to by pathname. This
causes the program that is currently being run by the calling
process to be replaced with a new program, with newly initialized
stack, heap, and (initialized and uninitialized) data segments.

---

## dup
```c
int dup(int oldfd);  
```
The dup() system call allocates a new file descriptor that refers
to the same open file description as the descriptor oldfd. (For
an explanation of open file descriptions, see open(2).) The new
file descriptor number is guaranteed to be the lowest-numbered
file descriptor that was unused in the calling process.

---

## dup2
```c
int dup2(int oldfd, int newfd);
```
The dup2() system call performs the same task as dup(), but
instead of using the lowest-numbered unused file descriptor, it
uses the file descriptor number specified in newfd. In other
words, the file descriptor newfd is adjusted so that it now
refers to the same open file description as oldfd.

---

## pipe
```c
pipe( );
```c
 #include <unistd.h>

int pipe(int pipefd[2]);

#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Definition of O_* constants */
#include <unistd.h>

int pipe2(int pipefd[2], int flags);

/* On Alpha, IA-64, MIPS, SuperH, and SPARC/SPARC64, pipe() has the
  following prototype; see NOTES */

#include <unistd.h>

struct fd_pair {
    long fd[2];
   };
struct fd_pair pipe(void);
```
pipe() creates a pipe, a unidirectional data channel that can be
used for interprocess communication.  The array pipefd is used to
return two file descriptors referring to the ends of the pipe.
pipefd[0] refers to the read end of the pipe.  pipefd[1] refers
to the write end of the pipe.  Data written to the write end of
the pipe is buffered by the kernel until it is read from the read
end of the pipe.  For further details, see pipe(7).
```
(stdin)  +-------+
-------->| ls -l |--+
         +-------+  |
                    | (stdout)
                   +-+
                   |P|
                   |I|
                   |P|
                   |E|
                   +-+
                    |
 (stdout) +------+  |(stdin)
<---------|wc -l |--+
          +------+
```

---

## opendir
```c
#include <sys/types.h>

#include <dirent.h>
DIR *opendir(const char *name);
```
The opendir() function opens a directory stream corresponding to
the directory name, and returns a pointer to the directory
stream.  The stream is positioned at the first entry in the
directory.

---

## readdir
```c
#include <dirent.h>

struct dirent *readdir(DIR *dirp);
```
The readdir() function returns a pointer to a dirent structure
representing the next directory entry in the directory stream
pointed to by dirp.  It returns NULL on reaching the end of the
directory stream or if an error occurred.

In the glibc implementation, the dirent structure is defined as
follows:
```c
   struct dirent {
       ino_t          d_ino;       /* Inode number */
       off_t          d_off;       /* Not an offset; see below */
       unsigned short d_reclen;    /* Length of this record */
       unsigned char  d_type;      /* Type of file; not supported
                                      by all filesystem types */
       char           d_name[256]; /* Null-terminated filename */
   };
```

The only fields in the dirent structure that are mandated by
POSIX.1 are d_name and d_ino.  The other fields are
unstandardized, and not present on all systems; see NOTES below
for some further details.

---

## closedir
```c
#include <sys/types.h>
#include <dirent.h>

int closedir(DIR *dirp);
```
The closedir() function closes the directory stream associated
with dirp.  A successful call to closedir() also closes the
underlying file descriptor associated with dirp.  The directory
stream descriptor dirp is not available after this call.

The closedir() function returns 0 on success.  On error, -1 is
returned, and errno is set to indicate the error.


---

## strerror
```c
#include <string.h>

char *strerror(int errnum);
```
The strerror() function returns a pointer to a string that
describes the error code passed in the argument errnum, possibly
using the LC_MESSAGES part of the current locale to select the
appropriate language.  (For example, if errnum is EINVAL, the
returned description will be "Invalid argument".)  This string
must not be modified by the application, but may be modified by a
subsequent call to strerror() or strerror_l().  No other library
function, including perror(3), will modify this string.

---

## perror
```c
#include <stdio.h>

void perror(const char *s);
```

The perror() function produces a message on standard error
describing the last error encountered during a call to a system
or library function.

First (if s is not NULL and *s is not a null byte ('\0')), the
argument string s is printed, followed by a colon and a blank.
Then an error message corresponding to the current value of errno
and a new-line.

To be of most use, the argument string should include the name of
the function that incurred the error.

The global error list sys_errlist[], which can be indexed by
errno, can be used to obtain the error message without the
newline.  The largest message number provided in the table is
sys_nerr-1.  Be careful when directly accessing this list,
because new error values may not have been added to
sys_errlist[].  The use of sys_errlist[] is nowadays deprecated;
use strerror(3) instead.

---

## isatty
```c
#include <unistd.h>

int isatty(int fd);
```
The isatty() function tests whether fd is an open file descriptor
referring to a terminal.

isatty() returns 1 if fd is an open file descriptor referring to
a terminal; otherwise 0 is returned, and errno is set to indicate
the error.

ERRORS
    EBADF  fd is not a valid file descriptor.
    ENOTTY fd refers to a file other than a terminal.  On some older
        kernels, some types of files resulted in the error EINVAL
        in this case (which is a violation of POSIX, which
        specifies the error ENOTTY).

---

## ttyname
```c
#include <unistd.h>

char *ttyname(int fd);
```

The function ttyname() returns a pointer to the null-terminated
pathname of the terminal device that is open on the file
descriptor fd, or NULL on error (for example, if fd is not
connected to a terminal).  The return value may point to static
data, possibly overwritten by the next call.  The function
ttyname_r() stores this pathname in the buffer buf of length
buflen.

RETURN VALUE:
The function ttyname() returns a pointer to a pathname on
success.  On error, NULL is returned, and `errno` is set to
indicate the error.  The function ttyname_r() returns 0 on
success, and an error number upon error.

ERRORS:
EBADF  Bad file descriptor.

ENODEV fd refers to a slave pseudoterminal device but the
        corresponding pathname could not be found (see NOTES).

ENOTTY fd does not refer to a terminal device.

ERANGE (ttyname_r()) buflen was too small to allow storing the
        pathname.

---

## ttyslot
```c
#include <unistd.h>       /* See NOTES */

int ttyslot(void);
```

DESCRIPTION
       The legacy function ttyslot() returns the index of the current
       user's entry in some file.

       Now "What file?" you ask.  Well, let's first look at some
       history.

   Ancient history
       There used to be a file /etc/ttys in UNIX V6, that was read by
       the init(1) program to find out what to do with each terminal
       line.  Each line consisted of three characters.  The first
       character was either '0' or '1', where '0' meant "ignore".  The
       second character denoted the terminal: '8' stood for "/dev/tty8".
       The third character was an argument to getty(8) indicating the
       sequence of line speeds to try ('-' was: start trying 110 baud).
       Thus a typical line was "18-".  A hang on some line was solved by
       changing the '1' to a '0', signaling init, changing back again,
       and signaling init again.

       In UNIX V7 the format was changed: here the second character was
       the argument to getty(8) indicating the sequence of line speeds
       to try ('0' was: cycle through 300-1200-150-110 baud; '4' was for
       the on-line console DECwriter) while the rest of the line
       contained the name of the tty.  Thus a typical line was
       "14console".

       Later systems have more elaborate syntax.  System V-like systems
       have /etc/inittab instead.

   Ancient history (2)
       On the other hand, there is the file /etc/utmp listing the people
       currently logged in.  It is maintained by login(1).  It has a
       fixed size, and the appropriate index in the file was determined
       by login(1) using the ttyslot() call to find the number of the
       line in /etc/ttys (counting from 1).

   The semantics of ttyslot
       Thus, the function ttyslot() returns the index of the controlling
       terminal of the calling process in the file /etc/ttys, and that
       is (usually) the same as the index of the entry for the current
       user in the file /etc/utmp.  BSD still has the /etc/ttys file,
       but System V-like systems do not, and hence cannot refer to it.
       Thus, on such systems the documentation says that ttyslot()
       returns the current user's index in the user accounting data
       base.
RETURN VALUE
       If successful, this function returns the slot number.  On error
       (e.g., if none of the file descriptors 0, 1, or 2 is associated
       with a terminal that occurs in this data base) it returns 0 on
       UNIX V6 and V7 and BSD-like systems, but -1 on System V-like
       systems.

---

## ioctl
```c
#include <sys/ioctl.h>

int ioctl(int fd, unsigned long request, ...);
```

DESCRIPTION
       The ioctl() system call manipulates the underlying device
       parameters of special files.  In particular, many operating
       characteristics of character special files (e.g., terminals) may
       be controlled with ioctl() requests.  The argument fd must be an
       open file descriptor.

       The second argument is a device-dependent request code.  The
       third argument is an untyped pointer to memory.  It's
       traditionally char *argp (from the days before void * was valid
       C), and will be so named for this discussion.

       An ioctl() request has encoded in it whether the argument is an
       in parameter or out parameter, and the size of the argument argp
       in bytes.  Macros and defines used in specifying an ioctl()
       request are located in the file <sys/ioctl.h>.  See NOTES.
RETURN VALUE
       Usually, on success zero is returned.  A few ioctl() requests use
       the return value as an output parameter and return a nonnegative
       value on success.  On error, -1 is returned, and errno is set to
       indicate the error.


---

## getenv
```c
#include <stdlib.h>

char *getenv(const char *name);
```
DESCRIPTION
       The getenv() function searches the environment list to find the
       environment variable name, and returns a pointer to the
       corresponding value string.

       The GNU-specific secure_getenv() function is just like getenv()
       except that it returns NULL in cases where "secure execution" is
       required.  Secure execution is required if one of the following
       conditions was true when the program run by the calling process
       was loaded:

       *  the process's effective user ID did not match its real user ID
          or the process's effective group ID did not match its real
          group ID (typically this is the result of executing a set-
          user-ID or set-group-ID program);

       *  the effective capability bit was set on the executable file;
          or

       *  the process has a nonempty permitted capability set.

       Secure execution may also be required if triggered by some Linux
       security modules.

       The secure_getenv() function is intended for use in general-
       purpose libraries to avoid vulnerabilities that could occur if
       set-user-ID or set-group-ID programs accidentally trusted the
       environment.
RETURN VALUE
       The getenv() function returns a pointer to the value in the
       environment, or NULL if there is no match.

---

## tcsetattr
```c
#include <termios.h>

int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);
```

DESCRIPTION
       The tcsetattr() function shall set the parameters associated with
       the terminal referred to by the open file descriptor fildes (an
       open file descriptor associated with a terminal) from the termios
       structure referenced by termios_p as follows:

        *  If optional_actions is TCSANOW, the change shall occur
           immediately.

        *  If optional_actions is TCSADRAIN, the change shall occur
           after all output written to fildes is transmitted. This
           function should be used when changing parameters that affect
           output.

        *  If optional_actions is TCSAFLUSH, the change shall occur
           after all output written to fildes is transmitted, and all
           input so far received but not read shall be discarded before
           the change is made.

       If the output baud rate stored in the termios structure pointed
       to by termios_p is the zero baud rate, B0, the modem control
       lines shall no longer be asserted. Normally, this shall
       disconnect the line.

       If the input baud rate stored in the termios structure pointed to
       by termios_p is 0, the input baud rate given to the hardware is
       the same as the output baud rate stored in the termios structure.

       The tcsetattr() function shall return successfully if it was able
       to perform any of the requested actions, even if some of the
       requested actions could not be performed. It shall set all the
       attributes that the implementation supports as requested and
       leave all the attributes not supported by the implementation
       unchanged. If no part of the request can be honored, it shall
       return -1 and set errno to [EINVAL].  If the input and output
       baud rates differ and are a combination that is not supported,
       neither baud rate shall be changed. A subsequent call to
       tcgetattr() shall return the actual state of the terminal device
       (reflecting both the changes made and not made in the previous
       tcsetattr() call). The tcsetattr() function shall not change the
       values found in the termios structure under any circumstances.

       The effect of tcsetattr() is undefined if the value of the
       termios structure pointed to by termios_p was not derived from
       the result of a call to tcgetattr() on fildes; an application
       should modify only fields and flags defined by this volume of
       POSIX.1‐2017 between the call to tcgetattr() and tcsetattr(),
       leaving all other fields and flags unmodified.

       No actions defined by this volume of POSIX.1‐2017, other than a
       call to tcsetattr(), a close of the last file descriptor in the
       system associated with this terminal device, or an open of the
       first file descriptor in the system associated with this terminal
       device (using the O_TTY_INIT flag if it is non-zero and the
       device is not a pseudo-terminal), shall cause any of the terminal
       attributes defined by this volume of POSIX.1‐2017 to change.

       If tcsetattr() is called from a process which is a member of a
       background process group on a fildes associated with its
       controlling terminal:

        *  If the calling thread is blocking SIGTTOU signals or the
           process is ignoring SIGTTOU signals, the operation completes
           normally and no signal is sent.

        *  Otherwise, a SIGTTOU signal shall be sent to the process
           group.
RETURN VALUE
       Upon successful completion, 0 shall be returned. Otherwise, -1
       shall be returned and errno set to indicate the error.
ERRORS
       The tcsetattr() function shall fail if:

       EBADF  The fildes argument is not a valid file descriptor.

       EINTR  A signal interrupted tcsetattr().

       EINVAL The optional_actions argument is not a supported value, or
              an attempt was made to change an attribute represented in
              the termios structure to an unsupported value.

       EIO    The process group of the writing process is orphaned, the
              calling thread is not blocking SIGTTOU, and the process is
              not ignoring SIGTTOU.

       ENOTTY The file associated with fildes is not a terminal.

---

## tcgetattr
```c
#include <termios.h>

int tcgetattr(int fildes, struct termios *termios_p);
```

DESCRIPTION
       The tcgetattr() function shall get the parameters associated with
       the terminal referred to by fildes and store them in the termios
       structure referenced by termios_p.  The fildes argument is an
       open file descriptor associated with a terminal.

       The termios_p argument is a pointer to a termios structure.

       The tcgetattr() operation is allowed from any process.

       If the terminal device supports different input and output baud
       rates, the baud rates stored in the termios structure returned by
       tcgetattr() shall reflect the actual baud rates, even if they are
       equal. If differing baud rates are not supported, the rate
       returned as the output baud rate shall be the actual baud rate.
       If the terminal device does not support split baud rates, the
       input baud rate stored in the termios structure shall be the
       output rate (as one of the symbolic values).
RETURN VALUE
       Upon successful completion, 0 shall be returned. Otherwise, -1
       shall be returned and errno set to indicate the error.
ERRORS
       The tcgetattr() function shall fail if:

       EBADF  The fildes argument is not a valid file descriptor.

       ENOTTY The file associated with fildes is not a terminal.

---

## tgetent tgetflag tgetnum tgetstr tgoto
```c
#include <curses.h>
#include <term.h>

extern char PC;
extern char * UP;
extern char * BC;
extern unsigned ospeed;

int tgetent(char *bp, const char *name);
int tgetflag(char *id);
int tgetnum(char *id);
char *tgetstr(char *id, char **area);
char *tgoto(const char *cap, int col, int row);
int tputs(const char *str, int affcnt, int (*putc)(int));
```

Description
These routines are included as a conversion aid for programs that use the termcap library. Their parameters are the same and the routines are emulated using the terminfo database. Thus, they can only be used to query the capabilities of entries for which a terminfo entry has been compiled.

The tgetent routine loads the entry for name. It returns 1 on success, 0 if there is no such entry, and -1 if the terminfo database could not be found. The emulation ignores the buffer pointer bp.

The tgetflag routine gets the boolean entry for id, or zero if it is not available.

The tgetnum routine gets the numeric entry for id, or -1 if it is not available.

The tgetstr routine returns the string entry for id, or zero if it is not available. Use tputs to output the returned string. The return value will also be copied to the buffer pointed to by area, and the area value will be updated to point past the null ending this value.

Only the first two characters of the id parameter of tgetflag, tgetnum and tgetstr are compared in lookups.

The tgoto routine instantiates the parameters into the given capability. The output from this routine is to be passed to tputs.

The tputs routine is described on the curs_terminfo(3X) manual page. It can retrieve capabilities by either termcap or terminfo name.

The variables PC, UP and BC are set by tgetent to the terminfo entry's data for pad_char, cursor_up and backspace_if_not_bs, respectively. UP is not used by ncurses. PC is used in the tdelay_output function. BC is used in the tgoto emulation. The variable ospeed is set by ncurses in a system-specific coding to reflect the terminal speed.

Return Value
Except where explicitly noted, routines that return an integer return ERR upon failure and OK (SVr4 only specifies "an integer value other than ERR") upon successful completion.

Routines that return pointers return NULL on error.

---