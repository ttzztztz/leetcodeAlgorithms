class Solution {
public:
    bool backspaceCompare(string S, string T) {
        const int N = S.size(), M = T.size();
        
        int continous = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (S[i] == '#') {
                continous++;
            } else if (S[i] != '#' && continous > 0) {
                continous--;
                S[i] = '#';
            }
        }
        
        continous = 0;
        for (int i = M - 1; i >= 0; i--) {
            if (T[i] == '#') {
                continous++;
            } else if (T[i] != '#' && continous > 0) {
                continous--;
                T[i] = '#';
            }
        }
        
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < N && ptr2 < M) {
            while (ptr1 < N && S[ptr1] == '#') ptr1++;
            while (ptr2 < M && T[ptr2] == '#') ptr2++;
            
            if (ptr1 < N && ptr2 < M) {
                if (S[ptr1] != T[ptr2]) return false;
                ptr1++, ptr2++;
            }
        }
        
        while (ptr1 < N && S[ptr1] == '#') ptr1++;
        while (ptr2 < M && T[ptr2] == '#') ptr2++;
        return ptr1 == N && ptr2 == M;
    }
};
