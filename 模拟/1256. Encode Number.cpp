class Solution {
public:
    string encode(int num) {
        if (num == 0) {
            return "";
        }

        num--;
        string answer;
        if (num % 2) {
            answer = encode(num / 2) + "1";
        } else {
            answer = encode(num / 2) + "0";
        }
        return answer;
    }
};