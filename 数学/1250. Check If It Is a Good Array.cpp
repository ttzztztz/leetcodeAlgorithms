class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        const int N = nums.size();

        int answer = nums[0];
        for (int i = 1; i < N; i++) {
            answer = std::__gcd(answer, nums[i]);
        }
        return answer == 1;
    }
};