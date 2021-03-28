class Solution {
public:
    int numDifferentIntegers(string word) {
        string t;
        unordered_set<string> visited;
        
        auto add = [&]() -> void {
            while (t.size() > 1 && *t.begin() == '0') t.erase(t.begin());
            if (!t.empty()) {
                if (!visited.count(t)) {
                    visited.insert(t);
                }
            }
            t.clear();
        };
        
        for (const char ch : word) {
            if ('0' <= ch && ch <= '9') {
                t += ch;
            } else {
                add();
            }
        }
        add();
        return visited.size();
    }
};
