#include "../includes/my_bsq.h"
#include "../includes/utils.h"

#define READLINE_READ_SIZE 150
int my_strlen(char *s)
{
    int len = 0;

    if (!s)
    return len;
    while (s[len])
    len++;
    return len;
}

char *my_strjoin(char *s1, char *s2)
{
    int i = 0;
    char *result;

    result = (char *)malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)) + 1);
    if (!result || !s1 || !s2)
    return NULL;

    while (*s1)
    result[i++] = *s1++;

while (*s2)
    result[i++] = *s2++;

result[i] = '\0';

return result;
}

char *my_strdup(char *str)
{
    char *cpy_str = NULL;
    int index = 0;

    cpy_str = (char *)malloc((my_strlen(str) + 1) * sizeof(char));
    if (!cpy_str || !str)
        return NULL;
    
    while (str[index] != '\0')
    {
        cpy_str[index] = str[index];
        index++;
    }

    cpy_str[index] = '\0';

    return cpy_str;
}

char *my_strsub(char *str, int start, int len)
{
    char *ptr;
    int i;

    ptr = (char *)malloc(sizeof(char) * (len + 1));
    if (!ptr || !str)
        return NULL;

    str = str + start;
    i = 0;
    while (i < len)
    {
        ptr[i] = str[i];
        i++;
    }

    ptr[i] = '\0';
    return ptr;
}

char *my_strchr(char *str, char c)
{
    int len = 0;
    char *ptr = str;

    len = my_strlen(str) + 1;
    while(len--)
    {
        if (*ptr == c)
            return ptr;
        ptr++;
    }

    return NULL;
}

void my_strclr(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}

void read_and_save(int fd, char **line)
{
    int rd = 0;
    char buf[READLINE_READ_SIZE + 1];
    char *tmp = NULL;

    while ((rd = read(fd, buf, READLINE_READ_SIZE)))
    {
        if (rd == -1)
            break;
        buf[rd] = '\0';
        if (*line)
        {
            tmp = my_strjoin(*line, buf);
            free(*line);
            *line = tmp;
        }
        else
            *line = my_strdup(buf);

        if (my_strchr(*line, '\n'))
            break;
    }
}

char *output_line(char **line, int len)
{
    char *result = NULL;
    char *tmp = NULL;

    if ((*line)[len] == '\n')
    {
        result = my_strsub((*line), 0, len);
        tmp = my_strdup(&(*line)[len + 1]);
        free(*line);
        *line = tmp;
        if ((*(*line)) == '\0')
        my_strclr(line);
    }
    else
    {
        result = my_strdup(*line);
        my_strclr(line);
    }

    return result;
}

int line_len(char **line)
{
    int len = 0;

    if (*line)
    {
    while ((*line)[len] != '\n' && (*line)[len] != '\0')
        len++;
    }
    else
    return -1;

    return len;
}

char *my_readline(int fd)
{
    static char *line[100];
    int len = 0;
    char *result = NULL; 

    if (fd < 0)
        return NULL;
    
    read_and_save(fd, line);

    if ((len = line_len(line)) < 0)
        return NULL;

    result = output_line(line, len);

    return result;
}