class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> edges;
        unordered_map<char, int> indeg;
        const int n = words.size();
        
        for (const string& word : words) {
            for (const char ch : word) {
                indeg[ch] = 0;
            }
        }
        
        for (int i = 1; i < n; i++) {
            bool diff = false;
            for (int j = 0; j < min(words[i].size(), words[i - 1].size()); j++) {
                if (words[i][j] != words[i - 1][j]) {
                    edges[words[i - 1][j]].push_back(words[i][j]);
                    indeg[words[i][j]]++;
                    diff = true;
                    break;
                }
            }
            
            if (!diff && words[i - 1].size() > words[i].size()) return "";
        }
        
        string ans;
        deque<char> q;
        for (auto [ch, appear] : indeg) {
            if (appear == 0) q.push_back(ch);
        }
        
        while (!q.empty()) {
            const char u = q.front();
            q.pop_front();
            ans += u;
            
            for (char v : edges[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push_back(v);
            }
        }
        
        if (ans.size() != indeg.size()) return "";
        else return ans;
    }
};
