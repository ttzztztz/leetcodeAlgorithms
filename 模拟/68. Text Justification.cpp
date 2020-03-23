class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> answer;
        const int N = words.size();
        
        vector<int> stk;
        int stkLen = 0;
        
        for (int i = 0; i < N; i++) {
            if (stkLen + words[i].size() + stk.size() > maxWidth) {
                answer.push_back(generate(words, stk, maxWidth, stkLen, false));
                stk.clear();
                stkLen = 0;
            }
            
            stk.push_back(i);
            stkLen += words[i].size();
        }
        
        if (!stk.empty()) answer.push_back(generate(words, stk, maxWidth, stkLen, true));
        
        return answer;
    }
private:
    string generate(const vector<string>& words, const vector<int> stk, const int maxWidth, const int allLen, bool isLast) {
        string answer;
        
        const int N = stk.size();
        
        if (N == 0) return answer;
        if (N == 1) {
            answer = words[stk[0]];
            while (answer.size() < maxWidth) answer += ' ';
            return answer;
        }
        
        if (isLast) {
            for (int i : stk) {
                answer += words[i];
                answer += ' ';
            }
            answer.pop_back();
            
            while (answer.size() < maxWidth) answer += ' ';
            return answer;
        }
        
        const int padding = (maxWidth - allLen) / (N - 1);
        int extra = (maxWidth - allLen) % (N - 1);
        
        for (int i = 0; i < N; i++) {
            answer += words[stk[i]];
            if (i != N - 1) {
                string add(padding, ' ');
                if (extra > 0) {
                    extra--;
                    add += ' ';
                }
                answer += add;
            }
        }
        
        while (answer.size() < maxWidth) answer += ' ';
        return answer;
    }
};
