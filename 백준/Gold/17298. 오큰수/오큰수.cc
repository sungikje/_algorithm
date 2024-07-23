#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  int tmp;
  cin >> n;
  vector<int> vec(n);
  stack<int> stack;

  for(int i = 0; i < n; i++) {
    cin >> tmp;
    vec[i] = tmp;
  }

  // for(int i : vec) cout << i << " ";
  // cout << endl;

  for(int i = 0; i < n; i++) {
    if (stack.empty()) {
      stack.push(i);
    } else {
      while(true) {
        if (stack.empty()) {
          stack.push(i);
          break;
        }
        if (vec[i] > vec[stack.top()]) {
          vec[stack.top()] = vec[i];
          stack.pop();
        } else {
          stack.push(i);
          break;
        }
      }
    }
  }

  vec[vec.size()-1] = -1;
  while(!stack.empty()) { 
    vec[stack.top()] = -1;
    stack.pop();
  }

  for(int i : vec) cout << i << " ";

}
/*
너무 모든 index부터 value들을 다 저장해서 핸들링하려고 하는 것 같다
모든 값들을 저장하는 것이 능사는 아니다

문제에서 주어진 데이터의 Index들이 문제의 key가 되며 이를 유지해야 되는 경우 queue, stack
같은 순차적으로 처리가 가능한 자료구조 먼저 고려 필요
*/