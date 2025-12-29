#include "process.h" 
#include <cstring>
#include <thread>
#include <chrono>

constexpr std::size_t size = 101;

constexpr char STYLE = '=';

void FlushProcess(double total, double curr) {
  if (curr > total) {
    curr = total;
  }
  double rate = curr / total * 100; //1024.0 , 512.0 -> 0.5 -> 50.0
  
  int cnt = static_cast<int>(rate);

  char processbuff[size];
  memset(processbuff, '\0', sizeof(processbuff));
  for (int i = 0; i < cnt; ++i) {
    processbuff[i] = STYLE;
  }
  
  static const char* label = "|/-\\";
  static int len = strlen(label);
  static int index = 0;


  //刷新
  printf("[%-100s][%.2lf%%][%c]\r", processbuff, rate, label[(index++)%len]);
  fflush(stdout);
}


void Process() {
  const char* label = "|/-\\";
  char processbuff[size];
  memset(processbuff, '\0', sizeof(processbuff));

  int cnt = 0;
  int len = strlen(label);

  while (cnt <= 100) {
    printf("[%-100s][%d%%][%c]\r", processbuff, cnt, label[cnt%len]); 
    processbuff[cnt++] = STYLE;
    fflush(stdout);
    std::this_thread::sleep_for(std::chrono::microseconds(100000));
  }
  std::cout << std::endl;
}
