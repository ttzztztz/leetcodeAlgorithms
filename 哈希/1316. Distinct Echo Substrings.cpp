class Solution {
public:
    bool check(const string& text) {
        const int N = text.size();
        if (N % 2 == 1) return false;
        
        for (int i = 0; i < (N / 2); i++) {
            if (text[i] != text[i + N / 2]) return false;
        }
        
        return true;
    }
    int distinctEchoSubstrings(string text) {
        int answer = 0;
        const int N = text.size();
        
        for (int len = 2; len <= N; len += 2) {
            unordered_set<string> visited;
            string curr;
            for (int i = 0; i + len - 1 < N; i++) {
                if (i == 0) {
                    curr = text.substr(i, len);
                } else {
                    curr.erase(curr.begin());
                    curr.push_back(text[i + len - 1]);
                }
                if (!visited.count(curr) && check(curr)) {
                    visited.insert(curr);
                    answer++;
                }
            }
            visited.clear();
        }
        
        return answer;
    }
};
