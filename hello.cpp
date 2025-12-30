#include <iostream>

int flag = 1;//故意错误

int Sum(int s, int e) {
  int result = 0;
  for (int i = s; i <= e; ++i) {
    result += i;
  }
  return result *  flag;
}


int main() {
  int start = 1;
  int end = 10;

  std::cout << "I will begin\n";
  int n = Sum(start, end);

  std::cout << "running done, result is:" << start << "~" << end << "=" << n << "\n";

  return 0;
}
