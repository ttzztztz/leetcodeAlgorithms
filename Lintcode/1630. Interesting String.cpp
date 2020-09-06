class Solution {
public:
    /**
     * @param s: the string s
     * @return: check if the string is interesting
     */
    string check(string &s) {
        if (check(s, 0)) return "yes";
        else return "no";
    }
private:
    bool check(const string& s, int start) {
        const int N = s.size();
        if (start == N) return true;
        if (start > N) return false;
        if (s[start] < '0' || s[start] > '9') return false;
        
        int number = 0, ptr = start;
        while (ptr < N && s[ptr] >= '0' && s[ptr] <= '9') {
            number *= 10;
            number += s[ptr] - '0';
            ptr++;
            
            if (check(s, ptr + number)) return true;
        }
        return false;
    }
};
