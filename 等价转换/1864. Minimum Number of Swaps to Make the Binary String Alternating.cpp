class Solution {
public:
    int minSwaps(string s) {
        vector<int> cnt(2, 0);
        for (const char ch : s) cnt[ch - '0']++;
        if (abs(cnt[0] - cnt[1]) > 1) return -1;
        
        const int n = s.size();
        if (n % 2 == 1) {
            if (cnt[0] > cnt[1]) return solve(s, 0);
            else return solve(s, 1);
        } else {
            return min(solve(s, 0), solve(s, 1));
        }
    }
private:
    int solve(const string& str, int cur) {
        const int n = str.size();
        int ans = 0;
        string target;
        for (int i = 0; i < n; i++) {
            target.push_back('0' + cur);
            cur ^= 1;
        }
        
        for (int i = 0; i < n; i++) {
            ans += (str[i] != target[i]);
        }
        return ans / 2;
    }
};