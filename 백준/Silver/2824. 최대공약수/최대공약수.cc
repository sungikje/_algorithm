#include <iostream>
#include <unordered_map>

using namespace std;

void findPrimeSet(long long n, std::unordered_map<long long, long long> *map) {
  while(n % 2 == 0) {
    (*map)[2]++;
    n /= 2;
  }

  for(int i = 3; i * i <= n; i+=2) {
    while(n % i == 0) {
      (*map)[i]++;
      n /= i;
    }
  }
  if (n > 1) (*map)[n]++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  bool flag = false;
  long long n, m, t, res = 1;
  std::unordered_map<long long, long long> n_map, m_map;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> t;
    findPrimeSet(t, &n_map);
  }

  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> t;
    findPrimeSet(t, &m_map);
  }

  for(auto i = n_map.begin(); i != n_map.end(); i++) {
    if (m_map.find(i->first) != m_map.end()) {
      int tmp_n = i->second;
      int tmp_m = m_map[i->first];
      int small = tmp_n > tmp_m ? tmp_m : tmp_n;
      while(small) {
        res *= i->first;
        if (res >= 1000000000) {
          res %= 1000000000;
          flag = true;
        }
        small -= 1;
      }
    }
  }

  if (flag) {
    cout.width(9);
    cout.fill('0');
  }
  std::cout << res;
}