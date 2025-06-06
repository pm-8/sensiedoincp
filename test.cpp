#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> dp_prev(M+1, 1), dp_cur(M+1, 0);

    for(int len = 2; len <= N; ++len) {
        fill(dp_cur.begin(), dp_cur.end(), 0);
        for(int d = 1; d <= M; ++d) {
            int v = dp_prev[d];
            if (!v) continue;
            for(int mult = d; mult <= M; mult += d) {
                dp_cur[mult] += v;
                if (dp_cur[mult] >= MOD) 
                    dp_cur[mult] -= MOD;
            }
        }
        dp_prev.swap(dp_cur);
    }

    long long ans = 0;
    for(int x = 1; x <= M; ++x) {
        ans += dp_prev[x];
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans << "\n";
    return 0;
}
