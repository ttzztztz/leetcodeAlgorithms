class Solution {
public:
    int parent[100005];
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
        int parentU = findParent(u), parentV = findParent(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int N = s.size();

        init(N);
        for (const vector<int>& p : pairs) {
            merge(p[0], p[1]);
        }

        unordered_map<int, vector<int>> map;
        for (int i = 0; i < N; i++) {
            const int _parent = findParent(i);
            if (map.count(_parent)) {
                map[_parent].push_back(i);
            } else {
                map[_parent] = vector<int>{i};
            }
        }

        for (const pair<int, vector<int>>& p : map) {
            string temp;
            for (int _i : p.second) {
                temp.push_back(s[_i]);
            }
            sort(temp.begin(), temp.end());

            int ptr = 0;
            for (int _i : p.second) {
                s[_i] = temp[ptr];
                ptr++;
            }
        }

        return s;
    }
};