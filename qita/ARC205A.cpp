#include<iostream>
#include<cstdio>
using namespace std;
const int N=503;
int sum[N][N];
char s[N][N];
int main(){
    int n,i,j,q,a,b,x,y;
    char c;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            c = getchar();
            while(c!='#' && c!='.'){c = getchar();}
            s[i][j]=c;
            if(s[i][j]=='.' && s[i-1][j]=='.' && s[i-1][j-1]=='.' && s[i][j-1]=='.'){
                sum[i][j]=1;
            }
            sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    while(q--){
        scanf("%d %d %d %d",&a,&b,&x,&y);
        printf("%d\n",sum[b][y]-sum[a][y]-sum[b][x]+sum[a][x]);
    }
    return 0;
}