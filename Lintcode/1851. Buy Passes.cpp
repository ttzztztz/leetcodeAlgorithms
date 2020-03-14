class Solution {
public:
    /**
     * @param arr: the line 
     * @param k: Alex place
     * @return: the time when Alex requires to buy all passes
     */
    int buyPasses(vector<int> &arr, int k) {
        int answer = 0, rnd = 0;
        const int N = arr.size();
        for (int i = 0; i < k; i++) {
            arr[i]--;
            answer++;
        }
        multiset<int> allRemain;
        for (int i = 0; i < N; i++) {
            if (arr[i] > 0) {
                allRemain.emplace(arr[i]);
            }
        }
        
        while (!allRemain.empty() && arr[k] > rnd) {
            int _min = *allRemain.begin();
            if (arr[k] == _min) {
                answer += (_min - rnd - 1) * allRemain.size() + 1;
                break;
            }
            answer += (_min - rnd) * allRemain.size();
            rnd = _min;
            
            allRemain.erase(_min);
        }
        
        return answer;
    }
};
