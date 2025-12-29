#include <iostream>
#include <functional>


int main(){
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
  	std::cout << i + 1 << " ";
  }
  std::cout << std::endl;

  return 0;
}
