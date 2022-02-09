#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include "types_utils.h"

int quicksort_asc(int l, int r, int tab[], int tabSize);
int quicksort_desc(int l, int r, int tab[], int tabSize);
int quicksort(int tab[], int size, enum direction dir);

#endif // QUICKSORT_H_INCLUDED
