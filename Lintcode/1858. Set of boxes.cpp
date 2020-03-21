class Solution {
public:
    /**
     * @param boxes: 
     * @return: the number of boxes
     */
    int maxBoxes(vector<vector<int>> &boxes) {
        const int N = boxes.size();
        for (vector<int>& box : boxes) {
            if (box[0] < box[1]) swap(box[0], box[1]);
        }
        
        sort(boxes.begin(), boxes.end(), [](const auto& $1, const auto& $2)->bool {
            if ($1[0] == $2[0]) return $1[1] > $2[1];
            return $1[0] < $2[0];
        });
        
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            const int num = boxes[i][1];
            if (stk.empty() || stk.back() < num) {
                stk.push_back(num);
            } else {
                auto it = lower_bound(stk.begin(), stk.end(), num);
                *it = num;
            }
        }
        return stk.size();
    }
};
