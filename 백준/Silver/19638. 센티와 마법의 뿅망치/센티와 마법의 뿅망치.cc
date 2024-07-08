#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>

int main() {
  
  std::vector<int> infos;
  std::priority_queue<int> bigs;
  std::string tmp;
  std::getline(std::cin, tmp);
  int big = 0;
  int cm = 0;
  int bbong = 0;
  int bbongCnt = 0;
  int result = 0;

  // std::cout << "tmp : " << tmp << std::endl;

  std::istringstream iss(tmp);

  int number;
  while(iss >> number) {
    infos.push_back(number);
  }

  big = infos[0];
  cm = infos[1];
  bbong = infos[2];

  // for(auto a: infos){
  //   std::cout << a << std::endl;
  // }

  for(int i = 0; i < big; i++){
    std::cin >> number;
    bigs.push(number);
  }

  while(!bigs.empty() && bbong > 0) {
    if (bigs.top() == 1) break;

    if (bigs.top() >= cm) {
      // std::cout << "check : " <<  bigs.top() << std::endl;

      result = bigs.top()/2;
      bigs.pop();
      bigs.push(result);
      bbong -= 1;
      bbongCnt += 1;
      
    } else {
      break;
    }
    // std::cout << "bbong : " << bbong << std::endl;
  }

  if (bigs.size() == 0 || bigs.top() < cm) {
    std::cout << "YES" << std::endl;
    std::cout << bbongCnt << std::endl;
  } else {
    std::cout << "NO" << std::endl;
    std::cout << bigs.top() << std::endl;
  }

}