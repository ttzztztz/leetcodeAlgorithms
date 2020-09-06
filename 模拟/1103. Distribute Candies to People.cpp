class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> answer(num_people, 0);
        
        const int N = num_people;
        for (int i = 0, r = candies, cur = 1; r > 0; i = (i + N + 1) % N, cur++) {
            const int tmp = min(cur, r);
            answer[i] += tmp;
            r -= tmp;
        }
        
        return answer;
    }
};