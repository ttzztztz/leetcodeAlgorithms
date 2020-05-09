class Solution {
public:
    string Combine(vector<int>& digits) {
        vector<string> dig;
        for (auto& i : digits) dig.push_back(to_string(i));
        sort(dig.begin(), dig.end(), [](const auto& $1, const auto& $2) -> bool {
            return $1 + $2 > $2 + $1;
        });
        
        int m = 0;
        for (const string& s : dig) m += mod(s);
        m %= 3;
        
        if (m == 0) return concat(dig, 0, dig.size() - 1);
        else if (m == 1) { // remove 1 * 1 || 2 * 2
            string answer;
            for (int i = 0; i < dig.size(); i++) {
                const string& s = dig[i];
                const int t = mod(s);
                
                if (t == 1) {
                    answer = cmpMax(answer, concat(dig, 0, i - 1) + concat(dig, i + 1, dig.size() - 1));
                }
            }
            
            for (int i = 0; i < dig.size(); i++) {
                for (int j = i + 1; j < dig.size(); j++) {
                    const string& s1 = dig[i], s2 = dig[j];
                    const int t1 = mod(s1), t2 = mod(s2);
                    
                    if (t1 == 2 && t2 == 2) {
                        answer = cmpMax(answer, concat(dig, 0, i - 1) + concat(dig, i + 1, j - 1) + concat(dig, j + 1, dig.size() - 1));
                    }
                    
                }
            }
            
            return answer;
        } else if (m == 2) { // remove 1 * 2 || 2 * 1
            string answer;
            for (int i = 0; i < dig.size(); i++) {
                const string& s = dig[i];
                const int t = mod(s);
                
                if (t == 2) {
                    answer = cmpMax(answer, concat(dig, 0, i - 1) + concat(dig, i + 1, dig.size() - 1));
                }
            }
            
            for (int i = 0; i < dig.size(); i++) {
                for (int j = i + 1; j < dig.size(); j++) {
                    const string& s1 = dig[i], s2 = dig[j];
                    const int t1 = mod(s1), t2 = mod(s2);
                    
                    if (t1 == 1 && t2 == 1) {
                        answer = cmpMax(answer, concat(dig, 0, i - 1) + concat(dig, i + 1, j - 1) + concat(dig, j + 1, dig.size() - 1));
                    }
                    
                }
            }
            return answer;
        }
        
        return "";
    }
private:
    string concat(const vector<string>& s, int i, int j) {
        string answer;
        if (i > j) return "";
        
        for (int k = i; k <= j; k++) answer += s[k];
        return answer;
    }
    int mod(const string& s) {
        int i = 0;
        for (const char ch : s) i += ch - '0';
        return i % 3;
    }
    string cmpMax(const string& $1, const string& $2) {
        if ($1.size() == $2.size()) return $1 > $2 ? $1 : $2;
        else return $1.size() > $2.size() ? $1 : $2;
    }
};
