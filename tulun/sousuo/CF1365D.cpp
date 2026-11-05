#include<iostream>
#include<cstdio>
using namespace std;
const int N=53;
int huai[N][N];
int hao[N][N];
int ditu[N][N];
void dfs1(int x,int y){
    if(huai[x][y]==0 || ditu[x][y]==0 || hao[x][y]==1){return ;}
    hao[x][y]=1;
    dfs1(x+1,y);
    dfs1(x-1,y);
    dfs1(x,y-1);
    dfs1(x,y+1);
}
void dfs(int x,int y){
    if(huai[x][y]==0){return ;}
    huai[x][y]=0;
    if(ditu[x][y]!=3){return ;}
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int main(){
    int T,n,m,i,a,j;
    char c;
    bool xing;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        xing=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                c = getchar();
                huai[i][j]=1;
                while(c!='.' && c!='#' && c!='G' && c!='B'){c=getchar();}
                if(c=='.'){ditu[i][j]=1;}
                else if(c=='#'){ditu[i][j]=0;}
                else if(c=='G'){ditu[i][j]=2;}
                else{ditu[i][j]=3;}
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(ditu[i][j]==3){dfs(i,j);}
            }
        }
        dfs1(n,m);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(ditu[i][j]==2 && hao[i][j]==0){xing=0;}
                ditu[i][j]=0;
                huai[i][j]=0;
                hao[i][j]=0;
            }
        }
        if(xing){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}