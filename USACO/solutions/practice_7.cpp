#include <iostream>
#include <algorithm>
using namespace std;

struct tap_info
{
	int tap_number;
	int tap_rate;
};
const int MAXN = 1005;
tap_info tap_arr[MAXN];

int main()
{
	int N;
	int Q;
	int L;
	int R;
	int total = 0; 
	
	cin >> N >> Q;
	for (int i = 0; i < N ; i++)
	{

		cin >> tap_arr[i].tap_rate;
	}
	
	for (int a = 1; a <= Q; a++)
	{
		cin >> L >> R;
		
		for (int b = L ; b <= R; b++)
		{
			total += tap_arr[b-1].tap_rate;
		}
		
		cout << total << endl;
	}
	return 0;
}
