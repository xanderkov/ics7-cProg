#ifndef _KEYS_

#define _KEYS_

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
ARR_DLL int ARR_DECL mysort(void *base, size_t n, size_t size, int (*compare)(const void*, const void*));
ARR_DLL int ARR_DECL compare_ints(const void *a, const void *b);

#endif