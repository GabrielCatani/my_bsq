#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFF_SIZE 23

int  my_strlen(char *str){
    int len = 0;
    if (!str)
        return len;
    while (str[len] != '\0')
        len++;
    
    return len;
}

char *my_strsub(char *str, int start, int len){
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


void  add_to_line(char **line, char *buf){
    int i = 0;
    char *to_line = NULL;

    while (buf[i] != '\0' && buf[i] != '\n')
        i++;
    
    if (!(*line))
        to_line = my_strsub(buf, 0, i);
    else
        to_line = my_strjoin((*line), buf);
    
    *line = to_line;   
}

void my_strclr(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}

char *my_readline(int fd){
    static char *line_remainder;
    char buf[BUFF_SIZE + 1];
    char *line = NULL;
    char *ptr = NULL;
    int rd = 0;
    int i = 0;

    if (line_remainder){
        line = my_strdup(line_remainder);
        my_strclr(&line_remainder);
    }

    while ((rd = read(fd, buf, BUFF_SIZE))){
        buf[rd] = '\0';
        add_to_line(&line, buf);
        printf("%s\n", line);
        if (ptr = my_strchr(buf, '\n')){
            line_remainder = my_strdup(ptr);
            printf("aqui man %s", ptr);
            break;
        }
    }

    return line;
}

int  main(){
    int fd = 0;
    fd = open("./test", O_RDONLY);
    printf("%s\n", my_readline(fd));

    return 0;
}