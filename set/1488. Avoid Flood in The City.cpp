class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int n = rains.size();
        
        unordered_map<int, int> appear;
        vector<int> ans(n);
        set<int> usable;
        for (int i = 0; i < n; i++) {
            const int rain = rains[i];
            
            if (rain == 0) {
                usable.insert(i);
                ans[i] = 1;
            } else {
                if (!appear.count(rain)) {
                    appear[rain] = i;
                } else {
                    const int t = appear[rain];
                    appear[rain] = i;
                    auto it = usable.lower_bound(t);
                    
                    if (it == usable.end()) {
                        return {};
                    } else {
                        ans[*it] = rain;
                        usable.erase(it);
                    }
                }
                ans[i] = -1;
            }
        }
        return ans;
    }
};