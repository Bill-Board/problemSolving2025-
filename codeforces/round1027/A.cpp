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

map <int, pii> mpp;

void initialProcess() {
    for (int i = 0; i<100; i++) {
        for (int j = 0; j<100; j++) {
            int div = ((i + j)*(i + j))/10000;
            if (div == 0) {
                mpp[(i + j)*(i + j)] = {i, j};
            } 
        }
    }
}

int toNumber(string s) {
    int ans = 0, n = s.size();
    for (int i = n-1, mul = 1; i >= 0; i--, mul *= 10) {
        ans += (s[i] - '0') * mul;
    }

    return ans;
}

void solve(int tc)
{
    string s; cin >> s;
    int n = toNumber(s);



    if (mpp.find(n) == mpp.end()) {
        cout << -1 << endl;
    } else {
        cout << mpp[n].first << ' ' << mpp[n].second << endl;
    }
}



signed main()
{
    int test_case=1;
    initialProcess();
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
