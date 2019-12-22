class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for (int num : nums) {
            int digit = 0;
            while (num) {
                digit++;
                num /= 10;
            }

            if (digit % 2 == 0) {
                answer++;
            }
        }

        return answer;
    }
};