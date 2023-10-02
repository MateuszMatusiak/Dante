#ifndef INC_815_FUNCTIONS_H
#define INC_815_FUNCTIONS_H

#define DEFINE_ARRAY(TYPE) \
struct array_##TYPE##_t    \
{                          \
int size;                  \
int capacity;              \
TYPE* data;\
};\

#define CREATE_ARRAY(TYPE) \
struct array_##TYPE##_t *create_array_##TYPE(int size) \
{                          \
if(size<=0)                \
    return NULL;\
struct array_##TYPE##_t *xd=(struct array_##TYPE##_t*)calloc(1,sizeof(struct array_##TYPE##_t)); \
if(xd==NULL)               \
{return NULL;                          \
}                          \
xd->size=0;\
xd->capacity=size;         \
xd->data=(TYPE*)calloc(size,sizeof(TYPE));             \
if(xd->data==NULL)               \
{                         \
free(xd);                  \
return NULL;\
}                          \
return xd;\
}\


#define FREE_ARRAY(TYPE) \
void free_array_##TYPE(struct array_##TYPE##_t *array) \
{                        \
if(array!=NULL)          \
{                        \
if(array->data!=NULL)    \
    free(array->data);       \
free(array);\
}\
}\

#define SAVE_ARRAY(TYPE) \
int save_array_##TYPE(const struct array_##TYPE##_t *array, const char *filename) \
{                        \
if(array==NULL||filename==NULL||array->data==NULL||array->capacity<=0||array->size<=0||array->size>array->capacity)                                                   \
{                        \
return 1;}\
FILE *f=fopen(filename,"wb");                                                     \
if(f==NULL)              \
{return 2;                        \
}                        \
fwrite(&(array->size),sizeof(int),1,f);                                           \
fwrite(array->data,sizeof(*array->data),array->size,f);                                          \
fclose(f);\
return 0;\
}\

#define LOAD_ARRAY(TYPE) \
int load_array_##TYPE(struct array_##TYPE##_t **array, const char *filename) \
{ if(array==NULL||filename==NULL)      \
{ return 1;                        \
}                        \
FILE *f=fopen(filename,"rb");                                                \
if(f==NULL)              \
{return 2;                        \
}                        \
int x=0;\
int t=fread(&x,sizeof(int),1,f);                                             \
if(t!=1)                 \
{ fclose(f);             \
return 3;\
}                        \
if(x<=0)                 \
{ fclose(f);             \
return 3;\
}                        \
struct array_##TYPE##_t *xd=create_array_##TYPE(x);                          \
if(xd==NULL)             \
{fclose(f);              \
return 4;\
}                        \
xd->size=x;           \
t=fread(xd->data,sizeof(*xd->data),x,f);                            \
if(t!=x)              \
{free_array_##TYPE(xd);  \
fclose(f);               \
return 3;\
}\
*array=xd;\
fclose(f);               \
return 0;\
}\


#define SORT_ARRAY(TYPE) \
int sort_array_##TYPE(struct array_##TYPE##_t *array) \
{                        \
if(array==NULL||array->data==NULL||array->capacity<=0||array->size<=0||array->size>array->capacity) \
return 1;\
for(int i=0;i<array->size-1;++i)                      \
{                        \
for(int k=0;k<array->size-1;++k)                          \
{                        \
if(*(array->data+k)>*(array->data+k+1))               \
{                        \
TYPE x=*(array->data+k); \
*(array->data+k)=*(array->data+k+1);                  \
*(array->data+k+1)=x;\
}\
}                         \
}                        \
return 0;\
}\

#endif //INC_815_FUNCTIONS_H
