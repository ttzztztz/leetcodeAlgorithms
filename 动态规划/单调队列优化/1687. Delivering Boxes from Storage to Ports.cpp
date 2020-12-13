class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        const int n = boxes.size();
        
        vector<int> f(n + 1, 0), g(n + 1, 0);
        typedef long long ll;
        vector<ll> h(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (boxes[i - 1][0] != boxes[i - 2][0]) g[i] = g[i - 1] + 1;
            else g[i] = g[i - 1];
        }
        for (int i = 1; i <= n; i++) h[i] = h[i - 1] + boxes[i - 1][1];
        
        deque<int> q = {0};
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && i - q.front() > maxBoxes) q.pop_front();
            while (!q.empty() && h[i] - h[q.front()] > maxWeight) q.pop_front();
            
            f[i] = f[q.front()] - g[q.front() + 1] + g[i] + 2;
            if (i >= n) continue;
            while (!q.empty() && f[q.back()] - g[q.back() + 1] > f[i] - g[i + 1]) q.pop_back();
            q.push_back(i);
        }
        return f[n];
    }
};
