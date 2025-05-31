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

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> a;
    map<int, int>mpp;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        if(mpp.count(target- nums[i])){
            a.push_back(mpp[target- nums[i]]);
            a.push_back(i);
            break;
        }   
        mpp[nums[i]] = i;
    }
    return a;
}

void solve(int tc)
{
    int n, target; cin >> n >> target;
    vector<int> nums(n);

    for (auto &i: nums) {
        cin >> i;
    }

    vector<int> ans =  twoSum(nums, target);
}



signed main()
{
    int test_case=1;
//    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cin >> test_case;
    for(int i = 1; i <= test_case ; i++)
        solve(i);
    return 0;
}



///  Alhamdulillah...
