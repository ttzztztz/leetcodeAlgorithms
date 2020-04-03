class Solution {
public:
    /**
     * @param nums: a binary array
     * @return:  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int answer = 0, current = 0;
        for (int i : nums) {
            if (i == 1) {
                current ++;
                answer = max(answer, current);
            } else {
                current = 0;
            }
        }
        
        return answer;
    }
};
