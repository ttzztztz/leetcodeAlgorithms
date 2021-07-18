class Solution {
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        q = queries.size(), n = parents.size();
        ans = vector<int>(q, 0), ord = vector<int>(n + 1, 0);
        edges = vector<vector<int>>(n + 1);
        troot = new TrieNode();
        
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1) root = i;
            else edges[parents[i]].push_back(i);
        }
        que = queries;
        for (int i = 0; i < q; i++) {
            que[i].push_back(i);
        }

        dfs1(root, -1);
        sort(que.begin(), que.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return ord[lhs[0]] < ord[rhs[0]];
        });
        dfs2(root, -1);
        
        return ans;
    }
private:
    vector<int> ans, ord;
    int q, n, root, id = 0, ptr = 0;
    vector<vector<int>> edges, que;
    
    void dfs1(int u, int parent) {
        ord[u] = ++id;

        for (int v : edges[u]) {
            if (v == parent) continue;
            dfs1(v, u);
        }
    }
    
    void dfs2(int u, int parent) {
        insert(u);
        while (ptr < q && ord[que[ptr][0]] < ord[u]) ptr++;
        while (ptr < q && que[ptr][0] == u) {
            solve(u, que[ptr][1], que[ptr][2]);
            ptr++;
        }

        for (int v : edges[u]) {
            if (v == parent) continue;
            dfs2(v, u);
        }
        remove(u);
    }

    class TrieNode {
    public:
        TrieNode* nxt[2];
        int cnt = 0;
        TrieNode() {
            memset(nxt, 0, sizeof nxt);
        }
    };
    
    TrieNode* troot;
    void insert(int val) {
        TrieNode* cur = troot;
        cur->cnt++;
        for (int j = 31; j >= 0; j--) {
            const int nxt = (val & (1 << j)) ? 1 : 0;
            
            if (cur->nxt[nxt] == nullptr) cur->nxt[nxt] = new TrieNode();
            cur = cur->nxt[nxt];
            cur->cnt++;
        }
    }
    
    void remove(int val) {
        TrieNode* cur = troot;
        cur->cnt--;
        for (int j = 31; j >= 0; j--) {
            const int nxt = (val & (1 << j)) ? 1 : 0;

            cur = cur->nxt[nxt];
            cur->cnt--;
        }
    }
    
    void solve(int u, int val, int qid) {
        TrieNode* cur = troot;
        int v = 0;
        for (int j = 31; j >= 0 && cur; j--) {
            const int a = (val & (1 << j)) ? 1 : 0;
            
            if (cur->nxt[a ^ 1] && cur->nxt[a ^ 1]->cnt > 0) {
                v |= 1 << j;
                cur = cur->nxt[a ^ 1];
            } else {
                cur = cur->nxt[a];
            }
        }
        ans[qid] = v;
    }
};