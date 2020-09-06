class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char, int> app;
        unordered_set<char> visited;
        for (const char ch : text) app[ch]++;
        
        string answer;
        const int N = text.size();
        for (int i = 0; i < N; i++) {
            app[text[i]]--;
            if (visited.count(text[i])) {
                continue;
            }
            
            while (!answer.empty() && answer.back() > text[i] && app[answer.back()] > 0) {
                const char g = answer.back();
                answer.pop_back();
                visited.erase(g);
            }
            
            visited.insert(text[i]);
            answer.push_back(text[i]);
        }
        
        return answer;
    }
};
