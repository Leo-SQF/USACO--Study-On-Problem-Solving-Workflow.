#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
/*	for(int i = 1; i <= N ; i++)
	{
		vector<int>i(N);
		for (int A = 1; A <=N; A++)
		{
			int input;
			cin >> input;
			i.push_back(input)
		}
	}
*/
	int total = N * N;
	vector<int>whole(total);
	for (int i = 1 ; i <= total ; i ++)
	{
		int input;
		cin >> input;
		whole.push_back(input);
	}	
	int count;
	reverse(whole.begin(), whole.end());
	for (int a = 0; a < total ; a++)
	{
		if (whole[a] == 0)
		{
			continue;
		}
		else
		{
			for (int b = 0; b < total; b ++)
			{
				if (whole[b]==0)
				{
					whole[b]= 1;
				}
				else
				{
					whole[b]= 0;
				}
			}
			int left;
			left = total%a;
			if (left == 0) continue;
			else
			{
				continue;
			}
			count = count +1 ;
		}
	}
	cout << cout << endl;
	return 0;
} 
