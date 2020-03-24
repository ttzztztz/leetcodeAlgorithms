class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the maximum length
     */
    int maxLen(vector<int> &a) {
        unordered_map<int, int> appear;
        const int N = a.size();
        
        int answer = 0;
        for (int left = 0, right = 0; right < N; right++) {
            appear[a[right]]++;
            while (appear.size() >= 3) {
                appear[a[left]]--;
                if (appear[a[left]] == 0) appear.erase(a[left]);
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};
