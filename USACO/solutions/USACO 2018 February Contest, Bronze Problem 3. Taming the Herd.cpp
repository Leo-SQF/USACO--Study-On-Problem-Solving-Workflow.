#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> log(N);
    for(int i = 0; i < N; i++) 
	{
        cin >> log[i];
    }
    if(log[0] != -1 && log[0] != 0) 
	{
        cout << -1 << endl;
        return 0;
    }
    log[0] = 0;

    bool ok = true;
    vector<int> arr = log;
    for(int i = 0; i < N; i++) 
	{
        if(arr[i] > 0) 
		{
            int last = i - arr[i];
            if(last < 0) { ok = false; break; }
            for(int d = 0; d <= arr[i]; d++) 
			{
                int pos = last + d;
                if(arr[pos] != -1 && arr[pos] != d) 
				{
                    ok = false;
                }
                arr[pos] = d;
            }
        }
    }
    if(!ok) 
	{
        cout << -1 << endl;
        return 0;
    }

    int minB = 0, maxB = 0;
    for(int i = 0; i < N; i++) 
	{
        if(arr[i] == 0) 
		{
            minB++;
            maxB++;
        } 
		else if(arr[i] == -1) 
		{
            maxB++;
        }
    }
    cout << minB << " " << maxB << endl;
    return 0;
}
