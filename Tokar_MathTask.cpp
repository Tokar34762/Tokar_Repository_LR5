#include "Tokar_MathTask.h"

using namespace std;

int main() {
  int NumberA = 0, NumberB = 0;
  // Input variable A
  EnterDigit(NumberA, "Input height A");
  // Input variable B
  EnterDigit(NumberB, "Input height B");
  // Calculate the area of the rectangle
  int RectangleArea = CalcRectangleArea(NumberA, NumberB);
  // Output the area
  cout << "Area of Rectangle is " << RectangleArea << endl;
  // Process the array
  ProcessArray();
  return 0;
}
