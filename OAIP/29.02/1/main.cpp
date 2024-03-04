#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
  if (x < 0) {
    return pow(pow(x, 3), (1 / 5)); 
  } else {
    double sum = 0;
    for (int k = 1; k <= 3; k++) {
      sum += pow(x, k) / k;
    }

    return sum + x * x;
  }
}

int main()
{
  double array[10];
  array[0] = -2;

  for (int i = 1; i < 10; i++) {
    array[i] = array[i - 1] + 0.4;
  }
  for (int i = 0; i < 10; i++) {
    cout << "x = " << array[i] << " -> " << f(array[i]) << endl;
  }
  return 0;
}
