#include <libintl.h>
#include <locale.h>
#include <signal.h>

#include "game.h"

#define APP_NAME "num-game"
void on_kill();

int main(int argc, char **argv)
{
  textdomain(APP_NAME);
  setlocale(LC_ALL, "");

  generate_number();

  signal(SIGINT, on_kill);
  signal(SIGABRT, on_kill);
  signal(SIGTERM, on_kill);
  signal(SIGTSTP, on_kill);

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

void on_kill()
{
  printf(gettext("Your number was: %d"), get_number());
  printf("\n");
  exit(-1);
}
