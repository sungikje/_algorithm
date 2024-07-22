
#include <iostream>
#include <set>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  cout.tie(0);
  
  string word[1001];
  int r, c;

  cin >> r >> c;

  char arr[r][c];
  
  int ptr = 0;
  int cnt = 0;

  for(int i = 0; i < r; i++) {
    string str;
    cin >> str;
    for(int j = 0; j < str.length(); j++) arr[i][j] = str[j];
  }

  for(int i = 0; i < c; i++) {
    string str = "";
    for(int j = 1; j < r; j++) {
      str += arr[j][i];
    }
    word[i] = str;
  }

  while(1) {
    if (ptr == c) {
      cout << cnt;
      return 0;
    }

    set<string> _set;
    for(int i = 0; i < c; i++) {
      string tmp = word[i].substr(ptr, word[i].length());
      // cout << "str : " << tmp << endl;
      _set.insert(tmp);
    }

    if (_set.size() != c) {
      cout << cnt;
      return 0;
    } else {
      cnt++;
      ptr++;
    }
  }
}
/*
초기 코드 시간 초과 발생
예상 원인
  1. set => unordered_set으로 해도 시간 초과
  2. while - for - for
*/
