#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

vector<int> build_next(const string& str) {
    vector<int> nxt(str.size() + 1, 0);
    nxt[0] = -1;
    nxt[1] = 0;

    int i = 1, j = 0;
    while (i < str.size()) {
        if (j == -1 || str[i] == str[j]) {
            nxt[++i] = ++j;
        } else {
            j = nxt[j];
        }
    }
    return nxt;
}

vector<string> split(const string& str, const string& deli) {
    vector<string> ans;
    if (str.empty() || deli.empty()) return ans;

    vector<int> nxt = build_next(deli);
    int i = 0, j = 0, last = 0;
    const int d = deli.size();
    while (i < str.size()) {
        if (j == -1 || str[i] == deli[j]) {
            i++, j++;
        } else {
            j = nxt[j];
        }

        if (j == deli.size()) {
            if (i - last - d > 0) ans.push_back(str.substr(last, i - last - d));
            last = i;
            j = nxt[j];
        }
    }
    if (last != str.size()) {
        ans.push_back(str.substr(last));
    }
    return ans;
}

int main() {
    typedef tuple<string, string, vector<string>> TestCase;
    vector<TestCase> data = {
        {"111aa222aa333aa999", "aa", {"111", "222", "333", "999"}},
        {"123aaaaaaa777", "aa", {"123", "777"}}
    };
    for (auto& [a, b, res] : data) {
        vector<string> ans = split(a, b);
        assert((ans == res));
    }
    cout << "OK" << endl;
    return 0;
}
