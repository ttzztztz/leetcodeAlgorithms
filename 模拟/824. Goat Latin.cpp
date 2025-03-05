class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans, tmp;
        int cnt = 1;
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] != ' ') tmp += sentence[i];

            if (sentence[i] == ' ' || i == sentence.size() - 1) {
                if (!ans.empty()) ans += " ";
                ans += process(tmp, cnt);
                tmp.clear();
                cnt++;
            }
        }
        return ans;
    }
private:
    string process(string str, int idx) {
        char ch = str[0];
        if ('A' <= ch && ch <= 'Z') ch = ch - 'A' + 'a';

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            str += "ma";
        } else {
            const char ch =  str[0];
            str = str.substr(1) + ch + "ma";
        }

        string repeated_suffix(idx, 'a');
        return str + repeated_suffix;
    }
};