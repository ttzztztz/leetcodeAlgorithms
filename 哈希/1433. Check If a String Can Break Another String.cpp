class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        return check(s1, s2) || check(s2, s1);
    }
private:
    bool check(const string& s1, const string& s2) {
        multiset<char> appear(s1.begin(), s1.end());
        for (const char ch : s2) {
            auto it = appear.lower_bound(ch);
            if (it == appear.end()) return false;
            appear.erase(it);
        }
        return true;
    }
};
