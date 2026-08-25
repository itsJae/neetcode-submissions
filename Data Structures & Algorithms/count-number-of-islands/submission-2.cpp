class Solution {
public:
    void dfsRec(
        vector<vector<char>>& grid, 
        int i, 
        int j,
        int rowSize,
        int colSize
    ) {
        grid[i][j] = '0';
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, 1, -1, 0};
        
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < rowSize && ny >= 0 && ny < colSize) {
                if (grid[nx][ny] == '1') {
                    dfsRec(grid, nx, ny, rowSize, colSize);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    dfsRec(grid, i, j, rowSize, colSize);
                }
            }
        }

        return cnt;
    }
};