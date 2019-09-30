class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (0 == buildings.size()) {
            return vector<vector<int>>();
        }

        vector<vector<int>> answer;
        vector<pair<int, int>> segments;

        for (const vector<int>& building : buildings) {
            segments.emplace_back(building[0], building[2]);
            segments.emplace_back(building[1], -building[2]);
        }

        std::sort(segments.begin(), segments.end(), [](const pair<int, int>& $1, const pair<int, int>& $2)->bool{
            if ($1.first == $2.first) {
                return $1.second > $2.second;
            } else {
                return $1.first < $2.first;
            }
        });

        multiset<int> set;
        set.insert(0);
        int lastHeight = 0;

        for (const pair<int, int>& segment : segments) {
            int height = segment.second, left = segment.first;

            if (height < 0) {
                set.erase(set.find(-height));
            } else {
                set.insert(height);
            }

            int maxHeight = *set.rbegin();
            if (lastHeight != maxHeight) {
                lastHeight = maxHeight;
                vector<int> oneAnswer = {left, maxHeight};
                answer.push_back(oneAnswer);
            }
        }

        return answer;
    }
};