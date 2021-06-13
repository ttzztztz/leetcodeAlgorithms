class Solution {
public:
    vector<int> earliestAndLatest(int n, int fp, int sp) {
        this->n = n, this->fp = fp, this->sp = sp;
        string init(n, 'x');
        init[fp - 1] = 'f', init[sp - 1] = 's';
        
        int mi = numeric_limits<int>::max() / 2, ma = numeric_limits<int>::min() / 2;
        unordered_set<string> visited = { init };
        deque<string> q = { init };
        int round = 1;
        while (!q.empty()) {
            const int cnt = q.size();
            for (int _ = 0; _ < cnt; _++) {
                auto u = q.front();
                q.pop_front();
                
                // cout << u << endl;
                if (is_final(u)) {
                    // cout << "ok" << u << endl;
                    mi = min(mi, round);
                    ma = max(ma, round);
                    continue;
                }
                
                vector<string> next_states = generate(u);
                for (auto& v : next_states) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push_back(v);
                    }
                }
            }
            round++;
        }
        
        return { mi, ma };
    }
private:
    int n, fp, sp;
    
    vector<string> generate(const string& str) {
        if (str.size() <= 2) return {};
        vector<string> ans;
        
        const int m = str.size();
        if (m % 2 == 1) ans = { string{ str[m / 2] } };
        else ans = { "" };
        
        for (int i = (m / 2) - 1, j = (m % 2 == 0) ? (m / 2) : (m / 2 + 1); i >= 0 && j < m; i--, j++) {
            string vs{ str[i], str[j] };
            vector<string> na;
            for (const string& prev : ans) {
                if (str[i] == 's' || str[i] == 'f') {
                    na.push_back(str[i] + prev);
                } else if (str[j] == 's' || str[j] == 'f') {
                    na.push_back(prev + str[j]);
                } else {
                    na.push_back(str[i] + prev);
                    na.push_back(prev + str[j]);
                }
            }
            ans = na;
        }
        return ans;
    }
    
    bool is_final(const string& str) {
        const int m = str.size();
        for (int i = (m / 2) - 1, j = (m % 2 == 0) ? (m / 2) : (m / 2 + 1); i >= 0 && j < m; i--, j++) {
            // if (str.size() == 3) cout << "final" << i << ","<<j<< endl;
            
            string vs{ str[i], str[j] };
            if (vs == "fs" || vs == "sf") return true;
        }
        return false;
    }
};