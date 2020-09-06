class Solution {
public:
    /**
     * @param A: a string A
     * @param B: a string B
     * @return: return the minimum number of operations to transform
     */
    int transform(string &A, string &B) {
        // write your code here
        const int N = A.size(), M = B.size();
        unordered_map<char, int> m1, m2;
        
        for (const char ch : A) m1[ch]++;
        for (const char ch : B) m2[ch]++;
        
        if (m1 != m2) return -1;
        
        int answer = 0;
        for (int i = N - 1, j = M - 1; i >= 0 && j >= 0; i--, j--) {
            while (i >= 0 && B[j] != A[i]) i--;
            if (i >= 0 && A[i] == B[j]) answer++;
            
        }
        return N - answer;
    }
};
