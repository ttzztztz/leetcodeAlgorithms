class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0;
        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, greater<>> heap;
        const int n = apples.size();
        
        for (int i = 1; i <= n; i++) {
            const int a = apples[i - 1], d = days[i - 1];
            while (!heap.empty() && heap.top().first <= i) heap.pop();
            
            if (a > 0 && d > 0) {
                heap.emplace(i + d, a);
            }
            
            if (!heap.empty()) {
                auto [rot, cnt] = heap.top();
                heap.pop();
                
                ans++;
                if (cnt - 1 >= 1) heap.emplace(rot, cnt - 1);
            }
        }
        
        int d = n + 1;
        while (!heap.empty()) {
            auto [rot, cnt] = heap.top();
            heap.pop();
            
            ans += min(rot - d, cnt);
            
            d = min(rot, d + cnt);
        }
        return ans;
    }
};
