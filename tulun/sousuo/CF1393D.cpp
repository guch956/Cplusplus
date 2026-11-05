#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
const int N=2003;
ll dis[N][N];
char A[N][N];
int fx[4][2];
int main(){
    int n,m,i,j,x,y,k,a,x1,y1;
    ll ans=0;
    queue<int> q;
    char c;
    fx[0][0]=1;
    fx[1][1]=1;
    fx[2][0]=-1;
    fx[3][1]=-1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dis[i][j]=0x3f3f3f3f;
            c = getchar();
            while(c<'a' || c>'z'){c = getchar();}
            A[i][j] = c;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            a = 0;
            for(k=0;k<4;k++){
                x = i+fx[k][0];
                y = j+fx[k][1];
                if(A[i][j]!=A[x][y]){
                    a = 1;
                }
            }
            if(a){
                dis[i][j]=1;
                q.push((i-1)*m+j-1);
            }
        }
    }
    while(q.size()){
        a = q.front();
        q.pop();
        x = a/m+1;
        y = a%m+1;
        for(k=0;k<4;k++){
            x1 = x+fx[k][0];
            y1 = y+fx[k][1];
            if(1<=x1 && x1<=n && 1<=y1 && y1<=m){
                if(dis[x1][y1]>dis[x][y]+1){
                    dis[x1][y1]=dis[x][y]+1;
                    q.push((x1-1)*m+y1-1);
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            ans+=dis[i][j];
        }
    }
    printf("%lld",ans);
    return 0;
}
