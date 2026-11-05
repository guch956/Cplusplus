#include<iostream>
#include<cstdio>
using namespace std;
const int N=200003;
int win[N][21];
char s[N];
int head[N],to[N],nex[N],ent;
void adde(int u,int v){
    ent++;
    nex[ent]=head[u];
    to[ent]=v;
    head[u]=ent;
}
void solve(){
    int n,m,k,i,a,b,j;
    char c;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%s",s+1);
    for(i=1;i<=n;i++){
        head[i]=0;
        if(s[i]=='A'){win[i][0]=1;}
        else{win[i][0]=0;}
    }
    ent=0;
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        adde(a,b);
    }
    for(j=1;j<=2*k;j++){
        for(i=1;i<=n;i++){
            win[i][j]=j&1;
            for(a=head[i];a;a=nex[a]){
                b = to[a];
                if((win[b][j-1]^j)&1)win[i][j]=(j+1)&1;
            }
        }
    }
    if(win[1][2*k]==1){printf("Alice\n");}
    else{printf("Bob\n");}
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}