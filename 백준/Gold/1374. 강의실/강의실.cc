#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

struct Compare {
  int operator()(int a, int b) {
    return a > b;
  }
};

int sortBySmall(std::pair<int, int> a, std::pair<int, int> b) {
  return a.first < b.first;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;
  int a, b, c;
  std::vector<std::pair<int, int> > vec;
  std::priority_queue<int, std::vector<int>, Compare> pq;

  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::cin >> a >> b >> c;
    vec.push_back(std::make_pair(b, c));
  }

  sort(vec.begin(), vec.end(), sortBySmall);

  // std::cout << std::endl;
  // for(std::pair<int, int> a : vec) {
  //   std::cout << a.first << " " << a.second << std::endl;
  // }

  pq.push(vec[0].second);
  for(int i = 1; i < vec.size(); i++) {
    // std::cout << "start : " << vec[i].first << " end : " << vec[i].second << std::endl;
    if (vec[i].first >= pq.top()) {
      // std::cout << "come in" << std::endl;
      pq.pop();
    }
    pq.push(vec[i].second);
    // std::cout << "top : " << pq.top() << std::endl;
  }
  std::cout << pq.size();
}