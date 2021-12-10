#include "file_operations.h"
#include "io.h"



bool compare_structs(films *f1, films *f2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(f1[i].title, f2[i].title) || strcmp(f1[i].name, f2[i].name) || strcmp(f1[i].year, f2[i].year))
			return false;
	}
	return true;
}

int test_1_serch()
{
	FILE *f = NULL;
	int rc = NOT_OK, n = 0;
	films *film = NULL, *c_film = NULL;
	f = fopen("func_tests/pos_1_in\0", "r");
	if (f)
	{
		read_file_from_struct(f, &film, &n, "title\0");
		f = fopen("func_tests/pos_1_in\0", "r");
		read_file_from_struct(f, &c_film, &n, "title\0");
		search_film(film, n, "title\0", "Zombie\0");
		if (compare_structs(film, c_film, 1))
			rc = OK;
		free_struct(&film, n);
		free_struct(&c_film, n);
	}
	return rc;
}

int test_2_serch()
{
	FILE *f = NULL;
	int rc = NOT_OK, n = 0, check = OK;
	films *film = NULL;
	f = fopen("func_tests/pos_1_in\0", "r");
	if (f)
	{
		read_file_from_struct(f, &film, &n, "title\0");
		check = search_film(film, n, "year\0", "-1\0");
		if (check == NOT_YEAR)
			rc = OK;
		free_struct(&film, n);
	}
	return rc;
}

int test_1_is_number()
{
	char s[STR_LEN] = "123";
	int rc = NOT_OK;
	if (is_number(s) == TRUE)
		rc = OK;
	return rc;
}

int test_2_is_number()
{
	char s[STR_LEN] = "1a3";
	int rc = NOT_OK;
	if (is_number(s) == FALSE)
		rc = OK;
	return rc;
}

int test_1_is_space()
{
	char s[STR_LEN] = "  ";
	int rc = NOT_OK;
	if (is_space(s) == SPACE_NAME)
		rc = OK;
	return rc;	
}

int test_2_is_space()
{
	char s[STR_LEN] = "  	  	";
	int rc = NOT_OK;
	if (is_space(s) == SPACE_NAME)
		rc = OK;
	return rc;	
}

int test_3_is_space()
{
	char s[STR_LEN] = " a ";
	int rc = NOT_OK;
	if (is_space(s) == OK)
		rc = OK;
	return rc;	
}



int main()
{
	int err = OK;
	err += test_1_serch();
	err += test_2_serch();
	err += test_1_is_number();
	err += test_2_is_number();
	err += test_1_is_space();
	err += test_2_is_space();
	err += test_3_is_space();
	if (err != 0)
		printf("%d", err);
	return 0;
}
