#include <iostream>
#include <vector>

bool check_around(int x, int y, std::vector<std::vector<char>>& grid) {
    std::vector<std::vector<int>> dire = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int cnt = 0;
    for(auto& d : dire) {
        int new_x = x + d[0];
        int new_y = y + d[1];
        if (!(0 <= new_x && new_x < grid.size() && 0 <= new_y && new_y < grid[0].size())) {
            cnt++;
        } else {
            if (grid[new_x][new_y] == '.') {
                cnt++;
            }
        }
    }
    return cnt >= 3? true : false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, y;
    std::cin >> x >> y;
    std::vector<std::vector<char>> grid(x, std::vector<char>(y, '.'));
    std::vector<std::vector<char>> after_50_y(x, std::vector<char>(y, '.'));
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            std::cin >> grid[i][j];
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (grid[i][j] == 'X') {
                if (check_around(i, j, grid)) {
                    after_50_y[i][j] = '.';
                } else {
                    after_50_y[i][j] = 'X';
                }
            }
        }
    }

    int x_min = grid.size(), x_max = 0;
    int y_min = grid[0].size(), y_max = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (after_50_y[i][j] == 'X') {
                if (i < x_min) {
                    x_min = i;
                }
                if (i > x_max) {
                    x_max = i;
                }
                if (j < y_min) {
                    y_min = j;
                }
                if (j > y_max) {
                    y_max = j;
                }
            }
        }
    }

    for (int i = x_min; i <= x_max; i++) {
        for (int j = y_min; j <= y_max; j++) {
            std::cout << after_50_y[i][j];
        }
        std::cout << std::endl;
    }
}