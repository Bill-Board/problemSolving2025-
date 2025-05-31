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
    int n, k;
    string s; 
    cin >> n >> k >> s;

    int one = 0, zero = 0;
    for (int i =0; i<n; i++) {
        one += (s[i] == '1');
        zero += (s[i] == '0');
    }

    int min = abs(one - zero) / 2;
    int max = (one/2) + (zero/2);

    if (min <= k and k <= max and abs(min - k)%2 == 0) {
        cout << "YES\n";
    } else { 
        cout << "NO\n";
    }
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
