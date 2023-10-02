#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef void(*p)(void);
void *easter(int size, p chicken, p egg, p rabbit);
void print_chicken(void);
void print_egg(void);
void print_rabbit(void);

#endif // FUNCTIONS_H_INCLUDED
