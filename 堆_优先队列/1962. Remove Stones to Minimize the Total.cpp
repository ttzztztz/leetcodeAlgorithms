class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int ans = 0;
        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, less<>> heap;
        for (int i : piles) {
            heap.emplace(i / 2, i);
        }
        
        while (!heap.empty() && k > 0) {
            auto [delta, u] = heap.top();
            heap.pop();
            
            const int remain = u - delta;
            k--;
            ans += delta;
            if (remain >= 0) heap.emplace(remain / 2, remain);
        }
        return sum - ans;
    }
};