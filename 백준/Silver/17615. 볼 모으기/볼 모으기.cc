#include <iostream>
#include <vector>

int main () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<char> vec;
    std::vector<char> color;
    std::vector<int> color_cnt;
    char prev = 's';
    char t;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        std::cin >> t;

        if (prev == 's' || prev == t) {
            cnt++;
        } else {
            color.push_back(prev);
            color_cnt.push_back(cnt);
            cnt = 1;
        }
        prev = t;
    }
    color.push_back(prev);
    color_cnt.push_back(cnt);

    int first_color = color[0];
    int last_color = color[color.size()-1];
    int res = 0;
    if (first_color == last_color) {
        int bigger_standard = 0;
        int beside_bigger = 0;
        int bigger_idx = color_cnt[0] > color_cnt[color_cnt.size()-1] ? 0 : color_cnt.size()-1;
        for(int i = 0; i < color_cnt.size(); i++) {
            if (color[i] == first_color && i != bigger_idx) {
                bigger_standard += color_cnt[i];
            }
        }

        for(int i = 0; i < color_cnt.size(); i++) {
            if (color[i] != first_color) {
                beside_bigger += color_cnt[i];
            }
        }

        res = bigger_standard > beside_bigger ? beside_bigger : bigger_standard;
    } else {
        int first_start = 0;
        int last_start = 0;
        for(int i = 1; i < color_cnt.size(); i++) {
            if (color[i] == first_color) {
                first_start += color_cnt[i];
            }
        }

        for(int i = color_cnt.size()-2; i >= 0; i--) {
            if (color[i] == last_color) {
                last_start += color_cnt[i];
            }
        }
        res = first_start > last_start ? last_start : first_start;
    }
    std::cout << res;
}

/*
처음 진행할 땐 문제 조건이 단순히 오른쪽으로만 하나의 색상을 옮길 수 있다고 생각했다.
그 때 진행한 방식은 마지막 색상을 파악한 후 뒤에서부터 마지막 색상과 달라지는 index를 파악하고 0~index까지 red, blue 각 각 몇개를 움직여야되냐를 고민했다. -> 15점 처리

해결한 로직은 아래와 같다.
1. 옮기는 방향의 대한 제한 X
2. 분리되어야 하기 때문에 맨 앞 or 맨 뒤를 기준으로 옮길 수 있는지를 판단
    2-1. 이 때 서로 이웃한 색상이 다를 경우를 고려하기 위해 배열 2개로 색상과 중첩된 갯수를 관리했다.
3. 이동 로직
    3-1. 맨 앞과 맨 뒤 색상이 같은 경우 아래 2가지 중 더 작은 값을 채택했다.
        3-1-1. 맨 앞 or 맨 뒤 중 더 큰 중첩 갯수 index를 제외하고 색상이 같은 나머지 index들을 옮긴다고 가정
        3-1-2. 맨 앞(=맨 뒤)과 다른 색상들의 합
    3-2. 맨 앞과 맨 뒤 색상이 다른 경우는 단순히 맨 앞 색상을 다 옮기는 경우와 맨 뒤 색상을 옮기는 경우 중 더 작은 것을 채택  
*/