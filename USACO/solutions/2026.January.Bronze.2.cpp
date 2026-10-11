#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> position;
    for(int i = 0; i < N ; i ++)
    {
        int X;
        cin >> X;
        position.push_back(X);
    }
    sort(position.begin(), position.end());
    
    int max_exploded = 0;
    for(int start = 0; start < N; start++)
    {
        vector<bool> exploded(N, false);
        exploded[start] = true;
        int t = 1;
        while(true)
        {
            vector<int> new_explode;
            for(int i = 0; i < N; i++)
            {
                if(exploded[i]) continue;
                for(int j = 0; j < N; j++)
                {
                    if(exploded[j])
                    {
                        if( abs(position[i] - position[j]) <= t )
                        {
                            new_explode.push_back(i);
                            break;
                        }
                    }
                }
            }
            if(new_explode.empty()) break;
            for(int k = 0; k < new_explode.size(); k++)
            {
                int idx = new_explode[k];
                exploded[idx] = true;
            }
            t++;
        }
        int cnt = 0;
        for(int k = 0; k < exploded.size(); k++)
        {
            if(exploded[k]) cnt++;
        }
        if(cnt > max_exploded) max_exploded = cnt;
    }
    cout << max_exploded << endl;
    return 0;
}

