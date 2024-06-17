
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define NUMBER1 1
#define NUMBER2 2
#define NUMBER3 3
#define IGUAL 15
#define RESULT 5
#define NUMBER0 11
#define NUMBER4 4
#define NUMBER5 5
#define NUMBER6 6
#define NUMBER7 7
#define NUMBER8 8
#define NUMBER9 9
#define SOMA 10
#define SUBTRACAO 12
#define DIVISAO 13
#define MULTIPLICACAO 14
#define CLEAR 16
#define BACKSPACE 17
#define DECIMAL 18

int number1 = 0;
int number2 = 0;
int number3 = 0;
int number4 = 0;
int number5 = 0;
int number6 = 0;
int number7 = 0;
int number8 = 0;
int number9 = 0;
double result = 0.0;
wchar_t number1Str[20];
wchar_t number2Str[20];
wchar_t number3Str[20];
wchar_t number4Str[20];
wchar_t number5Str[20];
wchar_t number6Str[20];
wchar_t number7Str[20];
wchar_t number8Str[20];
wchar_t number9Str[20];
wchar_t resultStr[200];
char currentOperator = '+'; // Initialize with '+'
bool isOperatorPressed = false;
bool isDecimalUsed = false;

LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
  switch (msg) {
  case WM_COMMAND:
    switch (LOWORD(wp)) {
    case NUMBER1:
      number1 = 1;
      _snwprintf_s(number1Str, sizeof(number1Str), _TRUNCATE, L"%d", number1);
      SetWindowTextW(hEdit, number1Str);
      break;
    case NUMBER2:
      // ... similar logic for other number buttons
    case NUMBER3:
      // ...
      // ...
    case SOMA:
      if (isOperatorPressed) {
        switch (currentOperator) {
          case SOMA:
            result += number1;
            break;
          case SUBTRACAO:
            result -= number1;
            break;
          case MULTIPLICACAO:
            result *= number1;
            break;
          case DIVISAO:
            if (number1 != 0) {
              result /= number1;
            } else {
              SetWindowTextW(hEdit, L"Erro: Divisão por zero!");
              return 0;
            }
            break;
        }
      } else {
        result = number1;
      }
      isOperatorPressed = true;
      number1 = 0;
      _snwprintf_s(resultStr, sizeof(resultStr), _TRUNCATE, L"%g", result);
      SetWindowTextW(hEdit, resultStr);
      break;
    // Implement cases for other buttons (subtraction, multiplication, division, clear, etc.)
    }
    break;
  // Handle other messages (like WM_CREATE, WM_DESTROY)
  }
  return DefWindowProc(hwnd, msg, wp, lp);
}