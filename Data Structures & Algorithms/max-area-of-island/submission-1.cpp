class Solution {
public:
    void dfsRec(
        vector<vector<int>>& grid,
        int rowSize,
        int colSize,
        int u,
        int v,
        int& cnt
    ) {
        grid[u][v] = 0;
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, 1, -1, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = u + dx[i];
            int ny = v + dy[i];
        
            if (nx >= 0 && nx < rowSize && ny >= 0 && ny < colSize) {
                if (grid[nx][ny] == 1) {
                    ++cnt;
                    dfsRec(grid, rowSize, colSize, nx, ny, cnt);
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == 1) {
                    int cnt = 1;
                    dfsRec(grid, rowSize, colSize, i, j, cnt);
                    maxArea = max(maxArea, cnt);
                }
            }
        }

        return maxArea;
    }
};
