class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i : nums) {
            sum.push_back(sum.back() + i);
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right + 1] - sum[left];
    }
private:
    vector<int> sum = { 0 };
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */