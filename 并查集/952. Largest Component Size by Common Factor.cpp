class Solution {
public:
    int parent[20005], size[20005], answer;
    void init(int N) {
        for (int i = 0; i <= N; i++) {
            parent[i] = i;
            size[i] = 1;
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
            size[parentV] += size[parentU];
            answer = max(answer, size[parentV]);
        }
    }
    int largestComponentSize(vector<int>& A) {
        answer = 0;
        const int N = A.size();
        init(N);

        unordered_map<int, int> id;
        unordered_map<int, bool> visited;
        int maxNumber = 0;

        for (int i = 0; i < A.size(); i++) {
            id[A[i]] = i;
            maxNumber = max(maxNumber, A[i]);
        }

        for (int i = 2; i <= maxNumber; i++) {
            int find = -1;
            if (visited[i]) {
                continue;
            }

            for (int k = i; k <= maxNumber; k += i) {
                if (id.count(k)) {
                    if (find == -1) {
                        find = id[k];
                    } else {
                        merge(find, id[k]);
                    }
                }
                visited[k] = true;
            }
        }

        return answer;
    }
};