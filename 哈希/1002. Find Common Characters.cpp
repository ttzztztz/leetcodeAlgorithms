class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        const int N = A.size();
        vector<string> answer;
        
        unordered_map<char, int> app;
        unordered_map<char, int> singleApp;
        for (const string& str : A) {
            unordered_map<char, int> tmp;
            for (const char ch : str) tmp[ch]++;
            
            for (const auto& p : tmp) {
                singleApp[p.first]++;
                if (app.count(p.first)) {
                    app[p.first] = min(app[p.first], p.second);
                } else {
                    app[p.first] = p.second;
                }
            }
        }
        
        for (auto& p : singleApp) {
            if (p.second == N) {
                for (int k = 0; k < app[p.first]; k++) {
                    answer.push_back(string{p.first});
                }
            }
        }
        return answer;
    }
};