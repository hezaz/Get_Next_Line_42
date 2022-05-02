#include "get_next_line.h"

void	setzaz(char *t)
{
	t[0] = 'z';
	t[1] = 'a';
}

int	main()
{
	char t[2][2];

	t[0][0] = 'h';
	t[0][1] = 'e';
	t[1][0] = 'd';
	t[1][1] = 'i';
	//setzaz(t[0]);
	printf("\n%c %c\n", t[0][0], t[0][1]);
	return (0);

}

