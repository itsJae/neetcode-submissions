class Solution {
public:
    void dfs(
        int x, 
        int y, 
        set<vector<int>>& ocean, 
        int m, 
        int n,
        vector<vector<int>>& heights
    ) {
        if (ocean.count({x, y})) return;
        ocean.insert({x, y});
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, 1, -1, 0};

        for (int i = 0 ; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                heights[x][y] <= heights[nx][ny]
            ) {
                dfs(nx, ny, ocean, m, n, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        set<vector<int>> pacific;
        set<vector<int>> atlantic;

        for (int row = 0; row < m; ++row) 
            dfs(row, 0, pacific, m, n, heights);

        for (int row = 0; row < m; ++row) 
            dfs(row, n - 1, atlantic, m, n, heights);
        
        for (int col = 0; col < n; ++col) 
            dfs(0, col, pacific, m, n, heights);

        for (int col = 0; col < n; ++col) 
            dfs(m - 1, col, atlantic, m, n, heights);

        for (auto p : pacific) {
            for (auto a : atlantic) 
                if (p == a) ans.push_back(p);
        }

        return ans;
    }
};
