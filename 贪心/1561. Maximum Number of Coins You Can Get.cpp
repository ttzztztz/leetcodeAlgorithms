class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0;
        const int n = piles.size();
        sort(piles.begin(), piles.end());
        for (int i = n - 2, j = 0; j < n / 3; j++, i -= 2) {
            ans += piles[i];
        }
        return ans;
    }
};