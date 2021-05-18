class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        const int q = queries.size();
        memset(data, 0, sizeof data);
        vector<int> pos(m + 1, 0);
        for (int i = 1; i <= m; i++) {
            inc(q + i, 1);
            pos[i] = q + i;
        }
        
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            const int t = queries[i];
            ans[i] = query(pos[t]) - 1;
            
            inc(pos[t], -1);
            pos[t] = q - i;
            inc(pos[t], 1);
        }
        return ans;
    }
    
private:
    int data[2005];
    int lowbit(int x) {
        return x&(-x);
    }
    int query(int x) {
        int ans = 0;
        while (x) {
            ans += data[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void inc(int u, int v) {
        while (u && u <= 2000) {
            data[u] += v;
            u += lowbit(u);
        }
    }
};