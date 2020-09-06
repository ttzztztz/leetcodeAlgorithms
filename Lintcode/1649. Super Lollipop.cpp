class Solution {
public:
    /**
     * @param v1: the speed of GGbond
     * @param v2: the speed of SuperQ
     * @param s: the speed that lollipop can add
     * @param w: the cost of lollipop
     * @return: the minimal price
     */
    int getAns(int v1, int v2, vector<int> &s, vector<int> &w) {
        if (v1 > v2) return 0;
        const int d = v2 - v1;
        
        int answer = 9999999;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > d) {
                answer = min(answer, w[i]);
            }
        }
        return answer;
    }
};
