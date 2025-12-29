#include "process.h" 
#include <thread>
#include <chrono>
#include <random>


double total = 1024.0;
double speed = 1.0;

double SpeedFloat(double start, double range) { // [1.0, 3.0] -> [1.0, 4.0]
   int int_range = static_cast<int>(range);
   std::random_device rd;
   std::mt19937 gen(rd());

   std::uniform_int_distribution<int> distInt(1, 100);

   return start + distInt(gen) % int_range + (range - int_range);
}

inline void Download() {
  double curr = 0.0;
  while (true) {
    if (curr > total) {
      //std::cout << "curr > total" << std::endl;
      curr = total;  
      FlushProcess(total, curr); //更新进度, 按照下载进度更新
      break;
    }
    FlushProcess(total, curr); //更新进度, 按照下载进度更新
    curr += SpeedFloat(speed, 20.5);//模拟下载行为
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
  }
  std::cout << std::endl;
}


int main() {

  //Process();
  Download();

  return 0;
}
