#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second){

        return a.second > b.second;
    }else{

        return a.first < b.first;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > cows(N);
    for(int i=0; i<N; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows.begin(), cows.end(), cmp);

    vector<int> selected;
    for(int i=0; i<K; i++){
        selected.push_back(cows[i].first);
    }

    sort(selected.begin(), selected.end());

    for(int i=0; i<selected.size(); i++){
        cout << selected[i] << " ";
    }
    return 0;
}

