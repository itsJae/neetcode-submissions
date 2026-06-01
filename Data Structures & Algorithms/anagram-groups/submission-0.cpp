class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hash_map;
        std::vector<std::vector<std::string>> ans;

        for (std::string str : strs) 
        {
            std::vector <int> arr(26);

            for (char c: str)
                arr[c - 'a']++;    
            
            std::string key_string = "";
            for (int n : arr)
                key_string += std::to_string(n) + "#";

            hash_map[key_string].push_back(str);
        }

        for (const auto& [key, val] : hash_map)
        {
            ans.push_back(val);
        }

        return ans;
    }
};
