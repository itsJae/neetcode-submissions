class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // int start = 0;
        // int maxLen = 1;
        int ans = 0;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] and (j - i < 2 or dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++ans;
                }
            }
        }

        // cout << "table: " << endl;

        // for (auto x: dp) {
        //     for (auto y: x) {
        //         cout << y << " ";
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};
