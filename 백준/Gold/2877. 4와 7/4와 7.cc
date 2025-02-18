#include <iostream>


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int k, s = 1, e = 1;
  std::cin >> k;

  while(true) {
    if (s * 2 < k) {
      s *= 2; 
      k -= s;
      e += 1;
    }
    else {
      k -= 1;
      break;
    }
  }
  // std::cout << "e : " << e << "   k : " << k << std::endl;

  for(int i = e-1; i >= 0; i--) {
    int bit = (k >> i) & 1;
    // printf("%d", bit);
    if (bit == 0) {
      printf("4");
    } else {
      printf("7");
    }
  }
}