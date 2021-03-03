class MRUQueue {
public:
    MRUQueue(int n) {
        t = sqrt(n);
        for (int i = 1; i <= n; i++) {
            if (data.empty() || data.back().size() >= t) {
                if (data.empty()) pref.push_back(0);
                else pref.push_back(pref.back() + data.back().size());
                data.push_back({});
            }
            data.back().push_back(i);
        }
    }
    
    int fetch(int k) {
        k--;
        auto it = --upper_bound(pref.begin(), pref.end(), k);
        const int idx = it - pref.begin();
        
        const int ans = data[idx][k - pref[idx]];
        data[idx].erase(data[idx].begin() + k - pref[idx]);
        
        for (int i = idx + 1; i < pref.size(); i++) {
            pref[i]--;
        }
        if (data.back().size() >= t) {
            pref.push_back(pref.back() + data.back().size());
            data.push_back({ ans });
        } else {
            data.back().push_back(ans);
        }
        
        if (data[idx].empty()) {
            data.erase(data.begin() + idx);
            pref.erase(pref.begin() + idx);
        }
        return ans;
    }
private:
    int t;
    vector<vector<int>> data;
    vector<int> pref;
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
