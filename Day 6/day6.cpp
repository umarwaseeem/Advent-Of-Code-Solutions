#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    while (cin >> S)
    {
        const int N = sz(S);
        for (int i = 13; i < N; i++)
        {
            set<char> f;
            int cnt = 14;
            for (int j = i; cnt > 0; j--, cnt--)
            {
                f.insert(S[j]);
            }
            if (sz(f) == 14)
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

    return 0;
}