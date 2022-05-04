#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*gnl;
	static char	buf[BUFFER_SIZE];
	char		*tmp;
	char		*add;

	add = buf;
	gnl = NULL;
	tmp = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (buf[0])
		gnl = find_line(&tmp, &add);
	if (gnl)
		return (gnl);
	free(gnl);
	while (read(fd, add, BUFFER_SIZE) > 0)
	{
		gnl = find_line(&tmp, &add);
		if (gnl)
			return (gnl);
	}
	if (!gnl)
		return (tmp);
	free(tmp);
	return (NULL);
}
