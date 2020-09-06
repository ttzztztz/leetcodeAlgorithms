class Solution {
public:
    string addBinary(string a, string b) {
        string answer;
        if (a.size() > b.size()) swap(a, b); // make size(b) > size(a)
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int extra = 0;
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            int x = a[i] - '0', y = b[i] - '0';
            int nxt = x + y + extra;
            if (nxt >= 2) {
                extra = 1;
                nxt -= 2;
            } else {
                extra = 0;
            }
            answer.push_back(nxt + '0');
        }
        
        for (int i = min(a.size(), b.size()); i < b.size(); i++) {
            int y = b[i] - '0';
            int nxt = y + extra;
            if (nxt >= 2) {
                extra = 1;
                nxt -= 2;
            } else {
                extra = 0;
            }
            answer.push_back(nxt + '0');
        }
        if (extra) answer.push_back('1');
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
