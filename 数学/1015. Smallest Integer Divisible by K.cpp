class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 || K % 5 == 0) return -1;
        
        int ans = 1, i = 1;
        while (i % K != 0) {
            i %= K;
            i = i * 10 + 1;
            ans++;
        }
        return ans;
    }
};
