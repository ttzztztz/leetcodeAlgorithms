iclass Solution {
public:
    string generateTheString(int n) {
        string answer;
        if (n % 2 == 0) {
            answer += 'a';
            string tmp(n - 1, 'b');
            answer += tmp;
        } else {
            string tmp(n, 'a');
            answer += tmp;
        }
        return answer;
    }
};
