# Daily Experiment Log
Week:1 | Day:7
Date: 2026-10-5
Active modeling version: v0.0

## 1. Today's Experiment Objective
What is the goal of today’s experiment?
Example: Test 2 Bronze greedy problems using the 5-step modeling process.

Pre-set hypothesis:
none

Selected problems for today:
1. practice.5

## 2. Experiment Records
| Problem Link | Modeling Time | Coding Time | Debug Time | Result (AC/WA/TLE) | Bug Type (A/B/C/D) |

| ---- | 5min | 12min | 5min | AC | ---- |
|  |  |  |  |  |  |

## 3. Review after solving all problems
Compare predicted edge cases and real bugs:
__had not perdicted______________________________________

Did the 5-step modeling process help catch errors in advance?
___no , same as last time_____________________________________

Suggestions to improve the modeling workflow (save for weekly review, DO NOT modify Methodology.md today):
___none_____________________________________

## 4. Quick Reflection
Which step of the 5-step process worked poorly today?
___none_____________________________________

## 5. Git & File Update Check
- [ ] New problem markdown added to /problems
- [ ] Source code added to /solutions
- [ ] This daily log saved
- [ ] Git commit completed

## 6. Tomorrow's Simple Plan
_____work is below___________________________________

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

