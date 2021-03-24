class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        this->P = s;
        this->lenP = s.size();
        
        nxt = vector<int>(lenP + 5, 0);
        build();
        
        if (nxt[lenP] == 0) return false;
        const int repeat = lenP - nxt[lenP];
        return lenP % repeat == 0;
    }
private:
    string P;
    vector<int> nxt;
    int lenP;

    void build() {
        nxt[0] = -1;
        nxt[1] = 0;

        int j = 0, i = 1;
        while (i < lenP) {
            if (j == -1 || P[i] == P[j]) {
                nxt[++i] = ++j;
            } else {
                j = nxt[j];
            }
        }
    }
};