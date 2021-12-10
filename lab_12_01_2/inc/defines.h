#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 0
#define NULL_FILE -1
#define NULL_ARR -2
#define WRONG_ARG -3
#define NO 0
#define YES 1
#define NULL_LIB -4

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif
#define ARR_DECL __cdecl