class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        const int n = A.size();

        init(26);
        for (int i = 0; i < n; i++) {
            merge(A[i] - 'a', B[i] - 'a');
        }
        
        for (size_t i = 0; i < S.size(); i++) {
            for (int j = 0; j < S[i] - 'a'; j++) {
                if (find_parent(S[i] - 'a') == find_parent(j)) {
                    S[i] = 'a' + j;
                    break;
                }
            }
        }
        return S;
    }
private:
    vector<int> parent;
    void init(int n) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
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
