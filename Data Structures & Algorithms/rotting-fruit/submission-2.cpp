class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    visited[i][j] = true;
                    q.push({i, j});
                }
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int size = q.size();
            bool isIncremented = false;

            for (int i = 0; i < size; ++i) {
                pair<int, int> dq = q.front();
                q.pop();
                
                vector<int> dx = {1, 0, 0, -1};
                vector<int> dy = {0, -1, 1, 0};

                for (int i = 0; i < 4; ++i) {
                    int nx = dq.first + dx[i];
                    int ny = dq.second + dy[i];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                        !visited[nx][ny] && grid[nx][ny] == 1
                    ) {
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        visited[nx][ny] = true;
                        isIncremented = true;
                    }
                }
            }

            if (isIncremented) ++cnt;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return cnt;
    }
};
