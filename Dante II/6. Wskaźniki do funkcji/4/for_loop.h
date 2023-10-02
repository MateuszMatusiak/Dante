#ifndef FOR_LOOP_H_INCLUDED
#define FOR_LOOP_H_INCLUDED

typedef void(*p)(double);
void for_loop(double beg, double end, double a, p function);
void print_value(double a);
void print_accumulated(double a);
void print_square(double a);
void print_abs(double a);

#endif // FOR_LOOP_H_INCLUDED
