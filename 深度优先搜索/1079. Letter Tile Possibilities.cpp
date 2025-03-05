class Solution {
public:
    int numTilePossibilities(string tiles) {
        string cur;
        dfs(tiles, cur, 0);
        return visited.size();
    }
private:
    unordered_set<string> visited;

    void dfs(const string& tiles, string& cur, int state) {
        const int n = tiles.size();
        if (state == (1 << n) - 1) {
            if (!cur.empty()) visited.insert(cur);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (state & (1 << j)) continue;

            cur += tiles[j];
            dfs(tiles, cur, state | (1 << j));
            cur.pop_back();

            dfs(tiles, cur, state | (1 << j));
        }
    }
};