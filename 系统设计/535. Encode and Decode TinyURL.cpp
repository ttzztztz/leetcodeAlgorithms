class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        const string cur = to_string(idx++);
        string res = "http://tinyurl.com/" + cur;
        data[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return data[shortUrl];
    }
private:
    int idx = 0;
    unordered_map<string, string> data;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
