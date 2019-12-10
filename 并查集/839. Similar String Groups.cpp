class Solution {
public:
    int parent[2005];
    void init(int N) {
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            return parent[u] = findParent(parent[u]);
        }
    }
    void merge(int u, int v) {
        const int parentU = findParent(u), parentV = findParent(v);

        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }
    bool isSimilar(const string& $1, const string& $2) {
        int diff = 0, ptr = 0;
        const int N = $1.size();
        for (int i = 0; i < N; i++) {
            if ($1[i] != $2[i]) {
                diff++;
                if (diff >= 3) {
                    return false;
                }
            }
        }
        return diff == 2 || diff == 0;
    }
    int numSimilarGroups(vector<string>& A) {
        int answer = 0;
        const int N = A.size();
        init(N);

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isSimilar(A[i], A[j])) {
                    merge(i, j);
                }
            }
        }

        unordered_set<int> currentParent;
        for (int i = 0; i < N; i++) {
            const int _parent = findParent(i);
            if (!currentParent.count(_parent)) {
                answer++;
                currentParent.insert(_parent);
            }
        }

        return answer;
    }
};