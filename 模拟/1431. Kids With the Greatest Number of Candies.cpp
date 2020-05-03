class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        const int N = candies.size();
        vector<bool> answer(N, false);
        int _max = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < N; i++) {
            if (candies[i] + extraCandies >= _max) answer[i] = true;
        }
        return answer;
    }
};
