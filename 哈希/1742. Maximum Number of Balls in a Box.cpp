class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> cnt;
        for (int i = lowLimit; i <= highLimit; i++) {
            int d = 0;
            int t = i;
            while (t) {
                d += t % 10;
                t /= 10;
            }
            
            cnt[d]++;
        }
        
        int ans = 0;
        for (auto [k, v] : cnt) ans = max(ans, v);
        return ans;
    }
};
