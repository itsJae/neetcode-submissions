class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n);

        if (n == 1 && s[0] != '0') return 1;
        if (s[0] == '0') return 0;
        
        int first = s[0] - '0';
        int second = s[1] - '0';
        int combined = first * 10 + second;

        if (combined > 26 and second == 0) return 0;
        dp[0] = 1;
        dp[1]++;

        if (combined >= 11 and combined <= 26 and second != 0) 
            dp[1]++;

        for (int i = 2; i < n; ++i) {
            // need to check 0
            first = second;
            second = s[i] - '0';

            // cout << first << ", " << second << endl;
            // cout << "dp: " << endl;
            // for (auto x : dp) {
            //     cout << x << endl;
            // }
            
            if (!(first == 1 or first == 2) and second == 0) return 0;
            combined = first * 10 + second; 


            if (combined >= 11 && combined <= 26 and second != 0) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else if (combined == 10 || combined == 20) {
                dp[i] = dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        } 

        return dp[n - 1];
    }
};
