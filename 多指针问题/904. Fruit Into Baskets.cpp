class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int answer = 0;
        const int N = tree.size();
        int left = 0, right = 0;
        unordered_map<int, int> state;

        while (right < N) {
            state[tree[right]]++;

            while (state.size() >= 3) {
                if(--state[tree[left]] == 0) {
                    state.erase(tree[left]);
                }
                left++;
            }

            answer = max(answer, right - left + 1);
            right++;
        }

        return answer;
    }
};