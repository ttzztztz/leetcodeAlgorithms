class Solution {
public:
    string pushDominoes(string dominoes) {
        const int n = dominoes.size();
        vector<int> l(n), r(n);
        
        for (int i = 0, w = 0; i < n; i++) {
            if (dominoes[i] == 'R') w = n;
            else if (dominoes[i] == '.') w = max(0, w - 1);
            else w = 0; // dominoes[i] == 'L'
            
            l[i] = w;
        }
        for (int i = n - 1, w = 0; i >= 0; i--) {
            if (dominoes[i] == 'L') w = n;
            else if (dominoes[i] == '.') w = max(0, w - 1);
            else w = 0; // dominoes[i] == 'R'
            
            r[i] = w;
        }
        
        string ans;
        for (int i = 0; i < n; i++) {
            if (l[i] == r[i]) ans += '.';
            else if (l[i] > r[i]) ans += 'R';
            else ans += 'L'; // l[i] < r[i]
        }
        
        return ans;
    }
};