#ifndef BIT_SET_H_INCLUDED
#define BIT_SET_H_INCLUDED

struct bit
{
    unsigned char a1:1;
    unsigned char a2:1;
    unsigned char a3:1;
    unsigned char a4:1;
    unsigned char a5:1;
    unsigned char a6:1;
    unsigned char a7:1;
    unsigned char a8:1;
};
union bit_set
{
    unsigned char x;
    struct bit b;
};

#endif // BIT_SET_H_INCLUDED
