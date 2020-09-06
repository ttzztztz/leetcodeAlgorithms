iclass Solution {
public:
    bool backspaceCompare(string S, string T) {
        const int N = S.size(), M = T.size();
        
        int ptr1 = N - 1, ptr2 = M - 1;
        int skip1 = 0, skip2 = 0;
        while (ptr1 >= 0 || ptr2 >= 0) {
            while (ptr1 >= 0) {
                if (S[ptr1] == '#') {
                    ptr1--;
                    skip1++;
                } else if (skip1 > 0) {
                    skip1--;
                    ptr1--;
                } else break;
            }
            
            while (ptr2 >= 0) {
                if (T[ptr2] == '#') {
                    ptr2--;
                    skip2++;
                } else if (skip2 > 0) {
                    ptr2--;
                    skip2--;
                } else break;
            }
            
            if (ptr1 >= 0 && ptr2 >= 0 && S[ptr1] != T[ptr2]) return false;
            if ((ptr1 >= 0) != (ptr2 >= 0)) return false;
            
            ptr1--;
            ptr2--;
        }
        return true;
    }
};
