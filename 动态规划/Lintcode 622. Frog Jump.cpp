class Solution {
public:
    /**
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     */
    bool canCross(vector<int> &stones) {
        sort(stones.begin(), stones.end());
        for (int i = 0; i < stones.size(); i++) g[stones[i]] = i;
        
        return dfs(stones, 0, 0);
    }
private:
    unordered_map<int, int> f[1200];
    unordered_map<int, int> g;
    
    int dfs(const vector<int> &stones, int i, int last) {
        if (f[i].count(last)) return f[i][last];
        if (i == stones.size() - 1) return 1;
        
        int answer = 0;
        if (i == 0) {
            if (stones[1] == 1) answer |= dfs(stones, i + 1, 1);
        } else {
            int nxt = stones[i] + last - 1;
            if (last >= 2 && g.count(nxt)) answer |= dfs(stones, g[nxt], last - 1);
            
            nxt++;
            if (last >= 1 && g.count(nxt)) answer |= dfs(stones, g[nxt], last);
            
            nxt++;
            if (last >= 0 && g.count(nxt)) answer |= dfs(stones, g[nxt], last + 1);
        }
        
        return f[i][last] = answer;
    }
};
