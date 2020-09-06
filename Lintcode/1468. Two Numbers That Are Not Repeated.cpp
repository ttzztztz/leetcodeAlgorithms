class Solution {
public:
    /**
     * @param a: the array
     * @return: the two numbers that are not repeated
     */
    vector<int> theTwoNumbers(vector<int> &a) {
        vector<int> answer = {0, 0};
        
        int bin = 0;
        for (int n : a) bin ^= n;
        
        int bin_1 = bin & (-bin);
        int bin_2 = bin ^ (bin & (-bin));
        
        for (int n : a) {
            if (n & bin_1) {
                answer[0] ^= n;
            } else {
                answer[1] ^= n;
            }
        }
        
        if (answer[0] > answer[1]) swap(answer[0], answer[1]);
        return answer;
    }
};
