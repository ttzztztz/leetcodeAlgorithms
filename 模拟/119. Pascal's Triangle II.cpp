class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> f[35];
        f[0] = {1};
        f[1] = {1, 1};
        
        for (int i = 2; i <= rowIndex; i++) {
            const vector<int>& prev = f[i - 1];
            for (int j = 0; j <= i; j++) {
                const int p = j - 1 >= 0 ? prev[j - 1] : 0;
                const int c = j < prev.size() ? prev[j] : 0;
                
                f[i].push_back(p + c);
            }
        }
        
        return f[rowIndex];
    }
};