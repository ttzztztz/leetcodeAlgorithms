class Solution {
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
    int strStr2(const char* source, const char* target) {
        if (source == nullptr || target == nullptr) return -1;

        P = string(target);
        T = string(source);
        
        if (P.empty()) return 0;
        
        lenT = T.size();
        lenP = P.size();
    
        nxt = vector<int>(lenP + 2, 0);
        build();
        return kmp();
    }
private:
    string P, T;
    vector<int> nxt;
    int lenT, lenP;
    
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
    
    int kmp() {
        int i = 0, j = 0;
    
        while (i < lenT) {
            if (j == -1 || T[i] == P[j]) {
                i++;
                j++;
            } else {
                j = nxt[j];
            }
    
            if (j == lenP) {
                return (i - j);
                j = nxt[j];
            }
        }
        
        return -1;
    }
};
