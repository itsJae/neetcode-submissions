class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        int cnt = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j].size() == i || 
                    s[i] != strs[j][i]
                ) 
                    return s.substr(0, cnt);
            }

            ++cnt;
        }

        return s.substr(0, cnt);
    }
};