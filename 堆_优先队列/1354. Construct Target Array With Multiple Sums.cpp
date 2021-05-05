class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int n = target.size();
        
        typedef long long ll;
        ll sum = accumulate(target.begin(), target.end(), 0ll);
        priority_queue<int, vector<int>, less<>> heap(target.begin(), target.end());
        
        while (sum > 1 && heap.top() > sum / 2) {
            const ll t = heap.top();
            heap.pop();
            sum -= t;
            if (sum <= 1) return sum == 1;
            
            const ll next = t % sum;
            heap.push(next);
            sum += next;
        }
        return sum == n;
    }
};