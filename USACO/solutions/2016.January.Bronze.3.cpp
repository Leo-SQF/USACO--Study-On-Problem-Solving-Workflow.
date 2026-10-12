#include <iostream>
#include <map>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    
    int N;
    cin >> N;
    
    map<pair<int, int>, int> visit_time;
    int cx = 0, cy = 0;
    int t = 0;
    visit_time[{cx, cy}] = t;
    
    vector<int> deltas;
    
    for(int i = 0; i < N; i++)
    {
        char dir;
        int step;
        cin >> dir >> step;
        
        int dx = 0, dy = 0;
        if(dir == 'N') dy = 1;
        else if(dir == 'S') dy = -1;
        else if(dir == 'E') dx = 1;
        else if(dir == 'W') dx = -1;
        
        for(int s = 0; s < step; s++)
        {
            cx += dx;
            cy += dy;
            t++;
            
			pair<int, int> pos = make_pair(cx, cy);
			if (visit_time.find(pos) != visit_time.end())
			{
			    int diff = t - visit_time[pos];
			    deltas.push_back(diff);
			}
			visit_time[pos] = t;

        }
    }
    
	if(deltas.empty())
	{
	    cout << -1 << endl;
	}
	else
	{
	    int ans = INT_MAX;
	    for(int i = 0; i < deltas.size(); i++)
	    {
	        int d = deltas[i];
	        if(d < ans) ans = d;
	    }
	    cout << ans << endl;
	}
	return 0;
}


