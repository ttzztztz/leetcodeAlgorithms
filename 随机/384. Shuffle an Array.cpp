class Solution {
public:
    Solution(vector<int>& nums) {
        this->data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = data;
        for (int i = ans.size() - 1; i >= 0; i--) {
            uniform_int_distribution<int> d(0, i);
            const int t = d(rd);
            swap(ans[i], ans[t]);
        }
        return ans;
    }
private:
    vector<int> data;
    mt19937 rd{ random_device{}() };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
