#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char *line[1];
	int fd;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("BUFFER SIZE %d\n", BUFFER_SIZE);
	while ((i = get_next_line(fd, line)) > 0)
	{
		printf("%s\t\n", *line);
		free (*line);
	}
	printf("%s\t\n", *line);
	free (*line);
	if (i < 0)
		printf("ERROR\n");
	return (0);
}