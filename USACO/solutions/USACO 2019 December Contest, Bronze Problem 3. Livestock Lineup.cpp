#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main(){
    vector<string> cows={"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
    int N;cin>>N;
    set<pair<string,string>> cons;
    for(int i=0;i<N;i++){
        string a,b,t;
        cin>>a;
        for(int j=0;j<5;j++)cin>>t;
        cin>>b;
        cons.insert({a,b});
    }
    do{
        bool ok=1;
        for(auto &p:cons){
            string x=p.first,y=p.second;
            int xi=-1,yi=-1;
            for(int i=0;i<8;i++){
                if(cows[i]==x)xi=i;
                if(cows[i]==y)yi=i;
            }
            if(abs(xi-yi)!=1){ok=0;break;}
        }
        if(ok){
            for(auto &s:cows)cout<<s<<endl;
            return 0;
        }
    }while(next_permutation(cows.begin(),cows.end()));
    return 0;
}
