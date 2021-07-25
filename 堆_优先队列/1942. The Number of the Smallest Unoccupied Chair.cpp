class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        const int arrival = times[targetFriend][0];
        const int n = times.size();
        sort(times.begin(), times.end());
        
        set<int> tt;
        for (int i = 0; i < n; i++) tt.insert(i);
        typedef pair<int, int> pii;
        
        priority_queue<pii, vector<pii>, greater<>> heap;
        for (int i = 0; i < n; i++) {
            const int l = times[i][0], r = times[i][1];
            while (!heap.empty() && heap.top().first <= l) {
                auto [time, idx] = heap.top();
                heap.pop();
                tt.insert(idx);
            }
            
            const int ord = *tt.begin();
            heap.emplace(r, ord);
            tt.erase(ord);
            if (l == arrival) return ord;
        }
        return -1;
    }
};