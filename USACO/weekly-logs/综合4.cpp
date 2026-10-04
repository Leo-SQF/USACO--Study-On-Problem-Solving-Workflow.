#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct Cow
{
	int id, x , y , h ;
};

int main()
{
	freopen("cowparty.in","r",stdin);
    freopen("cowparty.out","w",stdout);
    int N , D ;
    cin >> N >> D ;
    Cow cow[505];
    for (int i = 1 ; i <= N ; i ++)
    {
    	cin >> cow[i].x >> cow[i].y >> cow[i].h;
    	cow[i].id = i;
	}
	
	int h_max = -1;
	int dist_min;
	int a,b;
	for (int i = 1; i <= N ; i ++)
	{
		for (int j = i + 1 ; j <= N ; j ++)
		{
			int dist = abs(cow[i].x - cow [j].x) + abs(cow[i].y -cow[j].y);
			if (dist > D) continue;	
			
			int h_value = cow[i].h + cow[j].h;
			if (h_value > h_max || 
			(h_value == h_max && dist < dist_min)  || 
			(h_value == h_max && dist == dist_min && cow[i].id < a))
			{
                h_max = h_value;
                dist_min = dist;
                a = cow[i].id;
                b = cow[j].id;
			}
		}
	}
	if(h_max == -1)
	{
        cout << "NO PAIR" << endl;
    }
	else
	{
        cout << a << " " << b << " " << h_max << " " << dist_min << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
	
} 

