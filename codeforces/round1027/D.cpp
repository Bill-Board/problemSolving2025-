//BISMILLAHIR RAHMANIR RAHEEM
//ALLAH IS WATCHING ME
// Shoeb Akibul Islam
// Dept of ICE, NSTU
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii= pair<int,int>;

const int N = 200005;
ll mod= 1e9+7;

int row[N], column[N];

template <typename T>
struct st
{
#define lc (n << 1)
#define rc ((n << 1) + 1)

    vector<T> minEle, maxEle;
    bool isRow;

    st(T n, bool isRow)
    {
        minEle.resize(4 * n, 0);
        maxEle.resize(4 * n, 0);

        this->isRow = isRow;
    }

    inline T minCombine(T a, T b)
    {
        return min(a, b);
    }

    inline T maxCombine(T a, T b)
    {
        return max(a, b);
    }

    inline void minPull(int n)
    {
        minEle[n] = min(minEle[lc], minEle[rc]);
    }

    inline void maxPull(int n)
    {
        maxEle[n] = max(maxEle[lc], maxEle[rc]);
    }

    void build(int n, int b, int e)
    {
        if (b == e)
        {
            if (isRow) {
                minEle[n] = maxEle[n] = row[b];
            } else {
                minEle[n] = maxEle[n] = column[b];
            }
            
            return;
        }

        T mid = (b + e) >> 1;

        build(lc, b, mid);
        build(rc, mid + 1, e);

        minPull(n);
        maxPull(n);
    }

    T minQuery(int n, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return INT_MAX;
        if (i <= b and e <= j)
            return minEle[n];

        int mid = (b + e) >> 1;

        return minCombine(minQuery(lc, b, mid, i, j), minQuery(rc, mid + 1, e, i, j));
    }

    T maxQuery(int n, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return 0;
        if (i <= b and e <= j)
            return maxEle[n];

        int mid = (b + e) >> 1;

        return maxCombine(maxQuery(lc, b, mid, i, j), maxQuery(rc, mid + 1, e, i, j));
    }
};

ll findTotalCell(pii a, pii b) {
    ll diffRow = abs(a.first - b.first) + 1, diffColumn = abs(a.second - b.second) + 1;

    return diffRow * diffColumn;
}

int findMinLength(pii a, pii b) {
    return min(abs(a.first - b.first) + 1, abs(a.second - b.second) + 1);
}

void solve(int tc)
{
    int n; cin >> n;

    for (int i = 1; i<=n; i++) {
        cin >> row[i] >> column[i];
    }

    if (n == 1) {
        cout << n << endl;

        return;
    }

    st<int> rBit(n, true), cBit(n, false);

    rBit.build(1, 1, n);
    cBit.build(1, 1, n);

    ll ans = LONG_LONG_MAX;

    for (int i = 1 ; i<=n ; i++) {
        pii minCell = {min(rBit.minQuery(1, 1, n, 1, i-1), rBit.minQuery(1, 1, n, i + 1, n)), min(cBit.minQuery(1, 1, n, 1, i-1), cBit.minQuery(1, 1, n, i + 1, n))};
        pii maxCell = {max(rBit.maxQuery(1, 1, n, 1, i-1), rBit.maxQuery(1, 1, n, i + 1, n)), max(cBit.maxQuery(1, 1, n, 1, i-1), cBit.maxQuery(1, 1, n, i + 1, n))};

        ll totalCell = findTotalCell(minCell, maxCell);
        ll emptyCell = totalCell - (n - 1);

        if (!emptyCell) {
            totalCell += findMinLength(minCell, maxCell);
        }

        ans = min (totalCell, ans);
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
