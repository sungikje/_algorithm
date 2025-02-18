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

  for(int i = e-1; i >= 0; i--) {
    int bit = (k >> i) & 1;   // 대부분의 언어에서 정수형은 메모리에 2진수로 저장된다.
    if (bit == 0) {
      printf("4");
    } else {
      printf("7");
    }
  }
}