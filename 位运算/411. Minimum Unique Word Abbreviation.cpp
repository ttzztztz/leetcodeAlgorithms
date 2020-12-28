class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        const int n = target.size();
        unordered_set<int> bitset;
        for (const string& word : dictionary) {
            if (word.size() != target.size()) continue;
            bitset.insert(str_difference(target, word));
        }
        
        string ans;
        for (int state = 0; state < (1 << n); state++) {
            bool valid = true;
            for (const int j : bitset) {
                if ((state & j) == state) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            
            const int cur_size = str_len(target, state);
            if (ans.empty() || cur_size < ans.size()) {
                ans = str_generate(target, state);
            }
        }
        return ans;
    }
private:
    int str_difference(const string& target, const string& word) {
        int state = 0;
        const int n = target.size();
        for (int j = 0; j < n; j++) {
            if (word[j] == target[j]) {
                state |= (1 << j);
            }
        }
        return state;
    }
    
    int len(int hidden) {
        int ans = 0;
        while (hidden) {
            ans++;
            hidden /= 10;
        }
        return ans;
    }
    
    int str_len(const string& target, const int state) {
        int ans = 0;
        
        int hidden = 0;
        const int n = target.size();
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) {
                if (hidden > 0) ans += len(hidden);
                ans ++;
                hidden = 0;
            } else {
                hidden++;
            }
        }
        if (hidden > 0) ans += len(hidden);
        
        return ans;
    }
    
    string str_generate(const string& target, const int state) {
        string ans;
        
        int hidden = 0;
        const int n = target.size();
        for (int i = 0; i < n; i++) {
            if (state & (1 << i)) {
                if (hidden > 0) ans += to_string(hidden);
                ans += target[i];
                hidden = 0;
            } else {
                hidden++;
            }
        }
        if (hidden > 0) ans += to_string(hidden);
        
        return ans;
    }
};
