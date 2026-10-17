#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Measurement {
    int day;
    int cow_id; 
    int delta;
};

int get_mask(int milk[], int max_milk) {
    int mask = 0;
    for (int i = 0; i < 3; ++i) {
        if (milk[i] == max_milk) {
            mask |= (1 << i);
        }
    }
    return mask;
}

int main() {

    int N;
    if (!(cin >> N)) return 0;

    vector<Measurement> ms(N);
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> ms[i].day >> name >> ms[i].delta;
        if (name == "Bessie") ms[i].cow_id = 0;
        else if (name == "Elsie") ms[i].cow_id = 1;
        else if (name == "Mildred") ms[i].cow_id = 2;
    }

    sort(ms.begin(), ms.end(), [](const Measurement& a, const Measurement& b) {
        return a.day < b.day;
    });

    int milk[3] = {7, 7, 7};
    int cur_max = 7;
    int cur_mask = get_mask(milk, cur_max);
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        milk[ms[i].cow_id] += ms[i].delta;
        int new_max = max({milk[0], milk[1], milk[2]});
        int new_mask = get_mask(milk, new_max);

        if (new_mask != cur_mask) {
            ans++;
            cur_mask = new_mask;
        }
    }

    cout << ans << "\n";

    return 0;
}
