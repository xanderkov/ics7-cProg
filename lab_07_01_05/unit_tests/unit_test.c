#include "../inc/defines.h"
#include "../inc/io_file.h"
#include "../inc/sort_array.h"


bool is_array(const void *a, size_t na, const void *b, size_t nb, size_t size)
{
	const char *ac = a;
	const char *bc = b;
	
	if (na != nb)
		return true;
	const char *pj = bc;
	for (const char *pi = ac; pi < ac + na * size; pi += size)
	{
		if (*pi != *pj)
			return true;
		pj += size;
	}
	return false;
}

void test_mysort()
{
	int err_cnt = 0;
	{
		int a[] = { 1, 2, 3, 4, 5 };
		int b[] = { 1, 2, 3, 4, 5 };
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 5, 4, 3, 2, 1 };
		int b[] = { 1, 2, 3, 4, 5 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 4, 3, 5, 1, 2 };
		int b[] = { 1, 2, 3, 4, 5 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 5,1,1,2,1,2,3 };
		int b[] = { 1,1,1,2,2,3,5 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 5,4 };
		int b[] = { 4,5 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 1,2 };
		int b[] = { 1,2 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	{
		int a[] = { 5 };
		int b[] = { 5 };
				
		mysort(a, sizeof(a) / sizeof(a[0]), sizeof(int), compare_ints);
		if (is_array(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
	}
	if (err_cnt > 0)
		printf("%d", err_cnt);
}

void test_key()
{
	int err_cnt = 0;
	{
		int a[] = { 9, 8000, 2, 500, 3, 1 };
		int b[] = { 8000, 500, 3 };
		int *cb, *ce;
		
		key(a, a + sizeof(a) / sizeof(a[0]), &cb, &ce);
		if (is_array(cb, ce - cb, b, sizeof(b) / sizeof(b[0]), sizeof(int)))
		{
			err_cnt++;
		}
		free(cb);
	}
	if (err_cnt > 0)
		printf("%d", err_cnt);
}

int main()
{
	test_mysort();
	test_key();
	return 0;
}