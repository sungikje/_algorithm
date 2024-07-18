#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

/*
sort 시간 복잡도 nlogn
  1초 = 100000000(1억) 근사치 n = 약 15000000(1500만)
*/
using namespace std;

struct Compare {
  bool operator()(int a, int b) {
    return a > b;
  }
};

bool sortByFirst(const pair<int, int> a, const pair<int, int> b){
  return a.first < b.first;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  priority_queue<int, vector<int>, Compare> pq;
  vector<pair<int, int> > vec;
  
  int n;
  int start;
  int end;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> start >> end;
    vec.push_back(make_pair(start, end));
  }
  sort(vec.begin(), vec.end(), sortByFirst);
  pq.push(vec[0].second);

  for(int i = 1; i < n; i++){
    if (vec[i].first >= pq.top()) {
      pq.pop();
    }
    pq.push(vec[i].second);
    pq.top();
  }
  cout << pq.size();
}