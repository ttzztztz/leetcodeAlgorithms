class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) {
            return "0";
        }
        string stack;
        stack.push_back(num[0]);
        for (int i = 1; i < num.size(); i++) {
            const char& currentChar = num[i];

            while (k && stack.size() && stack[stack.size() - 1] > currentChar) {
                stack.pop_back();
                k--;
            }

            stack.push_back(currentChar);
        }

        while (k) {
            stack.pop_back();
            k--;
        }
        bool begin = true;
        int answerStartPtr = 0;
        for (int i = 0; i < stack.size(); i++) {
            if (begin && stack[i] == '0') {
                answerStartPtr++;
                continue;
            }
            break;
        }
        stack = stack.substr(answerStartPtr);
        return stack == "" ? "0" : stack;
    }
};