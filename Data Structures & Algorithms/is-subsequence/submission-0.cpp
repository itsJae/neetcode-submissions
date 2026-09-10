class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;

        for (auto c : t) {
            // cout << "c: " << c << ", s[i]: " << s[i] << endl;
            if (c == s[i])
                ++i;
        }

        // cout << i << endl;
        if (i == s.size()) return true;
        return false;
    }
};