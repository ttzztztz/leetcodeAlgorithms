class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        const int N = start.size();
        
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(end)) return 0;
        
        deque<string> q;
        unordered_set<string> visited;
        q.push_back(start);
        int cur = 1;
        while (!q.empty()) {
            const int Q = q.size();
            for (int _ = 0; _ < Q; _++) {
                string state = q.front();
                q.pop_front();
                
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < 26; j++) {
                        if (state[i] == 'a' + j) continue;
                        const char before = state[i];
                        state[i] = 'a' + j;
                        if (!visited.count(state)) {
                            visited.insert(state);
                            if (dict.count(state)) q.push_back(state);
                            if (state == end) {
                                return cur + 1;
                            }
                        }
                        state[i] = before;
                    }
                }
            }
            cur++;
        }
        
        return 0;
    }
};
