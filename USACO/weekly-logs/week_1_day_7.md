

#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
    int t, id, s;
};

bool cmp(Student a, Student b){
    return a.t < b.t;
}

int main()
{

    freopen("checkin.in", "r", stdin);
    freopen("checkin.out", "w", stdout);

    int N, K;
    cin >> N >> K;
    Student stu[505];

    for(int i = 0; i < N; i++){
        cin >> stu[i].t >> stu[i].id >> stu[i].s;
    }

    sort(stu, stu + N, cmp);

    int total_score = 0;
    int cnt = 0;
    int last_time = -100000; 

    for(int i = 0; i < N; i++){
        if(stu[i].t - last_time >= K){
            total_score += stu[i].s;
            cnt ++;
            last_time = stu[i].t;
        }
    }

    cout << total_score << " " << cnt << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

