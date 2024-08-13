#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> vec;
  std::vector<int> res(n+1, -1);
  std::unordered_map<int, int> map;
  std::stack<std::pair<int, int> > stack;
  
  for(int i = 0 ; i < n; i++) {
    int tmp;
    std::cin >> tmp;
    vec.push_back(tmp);
    map[tmp]++;
  }

  // for(auto& a : map) {
  //   cout << a.first << " " << a.second << endl;
  // }

  for(int i = 0; i < vec.size(); i++) {
    while(!stack.empty() && map[stack.top().second] < map[vec[i]]) {
      res[stack.top().first] = vec[i];
      stack.pop();
    } 
    stack.push(std::make_pair(i, vec[i]));
  }

  for(int i = 0; i < n; i++) {
    std::cout << res[i] << " ";
  }
}