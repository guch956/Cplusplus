#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int INF=1000000;
int g[51][51];
int fx[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int x;
    int y;
    node(int a,int b){x=a;y=b;}
};
int vis[51][51];
int viss[51][51][4];
int main(){
    int n,m,i,j,t=1,k,x1,y1,ans;
    char c;
    node d(0,0);
    node d1(0,0);
    queue<node> q;
    deque<node> q1;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>c;
            viss[i][j][1]=viss[i][j][2]=viss[i][j][3]=INF;
            if(c=='X'){
                g[i][j]=1;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j] && g[i][j]){
                q = queue<node>();
                q1 = deque<node>();
                vis[i][j]=t;
                q.push(node(i,j));
                while(q.size()){
                    d = q.front();
                    q1.push_back(node(d.x,d.y));
                    viss[d.x][d.y][t]=0;
                    q.pop();
                    for(k=0;k<4;k++){
                        x1=d.x+fx[k][0];
                        y1=d.y+fx[k][1];
                        if(0<=x1 && x1<=n && 0<=y1 && y1<=m && !vis[x1][y1] && g[x1][y1]){
                            vis[x1][y1]=t;
                            q.push(node(x1,y1));
                        }
                    }
                }
                while(q1.size()){
                    d1 = q1.front();
                    q1.pop_front();
                    for(k=0;k<4;k++){
                        x1=d1.x+fx[k][0];
                        y1=d1.y+fx[k][1];
                        if(0<=x1 && x1<=n && 0<=y1 && y1<=m && viss[x1][y1][t]==INF){
                            if(g[d1.x][d1.y] && g[x1][y1]){
                                viss[x1][y1][t]=viss[d1.x][d1.y][t];
                                q1.push_front(node(x1,y1));
                            }
                            else{
                                viss[x1][y1][t]=viss[d1.x][d1.y][t]+1;
                                q1.push_back(node(x1,y1));
                            }
                        }
                    }
                }
                t++;
            }
        }
    }
    ans=INF;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans=min(ans,viss[i][j][1]+viss[i][j][2]+viss[i][j][3]-2);
            
        }
    }
    cout<<ans;
    return 0;
}