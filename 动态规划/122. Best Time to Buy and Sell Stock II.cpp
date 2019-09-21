class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int answer = 0;

        int buyPtr = 0, tempMin = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                if (i - buyPtr > 1) {
                    answer += prices[i - 1] - prices[buyPtr];
                }
                buyPtr = i;
            }
        }

        if (prices.size() - buyPtr > 1) {
            answer += prices[prices.size() - 1] - prices[buyPtr];
        }
        return answer;
    }
};