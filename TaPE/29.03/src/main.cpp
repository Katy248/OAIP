#include "game.h"
#include "libintl.h"
#include <clocale>

#define APP_NAME "num-game"

int main(int argc, char **argv) {

  setlocale(LC_ALL, "");
  textdomain(APP_NAME);
  
  generate_number();
  
  /* cout << get_number() << "\n"; */
  bool is_win = false;

  while (!is_win) {
    uint input;
    cout << gettext("Enter number") << ":\n";
    cin >> input;
    uint digits = get_guessed_digits_count(input);
    uint positions = get_guessed_digits_positions_count(input);

    is_win = digits == 3 && positions == 3;
    cout << gettext("Your input") << " -> " << input <<" " << gettext("Guessed right") << " " << digits
         << ". "<< gettext("On the right place") << ": " << positions << "\n";
  }

  cout << "***"
       << gettext("YOU WON!")
       << "***";

  return 0;
}
