#include "CUTE/cute/cute.h"
#include "CUTE/cute/cute_runner.h"
#include "CUTE/cute/ide_listener.h"
// подключение модуля с тестируемыми методами
#include "Tokar_MathTask.h"

using namespace cute;

void testCalculateSumAndAverage() {
  // Тест 1
  vector<int> arr1 = {1, 2, 3, 4, 5};
  int expectedSum1 = 15;
  double expectedAvg1 = 3.0;
  int actualSum1 = 0;
  double actualAvg1 = 0.0;
  CalculateSumAndAverage(arr1, actualSum1, actualAvg1);
  ASSERT_EQUAL(expectedSum1, actualSum1);
  ASSERT_EQUAL(expectedAvg1, actualAvg1);
}

// тест, проверяющий отсев пустых значений
void testUserInput_Empty() {
  // исходные данные
  string str = "";
  // ожидаемое значение результата работы функции User Input
  bool expected = false;
  // получение значения с помощью тестируемого метода
  bool actual = UserInput(str);
  // сравнение ожидаемого результата с полученным
  ASSERT_EQUAL(expected, actual);
}
// тест, проверяющий отсев нецифровых символов
void testUserInput_Letter() {

  // исходные данные
  string str = "a";
  // ожидаемое значение результата работы функции UserInput
  bool expected = false;

  // получение значения с помощью тестируемого метода
  bool actual = UserInput(str);

  // сравнение ожидаемого результата с полученным
  ASSERT_EQUAL(expected, actual);
}
// тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
  // исходные данные
  string str = "5a";
  // ожидаемое значение результата работы функции UserInput
  bool expected = false;
  // получение значения с помощью тестируемого метода
  bool actual = UserInput(str);
  // сравнение ожидаемого результата с полученным
  ASSERT_EQUAL(expected, actual);
}

// тест, проверяющий отсев отрицательных значений
void testUserInput_NegativeValue() {
  // исходные данные
  string str = "-5";
  // ожидаемое значение результата работы функции User Input
  bool expected = false;
  // получение значения с помощью тестируемого метода
  bool actual = UserInput(str);
  // сравнение ожидаемого результата с полученным
  ASSERT_EQUAL(expected, actual);
}

int main() {
  /**/ // Создаем тестовый наборs
  suite s;
  // Добавляем тестовую функцию в набор
  s.push_back(CUTE(testCalculateSumAndAverage));
  s.push_back(CUTE(testUserInput_Empty));
  s.push_back(CUTE(testUserInput_Letter));
  s.push_back(CUTE(testUserInput_NegativeValue));
  s.push_back(CUTE(testUserInput_DigitLetterValue));

  // Создаем listener и runner
  ide_listener<> listener;
  makeRunner(listener)(s, "All Rectangle Tests");
  return 0;
}