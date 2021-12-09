#ifndef _KEYS_

#define _KEYS_

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int mysort(void *base, size_t n, size_t size, int (*compare)(const void*, const void*));
int compare_ints(const void *a, const void *b);

#endif