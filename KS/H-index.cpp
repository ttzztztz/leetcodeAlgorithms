#include <iostream>
#include <set>

using namespace std;

int main() {
    int testCase = 0;
    cin >> testCase;
    for (int _ = 1; _ <= testCase; _++) {

        int N = 0;
        cin >> N;
        multiset<long long> s;
        printf("Case #%d: ", _);
        for (int i = 0; i < N; i++) {
            int Ai;
            cin >> Ai;
            s.insert(Ai);

            while (!s.empty() && *s.begin() < s.size()) {
                s.erase(s.begin());
            }

            printf("%u ", s.size());
        }

        printf("\n");
    }
    return 0;
}