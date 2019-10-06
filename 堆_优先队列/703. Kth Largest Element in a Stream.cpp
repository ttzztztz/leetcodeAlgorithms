class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> queue;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            queue.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            queue.pop();
        }
    }

    int add(int val) {
        queue.push(val);
        if (queue.size() > k) {
            queue.pop();
        }
        return queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */