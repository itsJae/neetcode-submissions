class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        string ans = "";
        
        for (int i = 0; i < s.size(); ++i) {
            string subs = s.substr(0, i + 1);

            for (int j = 0; j < strs.size(); ++j) {
                if (strs[j].find(subs) == string::npos) {
                    return ans;
                }
            }

            ans = subs;
        }

        return ans;
    }
};