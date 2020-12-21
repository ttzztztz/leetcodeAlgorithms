class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        do {
            answer.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return answer;
    }
};
