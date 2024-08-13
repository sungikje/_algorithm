#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> vec;
  std::vector<int> res(n+1, -1);
  std::unordered_map<int, int> map;
  std::stack<std::pair<int, int> > stack;
  
  for(int i = 0 ; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    vec.push_back(tmp);
    map[tmp]++;
  }

  for(int i = 0; i < vec.size(); i++) {
    while(!stack.empty() && map[stack.top().second] < map[vec[i]]) {
      res[stack.top().first] = vec[i];
      stack.pop();
    } 
    stack.push(std::make_pair(i, vec[i]));
  }

  for(int i = 0; i < n; i++) {
    std::cout << res[i] << " ";
  }
}
/*
우큰수 알고리즘 이용해 개선
  순차 비교 할 때, 즉 이 전에 처리한 정보를 효과적으로 재사용하기 위해서는 스텍 이용
  이중 반복문의 경우 시간 복잡도 매우 높기에 비효율적
  최대, 최소, 비교, 막대 그래프 등 histogram 문제들

또한 초기에 map을 이용했지만 시간 초과 발생 => unordered_map으로 개선
  map의 경우 레드-블랙 트리 구조로 구성, 때문에 트리를 순회해야되는 특징 존재 
    key가 삽입 될 때마다 자동으로 오름차순으로 정렬된다 
    삽입, 삭제, 검색 모두 O(logN)의 시간 복잡도 가짐
      
    트리 구조를 위해 추가적인 메모리 사용
  unordered_map의 경우 해시 테이블을 기반으로 구현됨
    삽입된 순서와 상관없이 내부 해시 테이블의 해시 값에 따라 저장 위치가 결정
    각 연산들은 평균적으로 O(1)의 시간 복잡도 가짐
*/