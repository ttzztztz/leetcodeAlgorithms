class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
        
        this->s = start, this->e = end;
        const int m = wordList.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (judge(wordList[i], wordList[j])) {
                    edges[wordList[i]].push_back(wordList[j]);
                    edges[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if (find(wordList.begin(), wordList.end(), start) == wordList.end()) {
            for (int j = 0; j < m; j++) {
                if (judge(start, wordList[j])) {
                    edges[start].push_back(wordList[j]);
                }
            }
        }
        
        if (find(wordList.begin(), wordList.end(), end) == wordList.end()) {
            return answer;
        }
        
        bfs();
        cur.push_back(start);
        dfs(start);
        return answer;
    }
private:
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> edges;
    vector<string> cur;
    
    string s, e;
    unordered_map<string, int> dist;
    
    void bfs() {
        dist[s] = 0;
        deque<string> q = {s};
        int d = 0;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                const string t = q.front();
                q.pop_front();
                
                for (const auto& nxt : edges[t]) {
                    if (dist.count(nxt)) continue;
                    
                    q.push_back(nxt);
                    dist[nxt] = d + 1;
                }
            }
            d++;
        }
    }
    
    void dfs(const string& str) {
        if (str == e) {
            answer.push_back(cur);
            return;
        }
        
        for (const string& s : edges[str]) {
            if (dist[s] == dist[str] + 1) {
                cur.push_back(s);
                dfs(s);
                cur.pop_back();
            }
        }
    }
    
    bool judge(const string& $1, const string& $2) {
        const int len1 = $1.size(), len2 = $2.size();
        if (len1 != len2) return false;
            
        bool used = false;
        for (int k = 0; k < len1; k++) {
            if ($1[k] != $2[k]) {
                if (used) return false;
                else used = true;
            }
        }
        
        return used;
    };
};
