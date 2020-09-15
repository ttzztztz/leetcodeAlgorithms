class Solution {
public:
    int lengthOfLastWord(string s) {
        int answer = 0;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            answer = tmp.size();
        }
        return answer;
    }
};
