class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> appear;
        unordered_set<string> ban;
        for (const auto& str : banned) ban.insert(str);
        
        string answer;
        int mxcnt = 0;
        
        stringstream ss(paragraph);
        string tmp;
        while (ss >> tmp) {
            vector<string> splited = split(tmp);
            
            for (string s : splited) {
                s = transform(s);
                if (ban.count(s)) continue;
                appear[s]++;
                if (appear[s] > mxcnt) answer = s, mxcnt = appear[s];
            }
        }
        return answer;
    }
private:
    bool islower(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    bool isupper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    string transform(const string& str) {
        string answer;
        
        for (int i = 0; i < str.size(); i++) {
            if (isupper(str[i])) answer += (str[i] - 'A' + 'a');
            else if (islower(str[i])) answer += str[i];
        }
        
        return answer;
    }
    vector<string> split(const string& str) {
        vector<string> answer;
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if (!isupper(str[i]) && !islower(str[i])) {
                answer.push_back(tmp);
                tmp.clear();
            } else {
                tmp += str[i];
            }
        }
        
        if (!tmp.empty()) answer.push_back(tmp);
        return answer;
    }
};