class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appear_cnt;
        for (const int& i : nums) appear_cnt[i]++;

        typedef pair<int, int> PII;
        priority_queue<PII, vector<PII>, greater<>> heap;
        for (auto& [number, cnt] : appear_cnt) {
            if (heap.empty() || heap.size() < k) {
                heap.emplace(cnt, number);
            } else if (heap.top().first < cnt) {
                heap.pop();
                heap.emplace(cnt, number);
            }
        }

        vector<int> ans;
        while (!heap.empty()) {
            const auto [cnt, number] = heap.top();
            heap.pop();
            ans.push_back(number);
        }
        return ans;
    }
};