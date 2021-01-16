class Solution {
public:
    /**
     * @param nums:  a sorted integer array without duplicates
     * @return: the summary of its ranges
     */
    vector<string> summaryRanges(vector<int> &nums) {
        // Write your code here
        vector<string> ans;
        if (nums.empty()) return ans;
        
        int lastl = nums[0], lastr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (lastr + 1 == nums[i]) {
                lastr = nums[i];
            } else {
                ans.push_back(generate(lastl, lastr));
                lastl = lastr = nums[i];
            }
        }
        
        ans.push_back(generate(lastl, lastr));
        return ans;
    }
private:
    string generate(int l, int r) {
        if (l == r) {
            return to_string(l);
        } else {
            return to_string(l) + "->" + to_string(r);
        }
    }
};
