#ifndef _SURNAME_MATHTASK_H_
#define _SURNAME_MATHTASK_H_
#include <iostream>
#include <numeric> // for std::accumulate
#include <string>
#include <vector>

using namespace std;
// Function to validate user input
bool UserInput(const string &input) {
  // If the string is empty, the input is invalid
  if (input.empty())
    return false;
  // Try to convert the input to an integer
  try {
    stoi(input);
  } catch (...) { // If an error occurs, the input is invalid
    return false;
  }
  return true;
}

void EnterDigit(int &varLink, const string &label) {
  string raw_input;
  cout << label << " = ";
  getline(cin, raw_input);
  while (!UserInput(raw_input)) {
    cout << "Invalid input. " << label << " = ";
    getline(cin, raw_input);
  }
  varLink = stoi(raw_input);
}
// Method to calculate the area of a rectangle
int CalcRectangleArea(int NumberA, int NumberB) { return NumberA * NumberB; }

void ProcessArray() {
  int N;
  cout << "Enter the size of the array (N): ";
  cin >> N;
  // Create a vector to hold the array elements
  vector<int> arr(N);
  cout << "Enter " << N << " integers:" << endl;
  for (int i = 0; i < N; ++i) {
    string input;
    cin >> input;
    while (!UserInput(input)) {
      cout << "Invalid input. Enter an integer: ";
      cin >> input;
    }
    arr[i] = stoi(input);
  }
  // Calculate the sum of the array elements
  int sum = accumulate(arr.begin(), arr.end(), 0);
  // Calculate the average
  double average = static_cast<double>(sum) / N;
  // Output the results
  cout << "Sum of array elements: " << sum << endl;
  cout << "Average of array elements: " << average << endl;
}
#endif