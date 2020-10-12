class Solution {
public:
    bool buddyStrings(string A, string B) {
        unordered_map<char, int> a, b;
        for (auto& p : A) a[p]++;
        for (auto& p : B) b[p]++;
        
        if (a != b) return false;
        int change = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (change == 2) return false;
                else change++;
            }
        }
        
        if (change == 2) return true;
        else {
            for (auto& p : a) if (p.second >= 2) return true;
            return false;
        }
    }
};
