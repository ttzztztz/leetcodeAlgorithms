class Solution {
public:
    /**
     * @param arr: An integer array
     * @param k: An integer
     * @return: return the pair of movies index with the longest total duration
     */
    vector<int> FlightDetails(vector<int> &arr, int k) {
        vector<int> answer;
        
        k -= 30;
        set<pair<int, int>> numberSet{{arr[0], 0}};
        const int N = arr.size();
        for (int i = 1; i < N; i++) {
            auto it = numberSet.lower_bound({k - arr[i], -1});
            
            if (it->first + arr[i] <= k) {
                if (answer.empty() || arr[answer[0]] + arr[answer[1]] < it->first + arr[i]) {
                    answer = vector<int>{it->second, i};
                }
            }
            
            if (it != numberSet.begin()) {
                it--;
                
                if (it->first + arr[i] <= k) {
                    if (answer.empty() || arr[answer[0]] + arr[answer[1]] < it->first + arr[i]) {
                        answer = vector<int>{it->second, i};
                    }
                }
            }
            
            numberSet.emplace(arr[i], i);
        }
        
        return answer;
    }
};
