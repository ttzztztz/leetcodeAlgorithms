class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> table;

        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {
                table.push_back(stoi(str.substr(i, len)));
            }
        }

        vector<int> answer;
        for (int num : table) {
            if (num >= low && num <= high) {
                answer.push_back(num);
            }
        }
        return answer;
    }
};