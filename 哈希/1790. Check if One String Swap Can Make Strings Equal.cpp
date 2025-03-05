class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        const int n = s1.size();
        for (int i = 0; i < n; i++) for (int j = 0; j < i; j++) {
            swap(s1[i], s1[j]);
            if (s1 == s2) return true;
            swap(s1[i], s1[j]);
        }
        return false;
    }
};