class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& v : A) {
            reverse(v.begin(), v.end());
        }
        
        for (auto& v : A) {
            for (auto& i : v) i = !i;
        }
        
        return A;
    }
};