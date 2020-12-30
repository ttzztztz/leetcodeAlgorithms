class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        const int n = words1.size(), m = words2.size();
        if (n != m) return false;
        
        for (const auto& p : pairs) {
            if (!word_idx.count(p[0])) {
                word_idx[p[0]] = word_cnt++;
            }
            if (!word_idx.count(p[1])) {
                word_idx[p[1]] = word_cnt++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!word_idx.count(words1[i])) {
                word_idx[words1[i]] = word_cnt++;
            }
            if (!word_idx.count(words2[i])) {
                word_idx[words2[i]] = word_cnt++;
            }
        }
        init(word_cnt);
        for (const auto& p : pairs) {
            merge(word_idx[p[0]], word_idx[p[1]]);
        }
        
        for (int i = 0; i < n; i++) {
            const int lhs = word_idx[words1[i]], rhs = word_idx[words2[i]];
            
            if (lhs != rhs && find_parent(lhs) != find_parent(rhs)) return false;
        }
        return true;
    }
private:
    unordered_map<string, int> word_idx;
    int word_cnt = 0;
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = find_parent(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = find_parent(u), pv = find_parent(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }
};
