class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        memset(data, 0, sizeof data);
        
        typedef long long ll;
        ll ans = 0;
        const int mod = 1e9+7;
        for (int i : instructions) {
            ans = (ans + min(query(i - 1), query(100000) - query(i))) % mod;
            inc(i, 1);
        }
        return ans;
    }
private:
    int data[100001];
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