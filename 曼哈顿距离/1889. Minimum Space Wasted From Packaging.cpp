class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        typedef long long ll;
        ll ans = numeric_limits<ll>::max();
        const int mod = 1e9+7;
        memset(data, 0, sizeof data);
        const int mxp = *max_element(packages.begin(), packages.end());
        
        int mx = 0;
        for (auto& box : boxes) {
            sort(box.begin(), box.end());
            mx = max(mx, box.back());
        }
        
        ll ttl = 0;
        for (ll i : packages) {
            ttl += (mx - i);
            inc(i, 1);
        }
        
        // cout << mx << "|" << ttl << endl;
        for (auto& box : boxes) {
            ll cur = ttl;
            if (box.back() < mxp) continue;
            
            ll last = mx, v = packages.size();
            for (int i = box.size() - 1; i >= 0; i--) {
                v -= (query(last) - query(box[i]));
                cur -= (last - box[i]) * v;
                
                // cout << box[i] << "," << last << "|" << v << "," << (last - box[i]) << endl;
                last = box[i];
            }
            ans = min(ans, cur);
        }
        
        // cout << endl;
        if (ans == numeric_limits<ll>::max()) return -1;
        return ans % mod;
    }
private:
    int data[100005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int u) {
        int ans = 0;
        while (u) {
            ans += data[u];
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        while (u && u <= 100000) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};