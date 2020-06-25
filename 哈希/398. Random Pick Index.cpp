class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            number[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const vector<int>& v = number[target];
        
        uniform_int_distribution<int> d(0, (int) v.size() - 1);
        return v[d(gen)];
    }
private:
    unordered_map<int, vector<int>> number;
    mt19937 gen{random_device{}()};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
