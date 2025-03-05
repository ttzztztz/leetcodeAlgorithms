class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;

        int last = lower;
        for (int i : nums) {
            if (last < i) ans.push_back(vector<int>{ last, i - 1 });
            last = i + 1;
        }

        if (last <= upper) ans.push_back(vector<int>{ last, upper });
        return ans;
    }
};