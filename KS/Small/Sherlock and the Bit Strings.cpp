#include <iostream>
#include <bitset>
#include <cstring>
#include <algorithm>

//#define DEBUG 1

using namespace std;

int main() {
    int dataCount = 0;
    cin >> dataCount;
    for (int _ = 1; _ <= dataCount; _++) {
        int N = 0, K = 0;
        long long P = 0;
        cin >> N >> K >> P;

        bitset<105> rank(P - 1);
        string rankStr = rank.to_string();
        std::reverse(rankStr.begin(), rankStr.end());

        string result(N, '0');
        bool haveRequire[N + 1];
        memset(haveRequire, 0, sizeof(haveRequire));
        for (int i = 1; i <= K; i++) {
            int Ai = 0, Bi = 0, Ci = 0;
            cin >> Ai >> Bi >> Ci;

            result[Ai - 1] = Ci + '0';
            haveRequire[Ai - 1] = true;
        }

        int rawPtr = 0;
        for (int i = 1; i <= N; i++) {
            if (!haveRequire[N - i]) {
#ifdef DEBUG
                cout << i << " " << N - i << " " << rankStr[rawPtr] << endl;
#endif
                result[N - i] = rankStr[rawPtr];
                rawPtr++;
            }
        }

        cout << "Case #" << _ << ": " << result << endl;
//        printf("Case #%d: %s \n", _, result.c_str());
    }
    return 0;
}