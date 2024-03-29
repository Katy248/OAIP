#include "main.h"

int main(int argc, char **argv)
{
    uint game_c = 1;
    if (argc >= 2)
    {
        game_c = (uint)strtol(argv[1], (char **)NULL, 10);
    }

    for (uint i = 0; i < game_c; i++)
    {
        play();
    }

    return 0;
}

void play()
{
    field *f = new_field();
    print_field(f);

    if (solve(f, 0, 0))
    {
        printf("%d", f->cells[0][0]);
        printf("%d", f->cells[0][1]);
        printf("%d", f->cells[0][2]);
    }
    else
        print_field(f);
    free(f);
}
