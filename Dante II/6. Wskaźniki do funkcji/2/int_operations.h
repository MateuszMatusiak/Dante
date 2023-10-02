#ifndef INT_OPERATIONS_H_INCLUDED
#define INT_OPERATIONS_H_INCLUDED

enum operations_t { op_add, op_sub, op_div, op_mul};
typedef int (*p)(int, int);
p get_function(enum operations_t x);
int add_int(int a, int b);
int sub_int(int a, int b);
int div_int(int a, int b);
int mul_int(int a, int b);


#endif // INT_OPERATIONS_H_INCLUDED
