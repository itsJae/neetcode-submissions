class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;

        while (l <= r) {
            cout << "l: " << l << ", r: " << r << endl;

            if (people[l] + people[r] <= limit) {
                ++l;
                --r;
                ++ans;
            } else {
                ++ans;
                --r;
            }
        }

        return ans;
    }
};