#ifndef COMPARATORS_C_INCLUDED
#define COMPARATORS_C_INCLUDED

typedef int (*p)(int, int);
int sort_int(int *array, int size, p function);
int comp_int(int a, int b);
int comp_int_abs(int a, int b);
int comp_int_length(int a, int b);
int comp_int_digits_sum(int a, int b);

#endif // COMPARATORS_C_INCLUDED
