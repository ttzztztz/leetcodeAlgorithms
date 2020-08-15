class Solution {
public:
    /**
     * @param str: the original string
     * @param sublen: an integer array
     * @return: the new string
     */
    string reformatString(string &str, vector<int> &sublen) {
        // write your code here
        vector<string> substrs;
        int idx = 0;
        for (int i : sublen) {
            substrs.push_back(str.substr(idx, i));
            idx += i;
        }
        
        string answer;
        for (int i = 0; i + 1 < substrs.size(); i += 2) {
            answer += substrs[i + 1];
            answer += substrs[i];
        }
        
        if (substrs.size() % 2 == 1) answer += substrs.back();
        return answer;
    }
};
