class Solution {
public:
    int countSubstrings(string s) {
        int answer = 0;
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            answer += extend(s, i, i);
            answer += extend(s, i, i + 1);
        }
        return answer;
    }
    int extend(const string& s, int i, int j) {
        int answer = 0;
        const int N = s.size();
        while (i >= 0 && j < N && s[i] == s[j]) {
            answer++;
            i--, j++;
        }
        return answer;
    }
};