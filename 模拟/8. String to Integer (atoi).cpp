class Solution {
public:
    int myAtoi(string str) {
        std::stringstream ss;
        ss << str;
        int result = 0;
        ss >> result;
        return result;
    }
};