#include "iostream"
#include "vector"
#include "stack"

bool dfs(int st_node, int end_node, int mid, std::vector<std::vector<std::pair<int, int> > > graph) {
  std::stack<int> stk;
  std::vector<bool> visited(graph.size(), false);

  stk.push(st_node);
  visited[st_node] = true;

  while(!stk.empty()) {
    int node = stk.top();
    stk.pop();
    if (node == end_node) return true;

    for(int i = 0; i < graph[node].size(); i++) {
      if (!visited[(graph[node][i]).first] && (graph[node][i]).second >= mid) {
        visited[(graph[node][i]).first] = true;
        stk.push((graph[node][i]).first);
      }
    }
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, m;
  int st_node, end_node;
  int res = 0;
  int max_edge = 0;

  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int> > > graph(n+1);
  std::vector<bool> visited(n+1);
  
  for(int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    graph[a].push_back(std::make_pair(b,c));
    graph[b].push_back(std::make_pair(a,c));
    if (max_edge < c) max_edge = c;
  }
  std::cin >> st_node >> end_node;


  int low = 1;
  int high = max_edge;
  
  while(low <= high) {
    int mid = (low + high) / 2;

    visited[st_node] = true;
    if (dfs(st_node, end_node, mid, graph)) {
      low = mid + 1;
      res = mid;
    } else high = mid - 1;
  }
  
  std::cout << res;
}

/*
입력
n, m
a, b, c : a, b는 섬, c는 섬 사이의 중량제한
d, e : 연결하는 도시

n : 최대 10000
m : 최대 100000

모든 다리 양방향

문제 포인트는 d <-> e 여러 이동 경로들 이동 경로마다 중량 가장 작은 도로의 값을 뽑고 이 중에 가장 큰 값이 정답
  dfs 이용 예정, dfs 원리 구체적 이해 필요

dfs 재귀로 구현한 경우에
  visited는 참조 변수로 사용해야 dfs process에서 수정, 공유된다
  만약 path를 모두 기록하고 싶을 때 종료 조건은 dfs 상단에 위치하고 visited를 false로 초기화할 때 pop_back()

메모리 초과
  => 특정 변수로 인한 문제는 아닐 것 같아서 백트래킹 dfs 재귀를 반복문 수정해보자 

최종 로직
  dfs로 모든 경로를 탐색하는 것은 비효율적
	:: dfs를 보다 효율적으로 사용하려면 dfs 이전에 탐색하고자 하는 부분들을 최대한 줄이는 것도 하나의 방법

  첫번째로 그래프의 최대 중량을 체크 

  1부터 최대 중량까지 이분 탐색을 이용해 도달할 수 있는지 여부 체크 
*/