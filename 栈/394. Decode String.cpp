class Solution {
public:
    string decodeString(string s) {
        const int N = s.size();

        string currentNumber;
        string currentString;
        vector<pair<string, int>> leftStack;
        for (int i = 0; i < N; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                currentNumber += s[i];
            } else if (s[i] == '[') {
                leftStack.emplace_back(currentString, stoi(currentNumber));
                currentNumber = "", currentString = "";
            } else if (s[i] == ']') {
                pair<string, int> top = leftStack.back();
                leftStack.pop_back();

                string prev_string = currentString;
                for (int k = 0; k < top.second - 1; k++) {
                    currentString += prev_string;
                }

                currentString = top.first + currentString;
            } else {
                currentString += s[i];
            }
        }


        return currentString;
    }
};