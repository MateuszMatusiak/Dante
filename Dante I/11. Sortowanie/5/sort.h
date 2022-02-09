#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

enum direction {ASCENDING=1, DESCENDING};
int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction dir);
int bubble_sort_asc(int tab[], int size);
int bubble_sort_desc(int tab[], int size);
int bubble_sort(int tab[], int size, enum direction dir);
int insertion_sort_asc(int tab[], int size);
int insertion_sort_desc(int tab[], int size);
int insertion_sort(int tab[], int size, enum direction dir);

#endif // SORT_H_INCLUDED
