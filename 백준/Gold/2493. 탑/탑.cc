#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>
#include <limits>
#include <utility>

/*
현재 Index 기준 더 큰 건물이 있는 경우 그 전 상황은 알빠가 아니다
ref : https://chan9.tistory.com/24
*/

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  
  std::string input;
  std::vector<int> tmp;
  std::stack<std::pair<int, int> > stack;
  int n;
  int h;

  std::cin >> n;
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  // std::getline(std::cin, input);
  // std::istringstream iss(input);
  // while (iss >> parse) tmp.push_back(parse);

  for(int i = 1; i <= n; i++) {
    std::cin >> h;
    // std::cout << "h : " << h << std::endl;
    if (i == 1) {
      stack.push(std::make_pair(h, i));
      std::cout << 0 << " ";
    } else {
      if (stack.empty()) {
        std::cout << 0 << " ";
        stack.push(std::make_pair(h, i));
      } else {
        while(1) {
          if (stack.top().first >= h) {
            std::cout << stack.top().second << " ";
            stack.push(std::make_pair(h, i));
            break;
          } else {
            stack.pop();
            if (stack.empty()) {
              std::cout << 0 << " ";
              stack.push(std::make_pair(h, i)); 
              break;
            }
          }
        }
      }
    }
  }
}