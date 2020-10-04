class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        const int n = arrival.size();
        vector<int> times(k, 0);
        
        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, greater<>> q;
        set<int> avail;
        for (int i = 0; i < k; i++) avail.insert(i);
        
        for (int i = 0; i < n; i++) {
            const int idx = i % k;
            while (!q.empty() && q.top().first <= arrival[i]) {
                avail.insert(q.top().second);
                q.pop();
            }
            
            if (avail.empty()) continue;
            auto it1 = avail.lower_bound(idx);
            if (it1 == avail.end()) {
                it1 = avail.begin();
            }
            
            const int server = *it1;
            times[server]++;
            q.emplace(arrival[i] + load[i], server);
            avail.erase(it1);
        }
        
        vector<int> ans;
        const int mx = *max_element(times.begin(), times.end());
        for (int i = 0; i < k; i++) {
            if (times[i] == mx) ans.push_back(i);
        }
        return ans;
    }
};
