#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll K, N;
ll calc(ll t, ll X) 
{
    ll low = 0, high = 2e5;
    ll bestv = 0;
    while(low <= high) 
	{
        ll mid = (low + high)/2;
        ll time_needed = mid + (mid - X);
        if(time_needed <= t) 
		{
            bestv = mid;
            low = mid + 1;
        } 
		else 
		{
            high = mid - 1;
        }
    }
    ll dist = bestv * bestv - X*(X-1)/2;
    ll rem_time = t - (bestv + (bestv - X));
    if(rem_time > 0) dist += rem_time * X;
    return dist;
}
ll solve(ll X) 
{
    ll l = 1, r = 2e5;
    ll ans = r;
    while(l <= r) 
	{
        ll mid = (l + r)/2;
        ll d = calc(mid, X);
        if(d >= K) 
		{
            ans = mid;
            r = mid - 1;
        } 
		else 
		{
            l = mid + 1;
        }
    }
    return ans;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K >> N;
    for(int i=0; i<N; i++) 
	{
        ll X;
        cin >> X;
        cout << solve(X) << '\n';
    }
    return 0;
}
