class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.empty()) return 0;
        if (stones.size() == 1) return stones[0];
        
        int sum = 0;
        for (int i : stones) sum += i;
        
        int f[1505];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 0; i < stones.size(); i++) {
            const int s = stones[i];
            for (int j = sum / 2; j >= 0; j--) {
                if (j >= s && f[j - s]) f[j] = 1;
            }
        }
        
        for (int j = sum / 2; j >= 0; j--) {
            if (f[j]) return sum - 2 * j;
        }
        return 0;
    }
};
