#include<iostream>
#include<queue>
using namespace std;
int m,n;const int INF = 0x3f3f3f3f;
struct dian{
    int x;
    int y;
};
int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
char g[502][502];
int vis[502][502];
void jisuan(int s1,int s2){
    deque<dian> q;
    int i,j,x1,y1;
    dian d1,d2;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            vis[i][j] = INF;
        }
    }
    d1.x = s1;d1.y = s2;
    vis[s1][s2] = 0;
    q.push_back(d1);
    while(q.size()){
        d1 = q.front();
        q.pop_front();
        for(i=0;i<=3;i++){
            x1 = d1.x+d[i][0];
            y1 = d1.y+d[i][1];
            if(1<=x1 && x1<=n && 1<=y1 && y1<=m){
                if(vis[x1][y1]==INF){
                    if(g[d1.x][d1.y]==g[x1][y1]){
                        vis[x1][y1] = vis[d1.x][d1.y];
                        d2.x = x1;
                        d2.y = y1;
                        q.push_front(d2);
                    }
                    else{
                        vis[x1][y1] = vis[d1.x][d1.y]+1;
                        d2.x = x1;
                        d2.y = y1;
                        q.push_back(d2);
                    }
                }
            }
        }
    }
}
int main(){
    int i,j,t1,t2,t3,t4;
    while(1){
        cin>>n>>m;
        if(n==0){
            break;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>g[i][j];
            }
        }
        cin>>t1>>t2>>t3>>t4;
        t1++;t2++;t3++;t4++;
        jisuan(t1,t2);
        cout<<vis[t3][t4]<<endl;
    }
    return 0;
}