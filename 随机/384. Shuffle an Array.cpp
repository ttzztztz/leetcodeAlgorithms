class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> ans = nums;

        const int n = ans.size();
        random_device rd;
        mt19937 gen(rd());

        for (int i = 0; i < n; i++) {
            uniform_int_distribution<int> d(i, n - 1);

            const int j = d(gen);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */