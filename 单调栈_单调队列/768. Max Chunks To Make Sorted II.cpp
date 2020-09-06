class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> stk;
        for (int num : arr) {
            if (stk.empty()) stk.push_back(num);
            else {
                int top = stk.back();
                while (!stk.empty() && stk.back() > num) stk.pop_back();
                stk.push_back(max(top, num));
            }
        }
        return stk.size();
    }
};
