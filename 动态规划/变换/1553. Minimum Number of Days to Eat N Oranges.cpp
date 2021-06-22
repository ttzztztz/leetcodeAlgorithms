class Solution {
public:
    int minDays(int n) {
        if (n == 0) return 0;
        if (memo.count(n)) return memo[n];
        
        int ans = n;
        ans = min(ans, (n % 2) + 1 + minDays(n / 2));
        ans = min(ans, (n % 3) + 1 + minDays(n / 3));
        return memo[n] = ans;
    }
private:
    unordered_map<int, int> memo;
};