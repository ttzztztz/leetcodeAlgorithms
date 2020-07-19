class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0, last = numBottles;
        while (last) {
            answer += last;
            last = numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
            
        }
        return answer;
    }
};
