class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        deg = vector<int>(n, 0);
        for (auto& road : roads) {
            deg[road[0]]++, deg[road[1]]++;
            connected.insert(hash(road[0], road[1]));
        }
        
        int ans = 0;
        for (int u = 0; u < n; u++) for (int v = u + 1; v < n; v++) {
            int t = deg[u] + deg[v];
            if (connected.count(hash(u, v))) t--;
            ans = max(ans, t);
        }
        return ans;
    }
private:
    vector<int> deg;
    unordered_set<string> connected;
    
    string hash(int a, int b) {
        if (a > b) swap(a, b);
        return to_string(a) + "," + to_string(b);
    }
};