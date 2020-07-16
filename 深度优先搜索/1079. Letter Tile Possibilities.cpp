class Solution {
public:
    int numTilePossibilities(string tiles) {
        N = tiles.size();
        used = vector<bool>(N, false);
        
        dfs(tiles);
        return visited.size();
    }
private:
    unordered_set<string> visited;
    
    vector<bool> used;
    string tmp;
    int N;
    
    void dfs(string& tiles) {
        if (!tmp.empty()) visited.insert(tmp);
        
        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                used[i] = true;
                tmp += tiles[i];
                dfs(tiles);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }
};