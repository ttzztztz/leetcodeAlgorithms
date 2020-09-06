class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefixSum = 0, answer = 1;
        for (int i : nums) {
            prefixSum += i;
            if (prefixSum < 0) answer = max(answer, -prefixSum + 1);
        }
        
        return answer;
    }
};
