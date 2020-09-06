class Solution {
public:
    string toLowerCase(string str) {
        for (char& ch : str) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'a' + ch - 'A';
            }
        }
        
        return str;
    }
};
