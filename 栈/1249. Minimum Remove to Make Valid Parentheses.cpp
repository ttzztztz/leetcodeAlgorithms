class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char> stack;
        vector<int> left;
        vector<bool> blackList(100005, false);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push_back(i);
            } else if (s[i] == ')') {
                if (left.empty()) {
                    blackList[i] = true;
                } else {
                    left.pop_back();
                }
            }

            stack.push_back(s[i]);
        }

        for (int i : left) {
            blackList[i] = true;
        }
        string answer;
        for (int i = 0; i < stack.size(); i++) {
            if (!blackList[i]) {
                answer.push_back(stack[i]);
            }
        }
        return answer;
    }
};