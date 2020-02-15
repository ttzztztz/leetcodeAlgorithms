class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        graph = vector<vector<int>>(26, vector<int>{});
        inDegree = vector<int>(26, 0);
        
        unordered_set<char> allChars;
        for (int i = 0; i < words.size() - 1; i++) {
            const string& $1 = words[i], $2 = words[i + 1];
            allChars.insert($1.begin(), $1.end());
            allChars.insert($2.begin(), $2.end());
            for (int j = 0; j < min($1.size(), $2.size()); j++) {
                if ($1[j] != $2[j]) {
                    addEdge($1[j], $2[j]);
                    break;
                }
            }
        }
        
        for (int i = 0; i < 26; i++) sort(graph[i].begin(), graph[i].end());
        
        deque<int> queue;
        vector<int> zero;
        
        for (int i = 0; i < 26; i++) {
            if (allChars.count(i + 'a') && inDegree[i] == 0) {
                if (graph[i].empty()) {
                    zero.push_back(i);
                } else {
                    queue.push_back(i);
                }
            }
        }
        
        while (!queue.empty()) {
            const int u = queue.front();
            queue.pop_front();
            answer.push_back(u + 'a');
            
            for (int v : graph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue.push_back(v);
                }
            }
        }
        
        for (int i = 0; i < zero.size(); i++) {
            const char ch = zero[i] + 'a';
            int ptr = 0;
            while (ptr < answer.size()) {
                if (ch > answer[ptr]) {
                    ptr++;
                } else {
                    break;
                }
            }
            answer.insert(answer.begin() + ptr, ch);
        }
        
        if (answer.size() < allChars.size()) {
            return "";
        } else {
            return answer;
        }
    }
private:
    vector<vector<int>> graph;
    vector<int> inDegree;
    string answer;
    void addEdge(char s, char e) {
        graph[s - 'a'].push_back(e - 'a');
        inDegree[e - 'a']++;
    }
};
