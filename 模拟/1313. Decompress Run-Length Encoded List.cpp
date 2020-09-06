class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> answer;
        const int N = nums.size();
        for (int i = 0; 2 * i + 1 < N; i++) {
            const int a = nums[2 * i], b = nums[2 * i + 1];
            for (int j = 0; j < a; j++) {
                answer.push_back(b);
            }
        }
        return answer;
    }
};
