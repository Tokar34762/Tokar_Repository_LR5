#ifndef _SURNAME_MATHTASK_H_
#define _SURNAME_MATHTASK_H_

#include <iostream>
#include <numeric> // for std::accumulate
#include <string>
#include <vector>

using namespace std;
// 1. Функция контроля ввода целого числа (возвращает bool)
bool UserInput(const string &input) {
  if (input.empty())
    return false;
  try {
    stoi(input);
  } catch (...) {
    return false;
  }
  return true;
}

// 2. Функция ввода целого числа с обработкой ввода
int EnterInteger(const string &label) {
  string raw_input;
  cout << label << ": ";
  getline(cin, raw_input);
  while (!UserInput(raw_input)) {
    cout << "Incorrect input. " << label << ": ";
    getline(cin, raw_input);
  }
  return stoi(raw_input);
}
// 3. Функция для ввода массива из N целых чисел
vector<int> EnterArray(int N) {
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    arr[i] = EnterInteger("Enter array element [" + to_string(i) + "]");
  }
  return arr;
}

void CalculateSumAndAverage(const vector<int> &arr, int &sum, double &average) {
  sum = 0;
  average = 0.0; // Инициализируем среднее значение
  if (!arr.empty()) { // Проверяем, не пуст ли массив
    for (int val : arr) {
      sum += val; // Суммируем элементы
    }
    average = (double)sum / arr.size(); // Преобразуем sum в double при делении
  }
}

#endif
