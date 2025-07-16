#include "../../cub3d.h"

int parse_cub_file(char *filename)
{
    int     fd;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("open file failed !!");
        return (1);
    }
    line = get_next_line(fd);
    while (line)
    {
        if (line[0] == '\n')
        {
            free(line);
            continue ;
        }

        printf("Read line: %s", line);

        free (line);
        line = get_next_line(fd);
    }
    close (fd);
    return (0);
}
