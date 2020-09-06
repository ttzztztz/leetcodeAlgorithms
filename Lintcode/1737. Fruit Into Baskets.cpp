class Solution {
public:
    /**
     * @param tree: The type of fruit
     * @return: The total amount of fruit you can collect.
     */
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> kindFruits;
        int currentCount = 0;
        const int N = tree.size();
        int answer = 0;
        
        for (int left = 0, right = 0; right < N; right++) {
            kindFruits[tree[right]]++;
            
            while (kindFruits.size() > 2) {
                kindFruits[tree[left]]--;
                if (kindFruits[tree[left]] == 0) kindFruits.erase(tree[left]);
                left++;
            }
            
            answer = max(answer, right - left + 1);
        }
        
        return answer;
    }
};
