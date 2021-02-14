bool edg[200000];
int ind[401];

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        memset(ind, 0, sizeof ind);
        memset(edg, 0, sizeof edg);

        for (auto& e : edges) {
            edg[id(e[0], e[1])] = edg[id(e[1], e[0])] = true;
            ind[e[0]]++, ind[e[1]]++;
        }

        int ans = numeric_limits<int>::max();
        for (auto& e : edges) {
            const int u = e[0], v = e[1];
            for (int k = 1; k <= n; k++) {
                if (edg[id(v, k)] && edg[id(u, k)]) {
                    ans = min(ans, ind[u] + ind[v] + ind[k] - 6);
                }
            }
        }
        
        if (ans == numeric_limits<int>::max()) return -1;
        else return ans;
    }
private:
    int id(int u, int v) {
        return u * 401 + v;
    }
};
