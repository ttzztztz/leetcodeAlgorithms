class Solution {
public:
    string freqAlphabets(string s) {
        string answer;
        const int N = s.size();
        int i = N - 1;
        while (i >= 0) {
            if (s[i] == '#') {
                const char ch1 = s[i - 1], ch2 = s[i - 2];
                string temp;
                temp += ch2, temp += ch1;
                int t = stoi(temp);
                answer.push_back('a' - 1 + t);
                i -= 3;
            } else {
                string temp;
                temp += s[i];
                int t = stoi(temp);
                answer.push_back('a' - 1 + t);
                i--;
            }
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
