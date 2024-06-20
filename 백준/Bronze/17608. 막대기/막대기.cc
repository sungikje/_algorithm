#include <iostream>
#include <vector>

int main() {
  int n;
  int var;
  int high;
  int result = 1;

  std::cin >> n;
  std::vector<int> vec;

  for(int i = 0; i < n; i++){
    std::cin >> var;
    if (i == n-1) high = var;
    vec.push_back(var);
  }

  // for(int i: vec) {
  //   std::cout << i << ' ';
  // }
  // std::cout << "high : " << high << std::endl;

  for(int i = n-2; i >= 0; i--){
    if (vec[i] > high) {
      
      result += 1;
      high = vec[i];
      // std::cout << "change high : " << high << std::endl;
    }
  }
  std::cout << result << std::endl;
}