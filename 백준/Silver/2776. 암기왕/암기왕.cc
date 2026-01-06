#include <iostream>
#include <vector>
#include <algorithm>

bool find(std::vector<int>& note, int v) {
    if (note[note.size()-1] < v) {
        return false;
    }

    int left = 0, right = note.size()-1;
    while(left <= right) {
        int mid = (right+left)/2;
        if (note[mid] == v) {
            return true;
        } else if (note[mid] < v) {
            left = mid + 1;
        } else {
            right = mid -1;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;

    while(t > 0) {
        int n, m;
        std::cin >> n;
        std::vector<int> note;
        for(int i = 0 ; i < n; i++) {
            int p;
            std::cin >> p;
            note.push_back(p);
        }
        std::sort(note.begin(), note.end(), std::less<int>());

        std::cin >> m;
        for(int i = 0 ; i < m; i++) {
            int p;
            std::cin >> p;
            int res = find(note, p);
            if (res) std::cout << "1\n";
            else std::cout << "0\n";
        }

        t -= 1;
    }
}