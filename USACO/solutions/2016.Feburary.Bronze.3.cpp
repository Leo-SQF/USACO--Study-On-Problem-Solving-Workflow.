#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

struct Cow {
    int x, y;
};

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B;
    cin >> N >> B;
    vector<Cow> cows(N);
    set<int> a_candidates, b_candidates;

    for (int i = 0; i < N; ++i) {
        cin >> cows[i].x >> cows[i].y;
        a_candidates.insert(cows[i].x + 1);
        b_candidates.insert(cows[i].y + 1);
    }

    int ans = INT_MAX;

    set<int>::iterator itA;
    for (itA = a_candidates.begin(); itA != a_candidates.end(); ++itA) {
        int a = *itA;

        set<int>::iterator itB;
        for (itB = b_candidates.begin(); itB != b_candidates.end(); ++itB) {
            int b = *itB;

            int bl = 0, tl = 0, br = 0, tr = 0;
            for (int i = 0; i < N; i++) {
                int x = cows[i].x;
                int y = cows[i].y;
                if (x < a) {
                    if (y < b) bl++;
                    else tl++;
                } else {
                    if (y < b) br++;
                    else tr++;
                }
            }
            int current_max = max( max(bl, tl), max(br, tr) );
            ans = min(ans, current_max);
        }
    }

    cout << ans << endl;
    return 0;
}

