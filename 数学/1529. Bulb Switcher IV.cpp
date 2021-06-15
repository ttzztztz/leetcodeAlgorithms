class Solution {
public:
    int minFlips(string target) {
        int ans = 0, cur = 0;
        
        const int n = target.size();
        for (int i = 0; i < n; i++) {
            const int d = target[i] - '0';
            if (cur != d) {
                cur ^= 1;
                ans++;
            }
        }
        return ans;
    }
};