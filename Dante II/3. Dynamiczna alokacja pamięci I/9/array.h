#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

struct array_t
{
    float *ptr;
    int size;
    int capacity;
};

int array_create_float(struct array_t *a, int N);
int array_push_back_float(struct array_t *a, float value);
void array_display_float(const struct array_t *a);
void array_destroy_float(struct array_t *a);
void array_destroy_struct_float(struct array_t **a);
int array_create_struct_float(struct array_t **a, int N);
int add_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c);
int subtract_vectors(const struct array_t *a, const struct array_t *b, struct array_t **c);
float dot_product(const struct array_t *a, const struct array_t *b);
float angle_between_vectors(const struct array_t *a, const struct array_t *b);
float length(const struct array_t *a);
int normalize_vector(const struct array_t *a, struct array_t **b);
#endif // ARRAY_H_INCLUDED
