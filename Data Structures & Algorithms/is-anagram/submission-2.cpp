class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;

        if (s.length() != t.length()) return false;

        for (char c : s)
            s_map[c]++;

        for (char c : t)
            s_map[c]--;

        for (const auto& [key, val] : s_map)
            if (val != 0) return false;

        return true;
    }
};
