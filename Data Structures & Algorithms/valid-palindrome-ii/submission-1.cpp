class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }

        return true;
    }

    bool validPalindrome(string s) {
        string tmp = s;

        for (int i = 0; i < s.size(); ++i) {
            tmp.erase(i, 1);
            
            if (isPalindrome(tmp)) 
                return true;

            tmp = s;
        }

        return false;
    }
};