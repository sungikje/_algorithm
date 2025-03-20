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

// 문제 주요 포인트는 현재 스택의 최상단 값이 순열로 만들고자 하는 값보다 큰 경우 stack에서 pop하게 되며 순열 생성이 불가한 상황을 조성한다.