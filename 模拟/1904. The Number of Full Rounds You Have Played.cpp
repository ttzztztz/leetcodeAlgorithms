class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int h1 = stoi(startTime.substr(0, 2)), m1 = stoi(startTime.substr(3));
        int h2 = stoi(finishTime.substr(0, 2)), m2 = stoi(finishTime.substr(3));
        
        if (make_pair(h1, m1) > make_pair(h2, m2)) h2 += 24;
        while (m1 % 15 != 0) {
            m1++;
            if (m1 >= 60) {
                h1++, m1 -= 60;
            }
        }
        while (m2 % 15 != 0) {
            m2--;
            if (m2 < 0) {
                h2--, m2 += 60;
            }
        }
        
        int ans = 0;
        while (make_pair(h1, m1) < make_pair(h2, m2)) {
            ans++;
            m1 += 15;
            if (m1 >= 60) m1 -= 60, h1++;
        }
        return ans;
    }
};
