class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        const int N = nums.size();
        vector<int> answer;
        
        priority_queue<int, vector<int>, less<>> heap1;
        priority_queue<int, vector<int>, greater<>> heap2;
        
        for (int num : nums) {
            heap1.push(num);
            heap2.push(heap1.top());
            heap1.pop();
            
            if (heap1.size() < heap2.size()) {
                heap1.push(heap2.top());
                heap2.pop();
            }
            
            answer.push_back(heap1.top());
        }
        return answer;
    }
};
