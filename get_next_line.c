#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char    *gnl;
    static char buf[1024][BUFFER_SIZE];
    char    *tmp;

//    tmp = malloc(sizeof(char));
    gnl = NULL;
    tmp = NULL;
    if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
        return (NULL);
//    tmp[0] = '\0';
//    if (!buf[fd][0])
//        buf[fd][0] = '\0';
    if (buf[fd][0])
        gnl = find_line(&tmp, buf[fd]);
    if (gnl)
        return (gnl);
    free(gnl);
    while (read(fd, buf[fd], BUFFER_SIZE) > 0)
    {
        //printf("\n%s\n", buf[fd]);
        gnl = find_line(&tmp, buf[fd]);
        if (gnl)
            return (gnl);
    }
    if (!gnl)
        return (tmp);
    free(tmp);
    return (NULL); 
}
