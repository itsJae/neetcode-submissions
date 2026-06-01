class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> square_map;
        unordered_map<int, unordered_set<char>> row_map;
        unordered_map<int, unordered_set<char>> col_map;
        

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int square_idx = (i / 3) * 3 + (j / 3);

                if (isdigit(board[i][j])) {
                    // Check square
                    auto add = square_map[square_idx].insert(board[i][j]);
                    if (!add.second) return false;

                    // Check row/col
                    add = row_map[i].insert(board[i][j]);
                    if (!add.second) return false;

                    add = col_map[j].insert(board[i][j]);
                    if (!add.second) return false;
                }
            }
        }

        return true;
    }
};
