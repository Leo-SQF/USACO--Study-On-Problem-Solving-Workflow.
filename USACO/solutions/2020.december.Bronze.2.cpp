#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i = 0; i < N; i++) 
	{
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++) 
	{
        int sum = 0;
        for(int j = i; j < N; j++) 
		{
            sum += p[j];
            int len = j - i + 1;
            if(sum % len != 0) continue;
            int avg = sum / len;
            bool found = false;
            for(int k = i; k <= j; k++) 
			{
                if(p[k] == avg) 
				{
                    found = true;
                    break;
                }
            }
            if(found) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
