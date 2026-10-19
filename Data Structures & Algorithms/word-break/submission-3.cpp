class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();
        vector<bool> dp(n);

        for (int i = 0; i < n; ++i) {
            string subS = s.substr(0, i + 1);

            if (find(wordDict.begin(), wordDict.end(), subS) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }

        for (int i = 0; i < n; ++i) {
            string subS = s.substr(0, i + 1);
            bool exists = find(
                wordDict.begin(), 
                wordDict.end(), 
                subS
                ) != wordDict.end() ? true : false;
            
            if (exists) {
                dp[i] = true;
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (dp[j]) {
                    subS = s.substr(j + 1, i - j);
                    exists = find(
                        wordDict.begin(), 
                        wordDict.end(), 
                        subS
                        ) != wordDict.end() ? true : false;
                    if (!dp[i])
                        dp[i] = dp[j] and exists;
                }
            }
        }

        // for (auto x : dp) 
        //     cout << x << endl;

        return dp[n - 1];
    }
};
