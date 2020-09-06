typedef unsigned long long ull;
vector<ull> all;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        if (all.empty()) {
            const int MAX = 1e5;
            
            for (ull i = 1; i <= MAX; i++) {
                const ull $1 = make1(i);
                const ull $1_2 = $1 * $1;
                if (isPalindrome($1) && isPalindrome($1_2)) all.push_back($1_2);

                const ull $2 = make2(i);
                const ull $2_2 = $2 * $2;

                if (isPalindrome($2) && isPalindrome($2_2)) all.push_back($2_2);
            }

            sort(all.begin(), all.end());
        }
        
        const ull l = stoull(L), r = stoull(R);
        auto it1 = upper_bound(all.begin(), all.end(), r);
        auto it2 = lower_bound(all.begin(), all.end(), l);
        return it1 - it2;
    }
private:
    bool isPalindrome(ull i) {
        string x = to_string(i);
        for (int l = 0, r = x.size() - 1; l < r; l++, r--) {
            if (x[l] != x[r]) return false;
        }
        return true;
    }
    ull make1(ull i) {
        string s1 = to_string(i);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return stoull(s1 + s2);
    }
    ull make2(ull i) {
        string s1 = to_string(i);
        string s2 = s1;
        s2.pop_back();
        reverse(s2.begin(), s2.end());
        return stoull(s1 + s2);
    }
};
