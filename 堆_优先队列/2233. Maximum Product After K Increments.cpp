class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> heap;
        for (int i : nums) heap.push(i);
        while (k > 0) {
            auto t = heap.top();
            heap.pop();
            heap.push(t + 1);
            k--;
        }
        
        ll ans = 1;
        while (!heap.empty()) {
            const ll i = heap.top();
            heap.pop();
            ans = (ans * i) % mod;
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
};
