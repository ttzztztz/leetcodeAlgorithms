class Solution {
public:
    Solution(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            hmap[nums[i]].push_back(i);
        }

        gen = mt19937(rd());
    }
    
    int pick(int target) {
        const vector<int>& target_vec = hmap[target];
        uniform_int_distribution<int> d(0, target_vec.size() - 1);
        return target_vec[d(gen)];
    }
private:
    random_device rd;
    mt19937 gen;

    unordered_map<int, vector<int>> hmap;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */