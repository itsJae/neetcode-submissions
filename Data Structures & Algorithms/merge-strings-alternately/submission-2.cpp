class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int p1 = 0;
        int p2 = 0;
        int s1 = word1.size();
        int s2 = word2.size();

        while (p1 < s1 && p2 < s2) {
            ans.push_back(word1[p1]); 
            ans.push_back(word2[p2]); 

            ++p1;
            ++p2;
        } 

        if (p1 == s1) {
            while (p2 < s2) {
                ans.push_back(word2[p2]);
                ++p2;
            }
        } else if (p2 == s2) {
            while (p1 < s1) {
                ans.push_back(word1[p1]);
                ++p1;
            }
        }

        return ans;
    }
};