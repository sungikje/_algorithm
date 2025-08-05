#include <iostream>
#include <array>
#include <unordered_set>

void comb(int start_idx, std::array<int, 6>& arr, bool* visited, int max, int cnt, int* min) {
    if (max == cnt) {
        long long sum = 0;
        int first_idx;
        int across_idx;
        std::unordered_set<int> across;
        for(int i = 0; i < arr.size(); i++) {
            if (visited[i]) {
                if (across.find(5-i) != across.end() || across.find(i) != across.end()) return;
                across.insert(5-i);
            }
        }

        bool check_across = false;
        for(int i = 0; i < arr.size(); i++) {
            if (visited[i]) sum += arr[i];
        }
        if (!check_across && sum < *min) *min = sum;
        return;
    }

    for(int i = start_idx+1; i < arr.size(); i++) {
        visited[i] = true;
        comb(i, arr, visited, max, cnt+1, min);
        visited[i] = false;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::array<int, 6> arr;
    bool visited[6] = {};
    int min = 50;
    int max = 0;
    std::cin >> n;
    for (int i = 0; i < 6; i++) {
        std::cin >> arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    
    long long sum = 0;
    if (n == 1) {
        for(int i = 0; i < arr.size(); i++) {
            if (arr[i] != max) sum += arr[i];
        }
        std::cout << sum;
        return 0;
    }

    int two_min = 100;
    for(int i = 0; i < arr.size(); i++) {
        visited[i] = true;
        comb(i, arr, visited, 2, 1, &two_min);
        visited[i] = false;
    }

    int three_min = 1000;
    for(int i = 0; i < arr.size(); i++) {
        visited[i] = true;
        comb(i, arr, visited, 3, 1, &three_min);
        visited[i] = false;
    }

    long long except_top = 0;
    except_top += 4 * two_min;
    int k = (n-2) * 4;
    except_top += k * min;

    sum = except_top * (n-1);
    sum += 4 * three_min;
    sum += k * two_min;
    sum += ((long long)(n-2) * (n-2)) * min;

    std::cout << sum;
}

/*
주사위 1, 2, 3 각 면의 최소합 조합을 고려해야한다는 접근은 좋았는데 조합을 고려할 때 3면의 경우 모든 요소의 면들이 마주볼 수 없다는 사실을 고려하지 않음.
0~5 index를 기준으로 첫번째 면을 기준으로만 마주보지 않는 것을 고려해서 실패했었다.
*/