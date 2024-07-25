#include <vector>
#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

bool dfs(int start, int end, vector<vector<int> > nodes) {
  stack<int> stack;
  vector<int> visited(nodes.size(), false);

  stack.push(start);

  while(!stack.empty()) {
    int node = stack.top();
    stack.pop();
    visited[node] = true;
    if (node == end) return true;
    for(int i = 0; i < nodes[node].size(); i++) {
      if (!visited[nodes[node][i]]) {
        stack.push(nodes[node][i]);
      }
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n;
  cin >> m;
  vector<vector<int> > nodes(n+1);
  vector<int> load(m+1);

  cin.ignore();
  for(int i = 0; i < n; i++) {
    string tmp;
    getline(cin, tmp);
    
    stringstream ss(tmp);
    int num;
    int k = 1;
    while (ss >> num) {
      if (i + 1 != k && num == 1) {
        nodes[i+1].push_back(k);
        nodes[k].push_back(i+1);
      } 
      k += 1;
    }
    ss.ignore();
  }

  for(int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    load[i+1] = tmp;
  }

  for(int i = 1; i < load.size() - 1; i++) {
    if (!dfs(load[i], load[i+1], nodes)){
      // cout << "start : " << load[i] << "  end : " << load[i+1] << endl;
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
}

/*
인접 행렬 리스트 받고 순서대로 이동이 가능한지 여부 판단

cin은 공백을 기준으로 입력을 받음
때문에 cin 후 getline 사용 시 getline이 cin의 공백을 읽는 문제 발생
이 때 남아 있는 줄바꿈 무시하는 ignore() 필요
*/