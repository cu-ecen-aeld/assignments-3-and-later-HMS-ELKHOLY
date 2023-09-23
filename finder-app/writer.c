#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <stdio.h>

#include <malloc.h>
#include <string.h>

#define log(l,o,par) { \
openlog("writerHms",LOG_CONS,o); \
syslog(0,"%s%s",l,par); \
closelog();}

int main (int argc, char *argv[]) {
if (argc<3)
{
    log("error params",LOG_PERROR,argv[1]);

    //printf("AARRR");
    return 1;
}

int fd;
fd = open (argv[1], O_WRONLY | O_CREAT | O_APPEND  | O_SYNC,0666 ) ;
 

  
ssize_t nr;

if (fd == -1){
log("error openning",LOG_PERROR,argv[1]);
}
else
{
log("success openning",LOG_DEBUG,argv[1]);
 //printf("2AAAAAAAAAAAAA\n%s","");

/* write the string in 'buf' to 'fd' */
char * buf = malloc((strlen(argv[2])+10)*sizeof(char));
strcpy(buf,argv[2]);
strcat(buf,"\n");

//printf("%s",buf);

nr = write (fd, buf, strlen (buf));
if (nr == -1){
log("error writing",LOG_PERROR,argv[1]);
return 1;
}

else{
log("success writing",LOG_DEBUG,argv[1]);}
 //printf("3AAAAAAAAAAAAA\n%s","");

}
if (close (fd) == -1)
{log("error closing",LOG_PERROR,argv[1]);
return 1;
}

else{
log("success closing",LOG_DEBUG,argv[1]);

}
 //printf("4AAAAAAAAAAAAA\n%s","");

}
