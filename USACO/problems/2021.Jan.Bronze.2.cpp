#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2 == 0) even++;
        else odd++;
    }
    int ans = 0;
    bool need_even = true;
    while(true)
    {
        if (need_even)
        {
            if (even > 0)
            {
                even--;
                ans++;
                need_even = false;
            }
            else if (odd >= 2)
            {
                odd -= 2;
                ans++;
                need_even = false;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (odd >= 1)
            {
                odd--;
                ans++;
                need_even = true;
            }
            else
            {
                break;
            }
        }
    }
    if (odd + even > 0)
    {
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}

