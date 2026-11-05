#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1003;
const int INF=0x3f3f3f3f;
bool ditu[N][N];
int dis[N][N][2];
int fx[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
struct node{
    int x;
    int y;
    int jiou;
    node(int x1,int y1,int j){x=x1;y=y1;jiou=j;}
};
int main(){
    int T,i,n,m,j,l,r,k,x1,y1,ans;
    char c;
    queue<node> q;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        scanf("%d %d",&l,&r);
        ans = INF;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin>>c;
                if(c=='0'){ditu[i][j]=0;}
                else{ditu[i][j]=1;}
                dis[i][j][0]=INF;
                dis[i][j][1]=INF;
            }
        }
        dis[1][1][0]=0;
        node u(1,1,0);
        q.push(u);
        while(q.size()){
            u = q.front();
            q.pop();
            k = u.jiou^1;
            for(i=0;i<8;i++){
                x1 = u.x+fx[i][0];
                y1 = u.y+fx[i][1];
                if(1<=x1 && x1<=n && 1<=y1 && y1<=m){
                    if(ditu[x1][y1] && dis[x1][y1][k]>dis[u.x][u.y][u.jiou]+1){
                        dis[x1][y1][k]=dis[u.x][u.y][u.jiou]+1;
                        q.push(node(x1,y1,k));
                    }
                }
            }
        }
        if(dis[n][m][0]<INF){
            j = (dis[n][m][0]-1)/r+1;
            if((r&1)==1 && (j&1)==1 && l==r){j++;}
            ans = min(j,ans);
        }
        if(dis[n][m][1]<INF){
            j = (dis[n][m][1]-1)/r+1;
            if(l==r){
                if((r&1)==0){j=INF;}
                else if((j&1)==0){j++;}
            }
            ans = min(ans,j);
        }
        if(ans<INF){printf("%d\n",ans);}
        else{printf("-1\n");}
    }
    return 0;
}
