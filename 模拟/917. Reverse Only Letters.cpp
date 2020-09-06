class Solution {
public:
    string reverseOnlyLetters(string S) {
        vector<char> all;
        const int N = S.size();
        for (int i = 0; i < N; i++) {
            if (isChar(S[i])) {
                all.push_back(S[i]);
            }
        }
        reverse(all.begin(), all.end());
        for (int i = 0, ptr = 0; i < N; i++) {
            if (isChar(S[i])) {
                S[i] = all[ptr++];
            }
        }
        return S;
    }
private:
    bool isChar(const char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};