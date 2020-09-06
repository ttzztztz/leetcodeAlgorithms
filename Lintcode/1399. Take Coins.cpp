class Solution {
public:
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
    int takeCoins(vector<int> &list, int k) {
        int sum = 0;
        for (int i : list) sum += i;
        
        const int N = list.size(), M = N - k;
        int left = 0, right = 0, current = 0;
        while (right < M) {
            current += list[right];
            right++;
        }
        int answer = sum - current;
        
        while (right < N) {
            current -= list[left];
            current += list[right];
            answer = max(answer, sum - current);
            left++, right++;
        }
        
        return answer;
    }
};
