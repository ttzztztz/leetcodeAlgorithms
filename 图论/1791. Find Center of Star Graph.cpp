class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<ll> visited;
        unordered_set<int> points;
        vector<int> ind(100001, 0);
        for (auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            const ll h = hash(u, v);
            if (!visited.count(h)) {
                visited.insert(h);
                
                ind[u]++;
                ind[v]++;
                points.insert(u);
                points.insert(v);
            }
        }
        
        const int m = points.size();
        for (int i : points) {
            // cout << m << ", " << i << ", " << ind[i] << endl;
            if (ind[i] == m - 1) return i;
        }
        cout << endl;
        
        return -1; // never
    }
private:
    typedef long long ll;
    ll hash(int a, int b) {
        if (a > b) swap(a, b);
        const ll maxn = 1e5+2;
        return 1ll * maxn * a + b;
    }
};
