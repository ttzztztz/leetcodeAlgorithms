class Solution {
public:
    int numTeams(vector<int>& rating) {
        memset(data, 0, sizeof data);
        
        int ans = 0;
        const int n = rating.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // x < i < j, rx < ri < rj || rx > ri > rj
                
                if (rating[i] < rating[j]) ans += query(rating[i] - 1);
                if (rating[i] > rating[j]) ans += query(100000) - query(rating[i]);
            }
            inc(rating[i], 1);
        }
        return ans;
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