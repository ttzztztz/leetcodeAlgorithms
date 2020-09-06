class Solution {
public:
    /**
     * @param sourceString: a string
     * @param targetStrings: a string array
     * @return: Returns a bool array indicating whether each string in targetStrings is a substring of the sourceString
     */
    vector<bool> whetherStringsAreSubstrings(string &sourceString, vector<string> &targetStrings) {
        // write your code here
        const int N = targetStrings.size();
        vector<bool> answer(N);
        
        for (int i = 0; i < N; i++) {
            answer[i] = sourceString.find(targetStrings[i]) != string::npos;
        }
        
        return answer;
    }
};
