class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            pair<int, int> u = q.front();
            q.pop();


            vector<int> dx = {1, 0, 0, -1};
            vector<int> dy = {0, 1, -1, 0};

            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i];
                int ny = u.second + dy[i];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !visited[nx][ny] && grid[nx][ny] > 0
                ) {
                    q.push({nx, ny});
                    // if (grid[nx][ny] > grid[u.first][u.second] + 1) {
                    visited[nx][ny] = true;
                    grid[nx][ny] = grid[u.first][u.second] + 1;
                    // }
                }
            }
        }
    }
};