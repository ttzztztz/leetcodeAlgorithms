class Solution {
public:
    /**
     * @param words1: 
     * @param words2: 
     * @param pairs: 
     * @return: Whether sentences are similary or not?
     */
    bool areSentencesSimilarTwo(vector<string> &words1, vector<string> &words2, vector<vector<string>> &pairs) {
        const int N = words1.size(), M = words2.size();
        if (N != M) return false;
        init(N);
        
        unordered_map<string, int> mapStringToID;
        int cnt = 0;
        for (const vector<string>& p : pairs) {
            if (!mapStringToID.count(p[0])) mapStringToID[p[0]] = cnt++;
            if (!mapStringToID.count(p[1])) mapStringToID[p[1]] = cnt++;
            
            merge(mapStringToID[p[0]], mapStringToID[p[1]]);
        }
        
        for (int i = 0; i < N; i++) {
            if (words1[i] == words2[i]) continue;
            
            if (!mapStringToID.count(words1[i]) || !mapStringToID.count(words2[i])) return false;
            
            if (findParent(mapStringToID[words1[i]]) != findParent(mapStringToID[words2[i]])) return false;
        }
        return true;
    }
private:
    vector<int> parent;
    void init(int N) {
        parent = vector<int>(2 * N + 5);
        for (int i = 0; i <= 2 *N + 2; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (parent[u] == u) return u;
        else return parent[u] = findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
        }
    }
};
