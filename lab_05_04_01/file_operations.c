#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "file_operations.h"
#define OK 0
#define M 100
#define NO_FILE -1
#define NO_INFO -2
#define BAD_POS -4
#define SUM_SYMB -5
#define WRONG_SYM -6
#define NUM_NAME 11
#define NUM_L_NAME 26
#define NUM_GRADES 4
#define N 259
#define SYMBOLS_NUM 59
#define ENGLISH_ALPHA 28
#define FALSE -1
#define WORD_LEN 30
#define WORDS_IN_STUDENT 6


typedef struct
{
    char lastname[NUM_L_NAME + 1];
    char name[NUM_NAME + 1];
    unsigned int grades[NUM_GRADES];
} student_t;


void copy_str(char s[], char s2[])
{
    int i = 0;
    for (i = 0; s[i] != '\0'; i++)
        s2[i] = s[i];
    s2[i] = '\0';
}


int read_struct(FILE *f, student_t *s)
{
    return fscanf(f, "%s %s %u %u %u %u", s->lastname, s->name, &(s)->grades[0], &(s)->grades[1], &(s)->grades[2], &(s)->grades[3]);
}


int read_file(FILE *f, student_t students[], unsigned int *n)
{
    unsigned int i = 0;
    while (read_struct(f, &students[i]) == 6)
    {
        if (strlen(students[i].lastname) >= NUM_L_NAME)
            return WRONG_SYM;
        if (strlen(students[i].name) >= NUM_NAME)
            return WRONG_SYM;
        i++;
    }
    if (i == 0)
        return NO_INFO;
    *n = i;
    return OK;
}


unsigned int calc_ave_mark(student_t students[], unsigned int n)
{
    unsigned int sum = 0;
    for (unsigned int j = 0; j < n; j++)
    {
        for (int i = 0; i < NUM_GRADES; i++)
            sum += students[j].grades[i];
    }
    return sum;
}


unsigned int calc_mark(student_t student)
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < NUM_GRADES; i++)
        sum += student.grades[i];
    return sum;
}


void print_stu(FILE *f, student_t student)
{
    fprintf(f, "%s\n", student.lastname);
    fprintf(f, "%s\n", student.name);
    for (int j = 0; j < NUM_GRADES - 1; j++)
        fprintf(f, "%u ", student.grades[j]);
    fprintf(f, "%u\n", student.grades[NUM_GRADES - 1]);
}


int delete_students(FILE *f, char *name)
{
    student_t students[M] = { { "Alexandrov", "Anatoliy", { 0, 0, 0, 0 } } };
    unsigned int n = 0;
    unsigned int ave_mark = -1, mark = -1;
    int rc = WRONG_SYM;
    rc = read_file(f, students, &n);
    if (rc != OK)
        return WRONG_SYM;
    f = fopen(name, "w");
    ave_mark = calc_ave_mark(students, n);
    for (unsigned int i = 0; i < n; i++)
    {
        mark = calc_mark(students[i]) * n;
        if (mark >= ave_mark)
        {
            print_stu(f, students[i]);
        }
    }
    return OK;
}


int compare_subword(char a[], char b[])
{
    int i = 0;
    while (b[i] != '\0')
    {
        if (a[i] != b[i])
            return FALSE;
        i++;
    }
    return OK;
}


void swap_struct(student_t *s1, student_t *s2)
{
    student_t c = { "Alexandrov", "Anatoliy", { 0, 0, 0, 0 } };
    c = *s1;
    *s1 = *s2;
    *s2 = c;
}


int print_students(FILE *f, FILE *out, char substr[])
{
    student_t students[M] = { { "Alexandrov", "Anatoliy", { 0, 0, 0, 0 } } };
    unsigned int n = 0, num = 0;
    int rc = 0;
    rc = read_file(f, students, &n);
    if (rc != OK)
        return WRONG_SYM;
    for (unsigned int i = 0; i < n; i++)
    {
        if (compare_subword(students[i].lastname, substr) == OK)
        {
            num++;
            print_stu(out, students[i]);
        }
    }
    if (num == 0)
        return WRONG_SYM;
    return OK;
}



int sort_students(FILE *f)
{
    unsigned int n = 0;
    student_t students[M] = { { "Alexandrov", "Anatoliy", { 0, 0, 0, 0 } } };
    int rc = 0, eq = 0;
    rc = read_file(f, students, &n);
    if (rc != OK)
        return WRONG_SYM;
    for (unsigned int i = 0; i < n - 1; i++)
    {
        for (unsigned int j = 0; j < n - i - 1; j++)
        {
            eq = strcmp(students[j].lastname, students[j + 1].lastname);
            if (eq > 0)
            {
                swap_struct(&students[j], &students[j + 1]);
            }
            else if (eq == 0)
            {
                eq = strcmp(students[j].name, students[j + 1].name);
                if (eq > 0)
                {
                    swap_struct(&students[j], &students[j + 1]);
                }
            }
        }
    }
    for (unsigned int i = 0; i < n; i++)
    {
        print_stu(stdout, students[i]);
    }
    return OK;
}


