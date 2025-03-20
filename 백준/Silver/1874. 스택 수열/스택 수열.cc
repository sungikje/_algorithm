#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  std::cin >> n;
  std::stack<int> stack;
  std::vector<char> vec;

  int idx = 1;
  for(int i = 0; i < n; i++) {
    int num;
    std::cin >> num;

    while(idx <= num) {
      stack.push(idx);
      vec.push_back('+');
      idx++;
    } 

    if (stack.top() == num) {
      stack.pop();
      vec.push_back('-');
    } else {
      std::cout << "NO";
      return 0;
    }
  }

  for(char a : vec) {
    std::cout << a << "\n";
  }
  return 0;
}