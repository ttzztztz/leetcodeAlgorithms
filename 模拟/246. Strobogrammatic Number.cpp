class Solution {
public:
    bool isStrobogrammatic(string num) {
        if (num.empty()) return true;

        unordered_set<int> kValid = { 0, 1, 8 };
        for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
            if (i == j) {
                const int a = num[i] - '0';
                if (!kValid.count(a)) return false;
            } else {
                const int a = num[i] - '0', b = num[j] - '0';
                if ((a == 6 && b == 9) || (a == 9 && b == 6)) continue;
                if (!kValid.count(a) || !kValid.count(b)) return false;
                if (a != b) return false;
            }
        }
        return true;
    }
};
