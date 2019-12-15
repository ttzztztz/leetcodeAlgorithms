class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        vector<int> occur(100005, 0);
        const int N = arr.size() / 4;

        for (int num : arr) {
            occur[num]++;

            if (occur[num] > N) {
                return num;
            }
        }
        return -1;
    }
};