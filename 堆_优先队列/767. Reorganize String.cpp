class Solution {
public:
    /**
     * @param S: a string
     * @return: return a string
     */
    string reorganizeString(string &S) {
        unordered_map<char, int> f;
        for (const char ch : S) f[ch]++;
        
        typedef pair<int, char> PIC;
        priority_queue<PIC, vector<PIC>, less<>> heap;
        for (auto& p : f) {
            heap.emplace(p.second, p.first);
        }
        
        string ans;
        while (!heap.empty()) {
            const int cnt = min((int) heap.size(), 2);
            vector<PIC> nxt;
            for (int _ = 0; _ < cnt; _++) {
                int app;
                char ch;
                tie(app, ch) = heap.top();
                heap.pop();
                
                if (!ans.empty() && ans.back() == ch) return "";
                ans += ch;
                if (app > 1) nxt.emplace_back(app - 1, ch);
            }
            for (auto& p : nxt) heap.emplace(p);
        }
        
        return ans;
    }
};
