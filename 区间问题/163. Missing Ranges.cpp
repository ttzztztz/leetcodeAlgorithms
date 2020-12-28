class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        int last = lower;
        for (int i = 0; i < nums.size(); i++) {
            if (last != nums[i]) {
                ans.push_back(generate(last, nums[i] - 1));
            }
            last = nums[i] + 1;
        }
        
        if (last <= upper) {
            ans.push_back(generate(last, upper));
        }
        return ans;
    }
private:
    string generate(int a, int b) {
        if (a == b) return to_string(a);
        else return to_string(a) + "->" + to_string(b);
    }
};
