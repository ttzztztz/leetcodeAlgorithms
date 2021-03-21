class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        const int mx = *max_element(coins.begin(), coins.end());
        const int sum = accumulate(coins.begin(), coins.end(), 0);
        vector<int> appear(mx + 1, 0);
        for (int i : coins) appear[i]++;
        
        int cur = 0;
        for (int i = 1; i <= mx; i++) {
            cur += appear[i] * i;
            if (cur < i) return cur + 1;
        }
        return sum + 1; // never
    }
};
