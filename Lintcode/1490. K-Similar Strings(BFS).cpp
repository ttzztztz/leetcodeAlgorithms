class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: the smallest K for which A and B are K-similar
     */
    int kSimilarity(string &A, string &B) {
        if (A == B) return 0;
        const int N = A.size();
        
        unordered_set<string> visited;
        int answer = 0;
        deque<string> q;
        q.push_back(A);
        while (!q.empty()) {
            int cnt = q.size();
            
            for (int _ = 0; _ < cnt; _++) {
                string cur = q.front();
                q.pop_front();
                
                int i = 0;
                while (cur[i] == B[i]) i++;

                for (int j = i + 1; j < N; j++) {
                    if (cur[i] == B[j] && cur[j] != B[j]) {
                        swap(cur[i], cur[j]);
                        if (!visited.count(cur)) {
                            visited.insert(cur);
                            q.push_back(cur);
                        }
                        if (cur == B) return answer + 1;
                        swap(cur[i], cur[j]);
                    }
                }
            }
            answer++;
        }
        return -1;
    }
};
