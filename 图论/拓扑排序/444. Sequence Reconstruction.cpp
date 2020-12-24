class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (org.size() == 1) {
            if (seqs.empty()) return false;
            
            const vector<int> kSeq = { org[0] };
            for (auto& seq : seqs) {
                if (seq != kSeq) return false;
            }
            return true;
        }
        
        vector<int> constructed;
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> edges;
        
        unordered_set<int> org_appear(org.begin(), org.end());
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); i++) {
                if (!org_appear.count(seq[i])) return false;
            }

            for (int i = 1; i < seq.size(); i++) {
                const int u = seq[i - 1], v = seq[i];
                
                edges[u].push_back(v);
                indegree[v]++;
                if (!indegree.count(u)) indegree[u] = 0;
            }
        }
        
        deque<int> q;
        for (auto [u, ind] : indegree) {
            if (ind == 0) q.push_back(u);
        }
        
        while (!q.empty()) {
            if (q.size() != 1) return false;
            const int u = q.front();
            constructed.push_back(u);
            q.pop_front();
            
            for (int v : edges[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push_back(v);
            }
        }
        
        return constructed == org;
    }
};