class Solution {
public:
    /**
     * @param A: a string array
     * @return: the number of groups 
     */
    int numSimilarGroups(vector<string> &A) {
        const int N = A.size();
        init(N);
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isOK(A[i], A[j])) merge(i, j);
            }
        }
        
        unordered_set<int> all;
        for (int i = 0; i < N; i++) all.insert(findParent(i));
        return all.size();
    }
private:
    bool isOK(const string& s1, const string& s2) {
        const int N = s1.size();
        
        int diff = 0;
        for (int i = 0; i < N; i++) {
            if (s1[i] != s2[i]) diff++;
            if (diff >= 3) break;
        }
        
        return diff == 0 || diff == 2;
    }
    vector<int> parent;
    void init(int N) {
        parent = vector<int>(N + 5);
        for (int i = 0; i <= N; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (u == parent[u]) return parent[u];
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) parent[pU] = pV;
    }
};
