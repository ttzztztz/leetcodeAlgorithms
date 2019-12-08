class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> answer;
        unordered_map<int, int> groupSizeMap;
        unordered_map<int, int> groupSizePosition;

        int index = 0;
        for (int i = 0; i < groupSizes.size(); i++) {
            const int groupSize = groupSizes[i];
            if (!groupSizeMap.count(groupSize) || groupSizeMap[groupSize] == 0) {
                groupSizeMap[groupSize] = groupSize;
                groupSizePosition[groupSize] = index;
                answer.push_back(vector<int>());
                index++;
            }

            groupSizeMap[groupSize]--;
            answer[groupSizePosition[groupSize]].push_back(i);
        }

        return answer;
    }
};