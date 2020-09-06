class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        
        for (int i = 1; i <= n; i++) {
            const bool b1 = i % 3 == 0, b2 = i % 5 == 0;
            
            if (b1 && !b2) ans.push_back("Fizz");
            else if (!b1 && b2) ans.push_back("Buzz");
            else if (b1 && b2) ans.push_back("FizzBuzz");
            else ans.push_back(to_string(i));
        }
        
        return ans;
    }
};
