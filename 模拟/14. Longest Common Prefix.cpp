class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } else if (strs.size() == 1) {
            return strs[0];
        }

        int ptr = 0, minLen = 0x7fffffff;
        for (int i = 0; i < strs.size(); i++) {
            int len = strs[i].size();
            minLen = std::min(minLen, len);
        }

        int i = 0;
        for (i = 0; i < minLen; i++) {
            char ch = strs[0][i];

            bool shouldBreakFlag = false;
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    shouldBreakFlag = true;
                    break;
                }
            }

            if (shouldBreakFlag) {
                break;
            }
        }

        return strs[0].substr(0, i);
    }
};