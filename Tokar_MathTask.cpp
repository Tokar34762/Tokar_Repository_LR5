#include "Tokar_MathTask.h"

using namespace std;

int main() {
  int N = EnterInteger("Enter the number of elements in the array: ");
  vector<int> arr = EnterArray(N);
  int sum = 0;
  double average = 0.0;
  CalculateSumAndAverage(arr, sum, average);
  cout << "The sum of the elements of the array: " << sum << endl;
  cout << "The arithmetic mean of the elements of the array: " << average
       << endl;
  return 0;
}
