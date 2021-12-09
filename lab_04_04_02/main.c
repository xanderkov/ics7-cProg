#include "defines.h"


int is_working(char *s)
{
    char words[N][WORD_LEN + 1];
    int i = 0, n = 0;
    while (s[i] != '\0')
        i++;
    if (i > N + 1)
        return INPUT_SIZE;
    if (s[0] != '\0' && split_line(s, words, &n) == OK && n == 3 && check_all(words) == OK)
    {
        printf("YES");
        return OK;
    }
    printf("NO");
    return OK;
}


int main()
{
    char s[N + 3] = { ' ' };
    fgets(s, sizeof(s), stdin);
    return is_working(s);
}
