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
        ::shuffle(ans.begin(), ans.end(), rd);
        return ans;
    }
private:
    mt19937 rd{ random_device{}() };
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
