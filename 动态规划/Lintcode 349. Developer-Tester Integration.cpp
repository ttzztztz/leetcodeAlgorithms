class Solution {
public:
    /**
     * @param d:  limit the number of developers that can be seated consecutively with employees of the same type
     * @param t:  limit the number of testers that can be seated consecutively with employees of the same type
     * @param queries: the queries of team size 
     * @return: return the number of ways
     */
    vector<int> theNumberofWays(int d, int t, vector<int> &queries) {
        memset(f, 0, sizeof f);
        memset(data, 0, sizeof data);

        f[0][0] = f[0][1] = 1;
        inc(1, 0, 1), inc(1, 1, 1);
        
        const int mx = *max_element(queries.begin(), queries.end());
        for (int people = 1; people <= mx; people++) {
            for (int kind = 0; kind <= 1; kind++) {
                const int limit = ((kind == 0) ? d : t) - 1;
                
                f[people][kind] = (query(people, kind ^ 1) - query(max(0, people - limit), kind ^ 1) + mod) % mod;
                inc(people + 1, kind, f[people][kind]);
            }
        }

        vector<int> ans;
        for (const int q : queries) {
            ll t = (f[q][0] + f[q][1]) % mod;
            ans.push_back(t);
        }
        return ans;
    }
private:
    typedef long long ll;
    const int mod = 1e9+7;
    ll f[100005][2], data[100005][2];

    int lowbit(int x) {
        return x&(-x);
    }
    ll query(int u, int kind) {
        ll ans = 0;
        while (u) {
            ans = (ans + data[u][kind]) % mod;
            u -= lowbit(u);
        }
        return ans;
    }
    void inc(int u, int kind, ll v) {
        while (u && u <= 100000) {
            data[u][kind] = (data[u][kind] + v) % mod;
            u += lowbit(u);
        }
    }
};
