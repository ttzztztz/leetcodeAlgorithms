class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> isJ(J.begin(), J.end());
        int answer = 0;
        
        for (char ch : S) if (isJ.count(ch)) answer++;
        return answer;
    }
};
