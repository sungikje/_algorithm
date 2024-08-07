
#include <iostream>
#include <vector>
#include <unordered_map>

void partArr(std::vector<int> vec, int t, std::vector<int>& part) {
  
  for(int i = 0; i < vec.size(); i++) {
    long sum = 0;
    for(int j = i; j < vec.size(); j++) {
      sum += vec[j];
      part.push_back(sum);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);

  int t, n, m;
  long cnt = 0;
  std::vector<int> vec_a;
  std::vector<int> vec_b;
  std::vector<int> part_a;
  std::vector<int> part_b;
  std::unordered_map<int, int> map_a;
  
  std::cin >> t;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    vec_a.push_back(tmp);
  }

  std::cin >> m;

  for(int i = 0; i < m; i++) {
    int tmp;
    std::cin >> tmp;
    vec_b.push_back(tmp);
  }
  
  std::vector<int> visited(n, false);

  // for(int i = 0; i < vec_a.size(); i++) std::cout << vec_a[i] << " ";
  // std::cout << std::endl;

  partArr(vec_a, t, part_a);
  partArr(vec_b, t, part_b);

  // std::cout << "comb a" << std::endl;
  // for(int a : part_a) {
  //   std::cout << a << " ";
  // }
  // std::cout << std::endl;
  // std::cout << "comb b" << std::endl;
  // for(int a : part_b) {
  //   std::cout << a << " ";
  // }
  // std::cout << std::endl;

  for(int i : part_a) map_a[i]++;

  // std::cout << "map-------------------------------" << std::endl;
  // for(const auto& pair : map_a) {
  //   std::cout << pair.first << "  " << pair.second << std::endl;
  // }

  for(int i : part_b) {
    if (map_a.find(t-i) != map_a.end()) {
      cnt+= map_a[t-i];
    }
  }

  std::cout << cnt;
  
}

/*
조합, dfs 이용 예정
  총 원소 2000개, T를 만족하는 원소의 갯수가 많아질수록 조합 기하급수적으로 늘어나는 문제
    2000!/((2000-k)!*k!) => k와 조합 갯수는 비례
  
  최적화 작업
    1. 백트래킹
      - 특정 값을 체크하는 백트래킹의 환경에서는 문제가 없다면 값의 정렬을 통해 최적화 할 수 있다
    2. Dp
    3. 해시맵
*/