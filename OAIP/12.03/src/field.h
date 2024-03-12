#include "includes.h"

#define FIELD_SIZE 9

typedef struct
{
    char *name;
    uint **cells;
} field;

field *new_field();
bool is_full(field *);
