class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> nxt;
        unordered_set<string> used;
        const int N = names.size();
        vector<string> answer;
        
        for (const string& name : names) {
            if (!used.count(name)) {
                answer.push_back(name);
                used.insert(name);
            } else {
                int n = nxt[name] + 1;
                while (used.count(name + "(" + to_string(n) + ")")) {
                    n++;
                }
                nxt[name] = n;
                used.insert(name + "(" + to_string(n) + ")");
                answer.push_back(name + "(" + to_string(n) + ")");
            }
        }
        
        return answer;
    }
};
