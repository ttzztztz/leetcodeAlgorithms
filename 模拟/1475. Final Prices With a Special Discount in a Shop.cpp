class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int N = prices.size();
        vector<int> answer(N);
        
        for (int i = 0; i < N; i++) {
            answer[i] = prices[i];
            for (int j = i + 1; j < N; j++) {
                if (prices[j] <= prices[i]) {
                    answer[i] -= prices[j];
                    break;
                }
            }
        }
        
        return answer;
    }
};
