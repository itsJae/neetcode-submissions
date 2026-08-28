class Solution {
public:
    void dfs(
        vector<vector<char>>& board,
        int u,
        int v,
        int m,
        int n
    ) {
        board[u][v] = '#';
        vector<int> dx = {1, 0, 0, -1};
        vector<int> dy = {0, 1, -1, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = u + dx[i];
            int ny = v + dy[i];

            if (nx < m && nx >= 0 && ny < n && ny >= 0 && board[nx][ny] == 'O') 
                dfs(board, nx, ny, m, n);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                    dfs(board, i, j, m, n);
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
