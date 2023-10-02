#ifndef COMPARATORS_H_INCLUDED
#define COMPARATORS_H_INCLUDED

struct point_t
{
	double x;
	double y;
};

typedef int(*p)(const void*, const void*);
int sort(void *tab, int size, int sizeofelement, p function);
int comp_int(const void *ptr1, const void *ptr2);
int comp_double(const void *ptr1, const void *ptr2);
int comp_point(const void *ptr1, const void *ptr2);

#endif // COMPARATORS_H_INCLUDED
