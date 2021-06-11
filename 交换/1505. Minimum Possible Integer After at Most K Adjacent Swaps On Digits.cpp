class Solution {
public:
    string minInteger(string num, int k) {
        const int n = num.size();
        memset(data, 0, sizeof data);
        
        vector<vector<int>> pos(10);
        for (int i = 0; i < n; i++) {
            const int d = num[i] - '0';
            pos[d].push_back(i);
        }
        
        string ans;
        for (int i = 0; i < n; i++) {
            for (int d = 0; d < 10; d++) {
                if (pos[d].empty()) continue;
                const int u = pos[d][0];
                
                const int cost = u - query(u);
                if (cost <= k) {
                    k -= cost;
                    pos[d].erase(pos[d].begin());
                    ans += '0' + d;
                    inc(u, 1);
                    break;
                }
            }
        }
        return ans;
    }
private:
    int data[30005];
    int lowbit(int u) {
        return u&(-u);
    }
    int query(int u) {
        u++;
        int ans = 0;
        while (u) {
            ans += data[u];
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int v) {
        u++;
        while (u && u <= 30001) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};