class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int answer = 0;
        sort(piles.begin(), piles.end());
        const int n = piles.size();
        
        for (int i = n - 2, k = 0; i >= 0 && k < n / 3; i -= 2, k++) {
            answer += piles[i];
        }
        return answer;
    }
};
