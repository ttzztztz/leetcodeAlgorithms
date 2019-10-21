class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        const int N = req_skills.size(), MAX_STATE = (1 << N) - 1, MAX = 0x6f6f6f6f, M = people.size();
        vector<int> dp(MAX_STATE + 5, MAX), newPeople(M + 5, 0);

        for (int i = 0; i < people.size(); i++) {
            const vector<string> &person = people[i];

            for (const string &skillInPeople : person) {
                int index = std::find(req_skills.begin(), req_skills.end(), skillInPeople) - req_skills.begin();

                newPeople[i] |= 1 << index;
            }
        }
        vector<vector<int>> answer(MAX_STATE + 5, vector<int>());

        dp[0] = 0;
        for (int state = 0; state <= MAX_STATE; state++) {
            if (dp[state] == MAX) {
                continue;
            }

            for (int i = 0; i < newPeople.size(); i++) {
                if (dp[state | newPeople[i]] > dp[state] + 1) {

                    dp[state | newPeople[i]] = dp[state] + 1;
                    answer[state | newPeople[i]] = answer[state];
                    answer[state | newPeople[i]].push_back(i);

                }
            }
        }

        return answer[MAX_STATE];
    }
};