#ifndef INC_813_FUNCTIONS_H
#define INC_813_FUNCTIONS_H

#define COUNT_BITS(value, px, py)     \
do{                                 \
*(px)=0;                              \
*(py)=0;                          \
unsigned long long v=(value);\
for(int i=(int)(sizeof(value)*8)-1;i>=0;--i)          \
{                                     \
    if(v&1ULL<<i)                            \
    {                     \
    (*(px))+=1;                             \
    }                          \
    else                          \
    {                                     \
    (*(py))+=1;                 \
    }                                     \
}                         \
} while(0);                \



#define DISPLAY_BITS(value)         \
do{                                 \
for(int i=(int)(sizeof(value)*8)-1;i>=0;--i)       \
{                           \
if((value)&1ULL<<i)                         \
printf("1");                    \
else                                \
printf("0"); \
}                                   \
} while(0);       \
\


#define REVERSE_BITS(pv)           \
do{           \
unsigned long long xd=0;            \
int k=(int)(sizeof(*(pv))*8)-1;         \
for(int i=0;i<((int)(sizeof(*(pv))*8));++i)         \
{           \
if((*(pv))&(1ULL<<i))           \
{           \
xd|=(1ULL<<k);          \
}           \
k--;            \
}           \
*pv=xd;         \
} while(0);          \


#define wetam(typ, p)               \
typ x;                              \
printf("Daj: ");\
t=scanf(p,&x);                \
if(t!=1)                            \
{                                   \
printf("Incorrect input");      \
return 1;                       \
}                                   \
int px=0;                                    \
int py=0;                           \
COUNT_BITS(x,&px,&py)               \
printf("%d\n%d\n",px,py);           \
DISPLAY_BITS(x)                     \
printf("\n");                       \
REVERSE_BITS(&x)                    \
DISPLAY_BITS(x)\


#endif //INC_813_FUNCTIONS_H









