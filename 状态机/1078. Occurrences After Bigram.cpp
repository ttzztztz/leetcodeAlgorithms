class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string tmp;
        vector<string> answer;
        const int N = text.size();
        int state = 0;
        for (int i = 0; i <= N; i++) {
            if (text[i] == ' ' || i == N) {
                if (state == 0) {
                    if (tmp == first) state = 1;
                    else state = 0;
                } else if (state == 1) {
                    if (tmp == second) state = 2;
                    else if (tmp == first) state = 1;
                    else state = 0;
                } else if (state == 2) {
                    answer.push_back(tmp);
                    if (tmp == first) state = 1;
                    else state = 0;
                }
                tmp.clear();
            } else {
                tmp.push_back(text[i]);
            }
        }
        return answer;
    }
};
