#include "defines.h"
#include "my_snprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare_strings(char *str, char *check_str, int n, int n_check)
{
	int rc = ERR;
	if (!strcmp(str, check_str) && n == n_check)
		rc = OK;
	else
	{
		printf("%s\n", str);
		printf("%s\n", check_str);
		printf("%d\n", n_check);
		printf("%d\n", n);
	}
	return rc;
}

int test_1_digit()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, 16, "c %d poehali", 15);
	n_check = my_snprintf(str, 16, "c %d poehali", 15);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}

int test_1_string()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, 6, "c %s", "Sus");
	n_check = my_snprintf(str, 6, "c %s", "Sus");
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}

int test_2_string()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, sizeof(check_str), "c %s %d%s%x", "Sus", 88, "amogus", 523);
	n_check = my_snprintf(str, sizeof(str), "c %s %d%s%x", "Sus", 88, "amogus", 523);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}

int test_1_char()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, sizeof(check_str), "c %c", 'S');
	n_check = my_snprintf(str, sizeof(check_str), "c %c", 'S');
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}

int test_2_minus_digit()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, sizeof(check_str), "c %d", -16);
	n_check = my_snprintf(str, sizeof(check_str), "c %d", -16);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}


int test_2_chars()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	n = snprintf(check_str, sizeof(check_str), "%c%c%c%c%c", 'H', 'e', 'l', 'l', 'o');
	n_check = my_snprintf(str, sizeof(check_str), "%c%c%c%c%c", 'H', 'e', 'l', 'l', 'o');
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}

int test_3_string()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	const char *s = "Loooooooooooooooooooooooooooooong!";
	n = snprintf(check_str, sizeof(check_str), "c %s", s);
	n_check = my_snprintf(str, sizeof(check_str), "c %s", s);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;	
}

int test_4_string()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	const char *s = "Loooooooooooooooooooooooooooooong!";
	n_check = snprintf(check_str, 10, "%s", s);
	n = my_snprintf(str, 10, "%s", s);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;	
}


int test_long_string()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	const char *s = "Loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong!";
	n_check = snprintf(check_str, N, "%s", s);
	n = my_snprintf(str, N, "%s", s);
	rc = compare_strings(str, check_str, n, n_check);
	return rc;
}


int test_limits()
{
	char *check_str = malloc(6), *str = malloc(6);
	int rc = ERR, n, n_check;
	
	const char *s = "0123456";
	n = my_snprintf(str, 5, "%s", s);
	n_check = snprintf(check_str, 5, "%s", s);
	
	rc = compare_strings(str, check_str, n, n_check);
	free(check_str);
	free(str);
	return rc;
}

int test_one_char()
{
	char *check_str = malloc(2), *str = malloc(2);
	int rc = ERR, n, n_check;
	
	const char c = 'a';
	n = my_snprintf(str, 2, "%c", c);
	n_check = snprintf(check_str, 2, "%c", c);
	
	rc = compare_strings(str, check_str, n, n_check);
	free(check_str);
	free(str);
	return rc;
}

int test_3_hex()
{
	char check_str[N] = { 0 }, str[N] = { 0 };
	int rc = ERR, n, n_check;
	
	n = snprintf(check_str, sizeof(check_str), "%x", 10);
	n_check = my_snprintf(str, sizeof(str), "%x", 10);
	rc = compare_strings(str, check_str, n, n_check);
	
	return rc;
}

int main()
{
	int err = OK;
	err += test_1_digit();
	err += test_1_string();
	err += test_1_char();
	err += test_2_minus_digit();
	err += test_2_string();
	err += test_2_chars();
	err += test_3_string();
	err += test_4_string();
	err += test_long_string();
	err += test_limits();
	err += test_one_char();
	err += test_3_hex();
	return OK;
}


