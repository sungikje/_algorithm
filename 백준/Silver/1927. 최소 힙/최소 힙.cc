
#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    
    if (pq.empty()) {
      if (tmp == 0) std::cout << "0\n";
      else pq.push(tmp);
    } else {  
      if (tmp == 0) {
        std::cout << pq.top() << std::endl;
        pq.pop();
      } else pq.push(tmp);
    }
  }
}