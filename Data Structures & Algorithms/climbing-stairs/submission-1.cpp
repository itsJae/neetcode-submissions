class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;

        vector<int> fib(n + 1);
        fib[1] = 1;
        fib[2] = 2;

        for (int i = 3; i <= n; ++i) {
            fib[i] = fib[i - 2] + fib[i - 1];
        }

        return fib[n];
    }
};
