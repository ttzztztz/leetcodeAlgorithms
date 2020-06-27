class Solution {
public:
    string toGoatLatin(string S) {
        string answer;
        int cnt = 1;
        stringstream ss(S);
        string tmp;
        
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (ss >> tmp) {
            if (cnt != 1) answer += " ";
            
            if (vowel.count(tmp[0])) tmp += "ma";
            else {
                const char ch = tmp[0];
                tmp.erase(tmp.begin());
                tmp += ch;
                tmp += "ma";
            }
            
            string other(cnt, 'a');
            tmp += other;
            answer += tmp;
            cnt++;
        }
        return answer;
    }
};
