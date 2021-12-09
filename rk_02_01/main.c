#include <stdio.h>
#include <math.h>
#define N 1300
#define M 100
#define OK 0
#define NULL_FILE -1


typedef struct
{
    char city[M];
    char region[M];
    char okrug[M];
    int number;
    int birth;
} town;

int read_line(FILE *f, char s[])
{
    char c;
    int i = 0;
    fscanf(f, "%c", &c);
    s[i] = c;
    while (c != '\n')
    {
        i++;
        s[i] = c;
        fscanf(f, "%c", &c);
    }
    if (i > 0)
    {
        s[i] = '\0';
        return 1;
    }
    else
    {
        return -1;
    }


}


int read_file(FILE *f, town cytes[], int *n)
{
    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%s", cytes[i].city);
        fscanf(f, "%s", cytes[i].region);
        fscanf(f, "%s", cytes[i].okrug);

        fscanf(f, "%d", &(cytes[i]).number);
        fscanf(f, "%d", &(cytes[i]).birth);
    }
    return OK;
}

int average_age(town cytes[], FILE *f, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (2021 - cytes[i].birth);
    }
    int ave_sum = sum / n;
    fprintf(f, "%d\n", ave_sum);
    return OK;
}

int number_of_rsk_town(town cytes[], FILE *f, int n)
{
    char s[4] = { 'r', 's', 'k', '\0'};
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0, t = 0;
        while (cytes[i].city[j] != '\0')
        {
            while (s[t] != '\0')
            {
                if (s[t] != cytes[i].city[j + t])
                {
                    break;
                }
                t++;
            }
            if (cytes[i].city[j + t] =='\0' && t == 3)
                num++;
            t = 0;
            j++;
        }
    }
    fprintf(f, "%d", num);
    return OK;
}



int main()
{
    FILE *in = fopen("in.txt", "r"), *out= fopen("out.txt", "w");
    if (in == NULL)
    {
        printf("HERE_NO_FILe\n");
        return NULL_FILE;
    }
    town cytes[N];
    int rc = OK, n = 0;
    rc = read_file(in, cytes, &n);
    if (n > 0)
    {
        rc = average_age(cytes, out, n);
        rc = number_of_rsk_town(cytes, out, n);
    }
    return rc;
}
