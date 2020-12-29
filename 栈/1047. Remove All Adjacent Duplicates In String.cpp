class Solution {
public:
    string removeDuplicates(string S) {
        string str;
        for (const char ch : S) {
            if (!str.empty() && str.back() == ch) str.pop_back();
            else str.push_back(ch);
        }
        return str;
    }
};
