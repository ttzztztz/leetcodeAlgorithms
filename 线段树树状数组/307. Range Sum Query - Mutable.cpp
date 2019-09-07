class NumArray {
public:
    int indexTree[100005];
    vector<int>* rawNums;

    int lowbit(int x) {
        return x & (-x);
    }

    NumArray(vector<int>& nums) : rawNums(&nums) {
        std::memset(indexTree, 0, sizeof(indexTree));

        for (int i = 0; i < nums.size(); i++) {
            this->increment(i + 1, nums[i]);
        }
    }

    void increment(int i, int val) {
        while (i && i < 100005) {
            indexTree[i] += val;
            i += lowbit(i);
        }
    }

    void update(int i, int val) {
        int previousNumber = (*rawNums)[i];
        (*rawNums)[i] = val;
        int delta = val - previousNumber;
        increment(i + 1, delta);
    }

    int sum(int i) {
        int answer = 0;
        while (i) {
            answer += indexTree[i];
            i -= lowbit(i);
        }
        return answer;
    }

    int sumRange(int i, int j) {
        return this->sum(j + 1) - this->sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */