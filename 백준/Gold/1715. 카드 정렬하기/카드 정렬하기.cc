#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare {
  int operator() (int a, int b) {
    return a > b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  priority_queue<int, vector<int>, compare> pq;
  int n;
  int sum = 0;

  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    pq.push(tmp);
  }

  if (pq.size() == 1) {
    cout << 0;
    return 0;
  }

  while(pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    

    pq.push(a + b);
    sum += (a + b);
    // cout << "a : " << a << "  b : " << b << endl;
    // cout << "sum : " << sum << endl;
  }
  // cout << endl;
  cout << sum << endl;
}
/*
while, n을 2씩 나누면서 증가
  for, 정렬된 벡터 앞 뒤 연속된 값들 덧셈 *홀수 경우 유의

n을 2씩 나눈 경우 O(logn), for문은 벡터 길이(약 n) = O(nlogn)으로 이론적으로 n이 60만이 되지 않기 때문에 가능 
*/