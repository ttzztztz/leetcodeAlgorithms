class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        typedef pair<int, int> PII;
        typedef long long ll;
        const int mod = 1e9+7;
        
        vector<PII> data;
        for (int i = 0; i < n; i++) data.emplace_back(speed[i], efficiency[i]);
        sort(data.begin(), data.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs.second > rhs.second;
        });
        
        ll ans = 0, sum = 0;
        priority_queue<ll, vector<ll>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            auto [s, e] = data[i];
            
            if (heap.size() < k) {
                heap.push(s);
                sum += s;
            } else if (heap.size() == k && heap.top() < s) {
                sum -= heap.top();
                heap.pop();
                
                sum += s;
                heap.push(s);
            }
            
            ans = max(ans, sum * e);
        }
        return ans % mod;
    }
};