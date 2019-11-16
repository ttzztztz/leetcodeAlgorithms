class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = -99999999;

        int temp1 = 1, temp2 = 1;
        for (const int num : nums) {
            if (num < 0) {
                swap(temp1, temp2);
            }

            temp1 = max(temp1 * num, num);
            temp2 = min(temp2 * num, num);

            answer = max(answer, max(temp1, temp2));
        }
        return answer;
    }
};