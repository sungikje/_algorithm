#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

/*
priority queue와 sort에서 return 유의
*/

struct Compare {
  bool operator()(int a, int b) {
    return a > b; // b를 a보다 우선 순위로, 즉 작은 것부터 오름차순으로 정렬
  }
};

bool sortBySmall(std::pair<int, int> a, std::pair<int, int> b) {
  return a.first < b.first;   // first가 작은 것부터 오름차순으로 정렬
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

  pq.push(vec[0].second);
  for(int i = 1; i < vec.size(); i++) {
    if (vec[i].first >= pq.top()) {
      pq.pop();
    }
    pq.push(vec[i].second);
  }
  std::cout << pq.size();
}