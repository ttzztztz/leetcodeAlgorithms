class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        while (!valid(nums)) {
            const int n = nums.size();
            for (int i = n - 1; i >= 0; i--) {
                swap(nums[i], nums[random(i)]);
            }
        }
        
        return nums;
    }
private:
    mt19937 rd{ random_device{}() };
    int random(int j) {
        uniform_int_distribution d(0, j);
        return d(rd);
    }
    
    bool valid(const vector<int>& nums) {
        for (int i = 1; i + 1 < nums.size(); i++) {
            if (2 * nums[i] == nums[i - 1] + nums[i + 1]) return false;
        }
        return true;
    }
};