#include <iostream>
#include <vector>


using namespace std;

void run(vector<int> path, int k, int n, int current, vector<vector<int>> *result) {
  if (current == n) {
    result->push_back(path);
    return;
  }
  for (int i = 1; i <= k; i++) {
    if (current + i <= n) {
      // current += i;
      path.push_back(i);
      run(path, k, n, current + i, result);
      path.pop_back();
    }
  }
}

int main()
{
  int k, n;
  cin >> k >> n;

  vector<vector<int>> result = {};
  vector<int> path = {};

  run({}, k, n, 0, &result);
  
  for (auto i : result) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}
