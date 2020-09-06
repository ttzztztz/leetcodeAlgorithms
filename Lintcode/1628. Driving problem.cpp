class Solution {
public:
    /**
     * @param L: the length
     * @param W: the width
     * @param p:  the obstacle coordinates
     * @return: yes or no
     */
    string drivingProblem(int L, int W, vector<vector<double>> &p) {
        const int N = p.size(), top = N + 1, bottom = N + 2;
        init(N);
        
        for (int i = 0; i < N; i++) {
            const vector<double>& point = p[i];
            if (point[1] <= 5) merge(top, i);
            if (point[1] >= W - 5) merge(bottom, i);
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (distSquare(p[i], p[j]) <= 36.0 + 1e-6) merge(j, i);
            }
        }
        
        return findParent(top) == findParent(bottom) ? "no" : "yes";
    }
private:
    vector<int> parent;
    void init(int N) {
        parent = vector<int>(N + 5);
        for (int i = 0; i <= N + 3; i++) parent[i] = i;
    }
    int findParent(int u) {
        if (u == parent[u]) return u;
        else return findParent(parent[u]);
    }
    void merge(int u, int v) {
        const int pU = findParent(u), pV = findParent(v);
        if (pU != pV) {
            parent[pU] = pV;
        }
    }
    double distSquare(const vector<double>& $1, const vector<double>& $2) {
        return ($1[0] - $2[0]) * ($1[0] - $2[0]) + ($1[1] - $2[1]) * ($1[1] - $2[1]);
    }
};
