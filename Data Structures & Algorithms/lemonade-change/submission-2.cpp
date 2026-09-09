class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; ++i) {
            if (bills[i] == 5) 
                ++m[bills[i]];
            else if (bills[i] == 10) {
                if (m[5] == 0) return false;
                --m[5];
                ++m[10];
            } else {
                if (m[5] > 0 && m[10] > 0) {
                    --m[5];
                    --m[10];
                } else if (m[5] > 2 && m[10] == 0) 
                    m[5] -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};