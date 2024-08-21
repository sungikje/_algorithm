#include <iostream>
#include <queue>

using namespace std;


struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  int sum = 0;
  int min = 100;
  priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
  cin >> n;
  vector<int> vec(1001, 0);

  for(int i = 0; i < n; i++) {
    int d, w;
    cin >> d >> w;
    pq.push(make_pair(d, w));
  }

  while(!pq.empty()) {
    pair<int, int> tmp = pq.top();
    for(int i = tmp.first; i >= 1; i--) {
      if (vec[i] == 0) {
        vec[i] = tmp.second;
        break;
      } else {
        if (vec[i] < tmp.second) {
          vec[i] = tmp.second;
          break;
        }
      }
    }
    pq.pop();
  }
  for(int i : vec) sum += i;
  cout << sum << endl;
}

/*
하루에 한 과제를 끝낼 수 있음 
d, w 입력 받음

d : 과제 마감일
w : 과제 점수


과제 점수를 기준으로 내림차순 정렬
과제 마감일에 값이 할당 안되어 있는 경우는 과제 마감일 인덱스에 과제 점수 할당
*/

