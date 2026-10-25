#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Cow 
{
    char dir;
    long long x, y;
    int id;
};

struct Event 
{
    int blocker;
    int blocked;
    long long time; 
};

bool compareEvents(const Event& a, const Event& b) 
{
    return a.time < b.time;
}

int main() 
{
    int N;
    cin >> N;
    vector<Cow> cows(N);
    for (int i = 0; i < N; ++i)
	{
        cin >> cows[i].dir >> cows[i].x >> cows[i].y;
        cows[i].id = i;
    }

    vector<Event> events;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (cows[i].dir == 'N' && cows[j].dir == 'E') 
			{
                if (cows[i].x > cows[j].x && cows[i].y < cows[j].y) 
				{
                    long long dist_N = cows[j].y - cows[i].y;
                    long long dist_E = cows[i].x - cows[j].x;
                    
                    if (dist_N < dist_E) 
					{
                        events.push_back({i, j, dist_E});
                    } else if (dist_E < dist_N) 
					{
                        events.push_back({j, i, dist_N});
                    }
                }
            }
        }
    }
    sort(events.begin(), events.end(), compareEvents);

    vector<long long> ans(N, -1);
    vector<bool> stopped(N, false);

    for (const auto& ev : events) 
	{
        if (stopped[ev.blocker]) continue;
        if (stopped[ev.blocked]) continue;

        stopped[ev.blocked] = true;
        ans[ev.blocked] = ev.time;
    }
    for (int i = 0; i < N; ++i) 
	{
        if (ans[i] == -1) {
            cout << "Infinity\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
    for (int i = 0; i < N; ++i)

    return 0;
}
