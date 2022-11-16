#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char *line[1];
	int fd1;
	int fd2;
	int i;

	i = 0;
	fd1 = open("FD1.txt", O_RDONLY);
	fd2 = open("FD2.txt", O_RDONLY);
	printf("BUFFER SIZE %d\n", BUFFER_SIZE);

	i = get_next_line(fd1, line);
	printf("%s\t\n", *line);
	free (*line);

	i = get_next_line(fd1, line);
	printf("%s\t\n", *line);
	free (*line);

	i = get_next_line(fd2, line);
	printf("%s\t\n", *line);
	free (*line);

	i = get_next_line(fd1, line);
	printf("%s\t\n", *line);
	free (*line);

	i = get_next_line(fd2, line);
	printf("%s\t\n", *line);
	free (*line);

	i = get_next_line(fd2, line);
	printf("%s\t\n", *line);
	free (*line);

	if (i < 0)
		printf("ERROR\n");
	return (0);
}