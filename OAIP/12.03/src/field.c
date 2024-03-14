#include "field.h"

field *new_field()
{
    char name[64];
    // scanf("%s\n", &name);
    uint **cells = (uint **)malloc(sizeof(uint) * FIELD_SIZE);
    for (uint i = 0; i < FIELD_SIZE; i++)
    {
        cells[i] = (uint *)malloc(sizeof(uint) * FIELD_SIZE);
        for (uint j = 0; j < FIELD_SIZE; j++)
        {
            scanf("%d ", &cells[i][j]);
        }
    }

    field *result = (field *)malloc(sizeof(field));
    *result = (field){/* .name = name, */ .cells = (uint **)cells};

    return result;
}

/* bool is_full(field *f)
{
    for (uint i = 0; i < FIELD_SIZE; i++)
    {
        for (uint j = 0; j < FIELD_SIZE; j++)
        {
            if (f->cells[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
} */

void print_field(field *f)
{
    for (uint i = 0; i < FIELD_SIZE; i++)
    {
        for (uint j = 0; j < FIELD_SIZE; j++)
        {
            printf("%d ", f->cells[i][j]);
        }
        printf("\n");
    }
}
