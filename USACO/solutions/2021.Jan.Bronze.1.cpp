#include<iostream>
#include<string>
using namespace std;

int main()
{
    string cow;
    cin >> cow;
    int pos[26]; 
    for(int i = 0; i < 26; i++)
    {
        pos[cow[i] - 'a'] = i;
    }

    string hear;
    cin >> hear;

    int ans = 1;
    int len = hear.size();
    for(int i = 1; i < len; i++)
    {
        int prev = pos[ hear[i-1] - 'a' ];
        int now  = pos[ hear[i]   - 'a' ];
        if(now <= prev)
        {
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}

