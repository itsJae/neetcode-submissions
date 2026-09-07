class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m) return "";

        unordered_map<char, int> need;
        int l = 0;
        int r = 0;

        for (auto x : t) 
            ++need[x];

        unordered_map<char, int> window;
        int have = 0;
        int minRes = INT_MAX;
        pair<int, int> minInterval = {-1, -1};
        string ans = "";

        while (r < n) {
            char cR = s[r];
            
            ++window[cR];
            ++r;

            if (need.count(cR) && window[cR] == need[cR])
                ++have;

            while (have == need.size()) {
                char cL = s[l];
                
                if (minRes > r - l) {
                    minRes = r - l;
                    minInterval = {l, r};
                }

                if (need.count(cL) != 0 && window[cL] == need[cL]) 
                    --have;

                --window[cL];          
                ++l;
            }
        }
        
        if (minInterval.first == -1 || minInterval.second == -1) return "";
        return s.substr(minInterval.first, minRes);
    }
};
