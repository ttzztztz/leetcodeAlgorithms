class Solution {
public:
    string thousandSeparator(int n) {
        string x = to_string(n);
        string answer;
        for (int i = x.size() - 1, j = 0; i >= 0; i--, j++) {
            if (j % 3 == 0 && i != x.size() - 1) answer.push_back('.');
            answer.push_back(x[i]);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
