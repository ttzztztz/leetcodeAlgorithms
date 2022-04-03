class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        v = values;
        
        for (int i = 0; i < keys.size(); i++) {
            kIdx[keys[i]] = i;
        }
        
        for (auto& d : dictionary) {
            cnt[encrypt(d)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (const char ch : word1) {
            ans += v[kIdx[ch]];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        if (cnt.count(word2)) return cnt[word2];
        else return 0;
    }
private:
    vector<string> v;
    unordered_map<char, int> kIdx;
    unordered_map<string, int> cnt;
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
