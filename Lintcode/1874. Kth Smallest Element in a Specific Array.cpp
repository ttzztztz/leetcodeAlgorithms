class Solution {
public:
    /**
     * @param arr: an array of integers
     * @param k: an integer
     * @return: the Kth smallest element in a specific array
     */
    int kthSmallest(vector<vector<int>> &arr, int k) {
        priority_queue<int, vector<int>, less<>> heap;
        const int N = arr.size();
        
        for (vector<int>& i : arr) for (int& j : i) {
            if (heap.size() < k) {
                heap.push(j);
            } else { // == k
                const int t = heap.top();
                if (j < t) {
                    heap.pop();
                    heap.push(j);
                }
            }
        }
        
        return heap.top();
    }
};
