#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long calc( pair<int , int > a , pair < int , int > b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int , int>> a(N);
    for( int i = 0 ; i < N ; i ++)
    {
        cin >> a[i].first >> a[i].second;
    }

    long long total = 0;
    for (int i = 0; i < N - 1; i ++)
    {
        total += calc(a[i], a[i+1]);
    }

    long long max_save = 0;
    // 枚举所有可以跳过的中间点 i，范围1~N-2
    for(int i = 1; i <= N-2; i++){
        long long old = calc(a[i-1], a[i]) + calc(a[i], a[i+1]);
        long long newd = calc(a[i-1], a[i+1]);
        long long save = old - newd;
        if(save > max_save){
            max_save = save;
        }
    }

    cout << total - max_save;
    return 0;
}
