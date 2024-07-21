
#include <iostream>
#include <vector>
#include <stack>

using namespace std;



void dfs(int node, vector<vector<int> > graph, vector<bool>& visited) {
  // visited[node] = true;
  // for(int i = 0; i < graph[node].size(); i++) {
  //   if (!visited[graph[node][i]]) {
  //     dfs(graph[node][i], graph, visited);
  //   }
  // }
  
  stack<int> stk;
  stk.push(node);

  while(!stk.empty()) {
    int tmpNode = stk.top();
    stk.pop();
    visited[tmpNode] = true;
    for(int i = 0; i < graph[tmpNode].size(); i++) {
      if (!visited[graph[tmpNode][i]]) stk.push(graph[tmpNode][i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  bool flag = false;
  

  cin >> n;
  vector<vector<int> > graph(n+1);
  vector<bool> visited(n+1, false);

  for(int i = 0; i < n-2; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1, graph, visited);

  for(int j = 1; j <= n; j++) {
    if (visited[j]) {
      cout << j << " "; 
      break;
    }
  } 
  for(int j = 1; j <= n; j++) {
    if (!visited[j]) {
      cout << j << " "; 
      break;
    }
  } 

  // cout << endl;
  // cout << endl;
  // for(bool i : visited) {
  //   cout << i << " ";
  // }
}

/*
인접 리스트 저장

dfs 이용해서 탐색

for문 처음 index부터 dfs 탐색 - visited false인 경우
  false인 경우 하나라도 뜨면 true인 node 하나랑 false인 node 하나 출력

dfs - 재귀 이용했을 땐 메모리 초과

*/