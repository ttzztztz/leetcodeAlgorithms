class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer;
        int ptr1 = 0, ptr2 = n;
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                answer.push_back(nums[ptr1++]);
            } else {
                answer.push_back(nums[ptr2++]);
            }
        }
        return answer;
    }
};
