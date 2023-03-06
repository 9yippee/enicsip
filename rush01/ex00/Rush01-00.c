#include <unistd.h>

void    print_str(char *str);
void    set_str(char *str);

int main(int argc, char **argv)
{
    char    *side;
    char    str[17];

    side = &*argv[1];
    str[16] = '\0';
    while (1)
    {
        set_str(str);
        print_str(str);
    }
}

void    print_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (i % 4 == 0)
            write(1, "\n", 1);
        write(1, &str[i], 1);
        i++;
    }
}

void    set_str(char *str)
{
    int     i;
    char    setch;

    i = 0;
    setch = '1';
    while (str[i] != '\0')
    {
        str[i] = setch;
        i++;
        setch++;
    }
}