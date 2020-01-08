class Solution {
public:
    bool isValid(string S) {
        if (S == "abc") return true;
        if (S.size() < 3) return false;
        
        auto offset = S.find("abc");
        if (offset == std::string::npos) {
            return false;
        }
        return isValid(S.replace(offset, 3, ""));
    }
};
