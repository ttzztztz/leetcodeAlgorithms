class Solution {
public:
    /**
     * @param prices: a list of integer
     * @return: return the actual prices
     */
    vector<int> FinalDiscountedPrice(vector<int> &prices) {
        const int N = prices.size();
        vector<int> answer(N, 0);
        
        vector<int> stk;
        for (int i = N - 1; i >= 0; i--) {
            while (!stk.empty() && stk.back() > prices[i]) stk.pop_back();
            
            if (stk.empty()) answer[i] = prices[i] - 0;
            else answer[i] = prices[i] - stk.back();
            
            stk.push_back(prices[i]);
        }
        
        return answer;
    }
};
