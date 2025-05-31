//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<int,int>;

const int N = 100005;
ll mod= 1e9+7;

void solve(int tc)
{
    int n; cin >> n;
    vector<int> a(n);

    for (auto &i: a) {
        cin >> i;
    }

    int ans = 1;

    for (int i = 1; i<n; i++) {
        int last = a[i - 1];

        while (i < n and a[i] - last <= 1) {
            i ++;
        }

        if (i < n)
            ans ++;
    }
    cout << ans << endl;
}



signed main()
{
    int test_case=1;
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
