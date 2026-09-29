#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Point {
    int r, c;
};
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
char grid[10][10];
int dist[10][10];

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int br, bc, lr, lc;
    for(int i=0;i<10;i++){
        string s; cin>>s;
        for(int j=0;j<10;j++){
            grid[i][j]=s[j];
            if(grid[i][j]=='B') br=i, bc=j;
            if(grid[i][j]=='L') lr=i, lc=j;
            dist[i][j]=-1;
        }
    }
    queue<Point> q;
    // multi-source: cells adjacent to lake L
    for(int d=0;d<4;d++){
        int nr=lr+dr[d], nc=lc+dc[d];
        if(nr>=0&&nr<10&&nc>=0&&nc<10 && grid[nr][nc]=='.'){
            dist[nr][nc]=1;
            q.push({nr,nc});
        }
    }
    while(!q.empty()){
        Point p = q.front(); q.pop();
        int r=p.r, c=p.c;
        // check if current cell is adjacent to Barn B
        bool nearBarn = false;
        for(int d=0;d<4;d++){
            int nr = r+dr[d], nc=c+dc[d];
            if(nr==br && nc==bc) nearBarn=true;
        }
        if(nearBarn){
            cout << dist[r][c] << endl;
            return 0;
        }
        for(int d=0;d<4;d++){
            int nr=r+dr[d], nc=c+dc[d];
            if(nr>=0&&nr<10&&nc>=0&&nc<10 && grid[nr][nc]=='.' && dist[nr][nc]==-1){
                dist[nr][nc] = dist[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    return 0;
}
