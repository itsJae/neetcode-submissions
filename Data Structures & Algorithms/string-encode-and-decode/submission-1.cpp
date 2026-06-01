class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        
        for (string str : strs) 
            encoded += (to_string(str.length()) + '#' + str);

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i {0};

        while (i < s.length())
        {
            int j {i};

            while (s[j] != '#')
                j++;
            
            int len = stoi(s.substr(i, j - i));

            decoded.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return decoded;
    }
};
