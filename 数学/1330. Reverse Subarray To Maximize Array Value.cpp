class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        const int N = nums.size();
        int raw = 0, delta = 0, _min = 999999, _max = -999999;
        
        for (int i = 0; i + 1 < N; i++) {
            const int a = nums[i], b = nums[i + 1];
            
            delta = max(delta, abs(b - nums[0]) - abs(a - b));
            delta = max(delta, abs(a - nums[N - 1]) - abs(a - b));
            
            raw += abs(a - b);
            _max = max(_max, min(a, b));
            _min = min(_min, max(a, b));
        }
        
        return raw + max(delta, (_max - _min) * 2);
    }
};
