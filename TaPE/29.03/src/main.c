#include "game.h"

#define APP_NAME "num-game"

int main(int argc, char **argv)
{

  setlocale(LC_ALL, "");
  textdomain(APP_NAME);

  generate_number();

  /* cout << get_number() << "\n"; */
  bool is_win = false;

  while (!is_win)
  {
    uint input;
    printf(gettext("Enter number"));
    printf(":\n");
    scanf("%d", &input);

    uint digits = get_guessed_digits_count(input);
    uint positions = get_guessed_digits_positions_count(input);

    is_win = digits == 3 && positions == 3;
    printf(gettext("Your input"));
    printf(" -> ");
    printf("%d", input);
    printf(" ");
    printf(gettext("Guessed right"));
    printf(" ");
    printf("%d", digits);
    printf(". ");
    printf(gettext("On the right place"));
    printf(": ");
    printf("%d", positions);
    printf("\n");
  }

  printf("***");
  printf(gettext("YOU WON!"));
  printf("***");

  return 0;
}
