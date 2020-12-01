class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        const int n = S.size();
        vector<long long> diff(n + 1, 0);
        
        for (int i = 0; i < shifts.size(); i++) {
            const int shift = shifts[i];
            diff[0] += shift;
            diff[i + 1] -= shift;
        }
        
        long long cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            int d = S[i] - 'a';
            d = (d + cur) % 26;
            S[i] = 'a' + d;
        }
        return S;
    }
};
