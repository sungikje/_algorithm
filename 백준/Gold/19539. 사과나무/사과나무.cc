#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    int sum = 0;
    int min_cnt = 0;
    int max_cnt = 0;
    std::vector<int> vec;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        sum += t;
        if (t == 1) min_cnt++;
        else if (t != 0) vec.push_back(t);
    }
    
    if (sum % 3 != 0) {
        std::cout << "NO";
        return 0;
    }

    max_cnt = sum / 3;
    int two_max_cnt = 0;
    for(auto& v : vec) two_max_cnt += v / 2;

    if (two_max_cnt < min_cnt) {
        std::cout << "NO";
        return 0;
    }

    for(int i = min_cnt; i <= two_max_cnt; i++) {
        if (1*i + 2*i == sum) {
            std::cout << "YES";
            return 0;
        }
    }
    std::cout << "NO";
}

/*
핵심 로직을 코드로 구현하는 것은 간단하지만 핵심 로직 파악이 쉽지 않았다.

1. sum % 3 != 0 이면 NO
    1-1. sum / 3이 최대한의 물 뿌리는 횟수가 된다.
2. 1로 밖에 해결이 안되는 요소 체크 -> 최소한의 물 뿌리는 횟수가 된다.
3. 입력 받는 수 중 0과 1이 아닌 경우들을 /2 연산을 통해 최대로 2를 사용하는 횟수를 구한다.
    3-1. 여기서 해당 과정을 거치는 이유는 만약 단순히 (최소한의 물 뿌림~최대한의 물 뿌림)으로 가는 경우 실제 1, 2로 구성되는 각 조합들을 고려하지 않게 된다.
    3-2. 2는 1로 나눌 수 있기 때문에 최대한의 물 뿌리는 횟수보다 2를 사용하는 횟수가 더 커도 되고 어차피 줄이면서 pair를 맞출거다.
4. 최소한보다 만약 2의 최대 횟수가 작다면 NO
5. 최소한의 물 뿌리는 횟수부터 2의 최대 사용 횟수까지 반복문 돌면서 pair를 맞춘다.
*/