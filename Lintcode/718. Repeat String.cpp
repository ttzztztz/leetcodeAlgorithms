class Solution {
public:
    /**
     * @param A: string A to be repeated
     * @param B: string B
     * @return: the minimum number of times A has to be repeated
     */
    int repeatedString(string &A, string &B) {
        if (A.empty()) return -1;
        string tmp = A;
        
        int answer = 1;
        while (tmp.size() < B.size()) {
            tmp += A;
            answer++;
        }
        
        if (tmp.find(B) != string::npos) return answer;
        if ((tmp + A).find(B) != string::npos) return answer + 1;
        
        return -1;
    }
};
