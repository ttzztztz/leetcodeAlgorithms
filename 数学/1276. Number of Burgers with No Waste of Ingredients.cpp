class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> answer;

        const int f1 = tomatoSlices - 2 * cheeseSlices;
        if (f1 % 2 || f1 < 0) {
            return answer;
        }
        const int f2 = 4 * cheeseSlices - tomatoSlices;
        if (f2 % 2 || f2 < 0) {
            return answer;
        }

        return {f1 / 2, f2 / 2};
    }
};