#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> grid(n+1, std::vector<int>(n+1, 0));
    std::vector<std::vector<int>> prefix(n+1, std::vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            std::cin >> grid[i][j];
            prefix[i][j] = grid[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    for(int i = 0; i < m; i++) {
        int start_x, start_y, end_x, end_y;
        std::cin >> start_x >> start_y >> end_x >> end_y;
        int prefix_sum = prefix[end_x][end_y] + prefix[start_x-1][start_y-1] - prefix[start_x-1][end_y] - prefix[end_x][start_y-1];
        std::cout << prefix_sum << "\n";
    }
}

/*
1, 2차원 배열의 누적합 obsidian 정리 참고.
출력에 std::endl 사용해서 시간 초과 발생
*/