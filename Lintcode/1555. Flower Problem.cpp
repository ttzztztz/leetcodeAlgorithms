class Solution {
public:
    /**
     * @param flowers: an array
     * @param k: an integer
     * @param m: an integer
     * @return: the last day
     */
    int flowerProblem(vector<int> &flowers, int k, int m) {
        N = flowers.size();
        init();
        vector<bool> opened(N + 5, false);
        
        int answer = -1;
        multiset<int> allBloomed;
        for (int i = 0; i < N; i++) {
            const int x = flowers[i];
            
            int curSize = 1;
            if (opened[x - 1]) {
                const int s = size[findParent(x - 1)];
                
                curSize += s;
                allBloomed.erase(allBloomed.find(s));
                merge(x - 1, x);
            }
            
            if (opened[x + 1]) {
                const int s = size[findParent(x + 1)];
                
                curSize += s;
                allBloomed.erase(allBloomed.find(s));
                merge(x + 1, x);
            }
            
            allBloomed.insert(curSize);
            opened[x] = true;
            
            if (allBloomed.size() >= m) {
                int offset = allBloomed.size() - m;
                auto it = allBloomed.begin();
                advance(it, offset);
                
                if (*it >= k) answer = i + 1;
            }
        }
        
        return answer;
    }
private:
    vector<int> parent, size;
    int N;
    void init() {
        parent = size = vector<int>(N + 5, 0);
        for (int i = 0; i < N + 5; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
            size[pV] += size[pU];
        }
    }
    int findParent(int u) {
        if (u == parent[u]) return parent[u];
        else return parent[u] = findParent(parent[u]);
    }
};
