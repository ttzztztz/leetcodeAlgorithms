class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        this->n = matrix.size(), this->m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        vector<int> ind((n + 1) * (m + 1), 0);
        vector<vector<int>> edges((n + 1) * (m + 1), vector<int>{});
        memset(group, 0xff, sizeof group);
        
        init();
        for (int i = 0; i < n; i++) {
            unordered_map<int, vector<int>> hmap;
            for (int j = 0; j < m; j++) {
                hmap[matrix[i][j]].push_back(j);
            }
            
            for (auto& p : hmap) {
                auto& vec = p.second;
                for (int x = 1; x < vec.size(); x++) {
                    merge(id(i, vec[x]), id(i, vec[x - 1]));
                }
            }
        }
                
        for (int i = 0; i < m; i++) {
            unordered_map<int, vector<int>> hmap;
            for (int j = 0; j < n; j++) {
                hmap[matrix[j][i]].push_back(j);
            }
            
            for (auto& p : hmap) {
                auto& vec = p.second;
                for (int x = 1; x < vec.size(); x++) {
                    merge(id(vec[x], i), id(vec[x - 1], i));
                }
            }
        }
        
        unordered_set<int> all_group;
        for (int i = 0; i < n; i++) {
            map<int, int> ttl;
            for (int j = 0; j < m; j++) {
                ttl[matrix[i][j]] = fp(id(i, j));
                all_group.insert(fp(id(i, j)));
            }
            
            for (auto it1 = ttl.begin(), it2 = ++ttl.begin(); it2 != ttl.end(); it1++, it2++) {
                int g1 = it1->second, g2 = it2->second;
                edges[g1].push_back(g2);
                ind[g2]++;
            }
        }
        
        for (int i = 0; i < m; i++) {
            map<int, int> ttl;
            for (int j = 0; j < n; j++) {
                ttl[matrix[j][i]] = fp(id(j, i));
                all_group.insert(fp(id(j, i)));
            }
            
            for (auto it1 = ttl.begin(), it2 = ++ttl.begin(); it2 != ttl.end(); it1++, it2++) {
                int g1 = it1->second, g2 = it2->second;
                edges[g1].push_back(g2);
                ind[g2]++;
            }
        }
        
        deque<int> q;
        unordered_map<int, int> tmp;
        int cur = 1;
        for (int g : all_group) {
            if (ind[g] == 0) q.push_back(g);
        }
        
        while (!q.empty()) {
            int cnt = q.size();
            
            for (int _ = 0; _ < cnt; _++) {
                int g = q.front();
                q.pop_front();
                
                tmp[g] = cur;
                for (int k : edges[g]) {
                    ind[k]--;
                    if (ind[k] == 0) q.push_back(k);
                }
            }
            
            cur++;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memo[fp(id(i, j))].emplace_back(i, j);
            }
        }
        
        
        for (auto [group, idx] : tmp) {
            for (auto [x, y] : memo[group]) {
                ans[x][y] = idx;
            }
        }
        
        return ans;
    }
private:
    typedef pair<int, int> Point;
    unordered_map<int, vector<Point>> memo;
    int group[505][505];
    int parent[250005];
    
    void init() {
        for (int i = 0; i <= n * m; i++) {
            parent[i] = i;
        }
    }
    int fp(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = fp(parent[u]);
    }
    void merge(int u, int v) {
        const int pu = fp(u), pv = fp(v);
        if (parent[pu] != pv) {
            parent[pu] = pv;
        }
    }
    
    int idx = 0;
    
    int n, m;
    int id(int i, int j) {
        return i * m + j;
    }
};
