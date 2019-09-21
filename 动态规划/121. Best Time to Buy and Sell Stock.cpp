class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;

        int minAnswer = 0x5fffffff;
        for (int price : prices) {
            if (price - minAnswer > 0) {
                answer = std::max(answer, price - minAnswer);
            }
            minAnswer = std::min(minAnswer, price);
        }

        return answer;
    }
};