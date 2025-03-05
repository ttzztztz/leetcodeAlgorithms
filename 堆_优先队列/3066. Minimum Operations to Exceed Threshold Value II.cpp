class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if (nums.empty()) return -1;

        typedef long long ll;
        priority_queue<ll, vector<ll>, greater<>> heap;
        for (int i : nums) heap.push(i);


        int ans = 0;
        while (heap.top() < k) {
            const ll x = heap.top();
            heap.pop();
            const ll y = heap.top();
            heap.pop();

            heap.push(min(x, y) * 2 + max(x, y));
            ans++;
        }
        return ans;
    }
};