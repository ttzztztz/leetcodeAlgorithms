class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int answer = 0;
        sort(people.begin(), people.end());
        const int N = people.size();
        int left = 0, right = N - 1;

        while (left <= right) {
            int rest = limit - people[right], carry = 1;
            right--;

            while (carry < 2 && rest > 0 && left <= right && people[left] <= rest) {
                rest -= people[left];
                left++, carry++;
            }

            answer++;
        }
        return answer;
    }
};