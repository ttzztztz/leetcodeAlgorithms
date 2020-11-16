class Solution {
public:
    int numSteps(string s) {
        int answer = 0;
        while (s != "1") {
            if (s.back() == '1') { // odd
                int add = 1;
                for (int i = s.size() - 1; i >= 0; i--) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        add = 0;
                        break;
                    } else {
                        s[i] = '0';
                    }
                }
                if (add == 1) {
                    s = "1" + s;
                }
            } else { // even
                s.pop_back();
            }
            answer++;
        }
        return answer;
    }
};
