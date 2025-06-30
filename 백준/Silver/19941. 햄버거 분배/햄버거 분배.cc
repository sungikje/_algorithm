#include <iostream>
#include <array>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(0);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::array<char, 20000> arr;
    arr.fill(0);
    int result = 0;

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        if (arr[i] == 'P') {
            int start = i - k >=0 ? i-k : 0;
            int end = i + k >= n ? n-1 : i + k;
            bool eat = false;

            for(int j = start; j < i; j++) {
                if (arr[j] == 'H') {
                    arr[j] = -1;
                    arr[i] = -1;
                    eat = true;
                    result++;
                    break;
                }
            }
            
            if(!eat) {
                for(int j = i+1; j <= end; j++){
                    if (arr[j] == 'H') {
                        arr[j] = -1;
                        arr[i] = -1;
                        result++;
                        break;
                    }
                }   
            }
        }
    }

    std::cout << result;
}