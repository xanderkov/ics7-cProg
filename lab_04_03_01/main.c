#include "revers_and_operate.h"
#include "defines.h"


int main()
{
    char s[N + 3] = { ' ' }, words[N][WORD_LEN + 1], new_s[N + 1] = { '\0' };
    char delim[] = { ' ', ',', ';', ':', '-', '.', '!', '?', '\n', '\0' };
    int rc = OK, n = 0;
    fgets(s, sizeof(s), stdin);
    if (input_str(s) != OK)
        return INPUT_SIZE;
    char *token;
    token = strtok(s, delim);
    while (token != NULL) 
    {
        my_memcpy(token, words[n++]);
        token = strtok(NULL, delim);   
    }
    reverse(words, n, new_s);
    if (new_s[0] == '\0')
        return EMPTY_STR;
    if (rc == OK)
        printf("%s%s", "Result:", new_s);
    return rc;
}
