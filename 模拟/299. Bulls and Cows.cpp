class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        const int N = secret.size();
        
        multiset<char> no;
        for (int i = 0; i < N; i++) {
            if (secret[i] == guess[i]) {
                a++;
            } else {
                no.insert(secret[i]);
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (secret[i] == guess[i]) {
                continue;
            } else {
                if (no.count(guess[i])) {
                    b++;
                    no.erase(no.lower_bound(guess[i]));
                }
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
