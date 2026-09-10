class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        
        int n = board.size();
        int m = board[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                dfs(board, nx, ny);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < m; ++i) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }

            if (board[n - 1][i] == 'O') {
                dfs(board, n - 1, i);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }

            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }

    }
};
