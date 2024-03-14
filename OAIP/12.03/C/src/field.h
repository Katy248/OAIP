#include "includes.h"

#define FIELD_SIZE 9

typedef struct
{
    // char name[64];
    uint **cells;
} field;

field *new_field();
bool is_full(field *);

void print_field(field *);
