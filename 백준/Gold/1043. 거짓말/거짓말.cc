#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std; 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  
  
  int n, m;
  int t;
  int t2;
  bool check = false;
  int cnt = 0;
  cin >> n >> m;

  vector<bool> visited(n+1);
  vector<set<int> > vec;
  queue<int> known;
  set<int> end_known;

  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> t2;
    known.push(t2);
  }

  // cout << endl;
  // vector<int> ttt;
  // while(!known.empty()) { 
  //   ttt.push_back(known.front());
  //   known.pop();
  // }
  // cout << "ttt" << endl;
  // for(int i : ttt) { cout << i << " "; }
  // cout << endl;
  

  for(int i = 0; i < m; i++) {
    cin >> t;
    set<int> _set;
    for(int j = 0; j < t; j++) {
      cin >> t2;
      _set.insert(t2);
    }
    vec.push_back(_set);
  }

  while(!known.empty()) {
    
    int q = known.front();
    known.pop();
    visited[q] = true;
    
    
    for(int i = 0; i < vec.size(); i++) {
      check = false;
      if (vec[i].find(q) != vec[i].end()) { check = true; }
      if (check) {
        for(set<int>::iterator it = vec[i].begin(); it != vec[i].end(); ++it) {
          if (!visited[*it]) known.push(*it);
        }
      }
    }
  }

  for(int i = 1; i < visited.size(); i++) {
    // cout << visited[i] << " ";
    if (visited[i]) { end_known.insert(i); }
  }
  // cout << endl;

  for(int i = 0; i < vec.size(); i++) {
    check = false;
    for(set<int>::iterator it = vec[i].begin(); it != vec[i].end(); ++it) {
      if (end_known.find(*it) != end_known.end()) {
        check = true;
        break;
      }
    }
    if (!check) cnt++;
  }

  cout << cnt;
  
}
/*
처음에 거짓말이라고 알고 있는 사람들(known)을 저장하고 파티를 순차적으로 known과 함께 파티 참여하는 사람
known으로 갱신하면서 진행
 => 파티는 순차적으로 진행되지 않기에 불가

known : queue 이용해 순차적으로 영향을 주는 경우 탐색 

known : queue
party : vector<set>
visited : vector -bool

처음 known에 인원 추가
파티 vector<set> 입력 받음

while q != empty
  q pop
  vector 순회하면서 set에 q 존재하는지 체크
  존재하면 해당 set 내용들 핸들링한 q 아닌 경우만 q 에 추가
  vector 순회 위해 i handeling 필요

visted 순회하면서 true인 경우 set 추가

vector<set> 순회하면서 visited 비교
*/