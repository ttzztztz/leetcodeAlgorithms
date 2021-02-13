class Solution {
public:
    /**
     * @param nums1: List[int]
     * @param nums2: List[int]
     * @param k: an integer
     * @return: return List[List[int]]
     */
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        const int N = nums1.size(), M = nums2.size();
        
        typedef pair<int, int> State;
        priority_queue<State, vector<State>, less<>> heap;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (heap.size() < k) {
                    heap.emplace(nums1[i] + nums2[j], nums1[i]);
                } else {
                    int topSum = heap.top().first;
                    if (nums1[i] + nums2[j] < topSum) {
                        heap.pop();
                        heap.emplace(nums1[i] + nums2[j], nums1[i]);
                    }
                }
            }
        }
        
        vector<vector<int>> answer;
        while (!heap.empty()) {
            int sum, i;
            tie(sum, i) = heap.top();
            heap.pop();
            
            answer.push_back(vector<int>{i, sum - i});
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
