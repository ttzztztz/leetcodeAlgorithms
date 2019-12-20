class Solution {
public:
    bool solve(const vector<double>& candidates) {
        if (candidates.size() == 0) return false;
        if (candidates.size() == 1) return abs(candidates[0] - 24.0) <= 1e-6;

        const int N = candidates.size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;

                vector<double> nextCandidates;
                for (int k = 0; k < N; k++) {
                    if (k == i || k == j) continue;
                    nextCandidates.push_back(candidates[k]);
                }

                nextCandidates.push_back(candidates[i] + candidates[j]);
                if(solve(nextCandidates)) return true;
                nextCandidates.pop_back();

                nextCandidates.push_back(candidates[i] - candidates[j]);
                if(solve(nextCandidates)) return true;
                nextCandidates.pop_back();

                nextCandidates.push_back(candidates[i] * candidates[j]);
                if(solve(nextCandidates)) return true;
                nextCandidates.pop_back();

                nextCandidates.push_back(candidates[i] / candidates[j]);
                if(solve(nextCandidates)) return true;
                nextCandidates.pop_back();
            }
        }

        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> candidates;
        for (int num : nums) {
            candidates.push_back(1.0 * num);
        }
        return solve(candidates);
    }
};