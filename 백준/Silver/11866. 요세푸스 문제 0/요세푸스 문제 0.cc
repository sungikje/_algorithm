#include <iostream>
#include <vector>
#include <sstream>

int main() {
  
  std::string input;
  std::vector<int> numbers;
  std::vector<int> vec;
  int number;
  int k;
  int n;
  int cnt = 0;
  
  std::getline(std::cin, input);
  std::istringstream iss(input);

  while (iss >> number) {
    numbers.push_back(number);
  }
  
  n = numbers[0];
  k = numbers[1];

  for (int i = 0; i < n; i++) {
    vec.push_back(i+1);
  }
  
  // for(int i : vec) std::cout << " i : " << i;
  // std::cout << std::endl;
  // std::cout << "n : " << n << "   k : " << k << std::endl;
  std::cout << '<';

  while(vec.size() > 1) {
    
    cnt += k-1;
    if (cnt >= vec.size()) cnt %= vec.size();
    // std::cout << "cnt : " << cnt << std::endl;
    // std::cout << "vec : " << vec[cnt] << std::endl;
    std::cout << vec[cnt] << ", ";
    vec.erase(vec.begin() + cnt);
  }

  std::cout << vec[0] << ">" << std::endl;

}