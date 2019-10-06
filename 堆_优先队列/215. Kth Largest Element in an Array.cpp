class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> queue;

        for (int i = 0; i < k; i++) {
            queue.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            queue.push(nums[i]);
            queue.pop();
        }

        return queue.top();
    }
};