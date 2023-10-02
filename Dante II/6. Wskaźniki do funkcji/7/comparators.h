#ifndef COMPARATORS_H_INCLUDED
#define COMPARATORS_H_INCLUDED

typedef int(*p)(const int*, const int*, int);
int sort_rows(int **tab, int column, int row, p function);
int comp_min(const int *ptr1, const int *ptr2, int width);
int comp_max(const int *ptr1, const int *ptr2, int width);
int comp_sum(const int *ptr1, const int *ptr2, int width);

#endif // COMPARATORS_H_INCLUDED
