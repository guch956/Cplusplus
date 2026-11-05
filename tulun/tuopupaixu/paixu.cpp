#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int g[30][30];
int rudu[30];
int pailie[30];
bool exist[30];
int check(int nu1,int nu){
    int i,n=26;
    int ru[30],zt=1,u,m=0;
    queue<int> q;
    for(i=1;i<=n;i++){ru[i]=rudu[i];}
    for(i=1;i<=n;i++){if(ru[i]==0 && exist[i])q.push(i);}
    while(q.size()){
        u = q.front();
        q.pop();
        m++;
        pailie[m]=u;
        if(q.size()){zt=0;}
        for(i=1;i<=n;i++){
            if(g[u][i] && exist[i]){
                ru[i]--;
                if(ru[i]==0){q.push(i);}
            }
        }
    }
    if(m<nu1){return 2;}
    if(m<nu){zt=0;}
    return zt;
}
int main(){
    int n,m,i,a,b,k,n1=0;
    int zhuangtai=0;
    char s[4];
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%s",s);
        a = s[0]-'A'+1;b = s[2]-'A'+1;
        if(!g[b][a]){
            g[b][a]=1;
            rudu[a]++;
            if(!exist[a])n1++;
            if(!exist[b])n1++;
            exist[a]=exist[b]=1;
            if(zhuangtai==0){
                zhuangtai=check(n1,n);
                k = i;
            }
        }
    }
    if(zhuangtai==0){
        printf("Sorted sequence cannot be determined.");
    }
    else if(zhuangtai==1){
        printf("Sorted sequence determined after %d relations: ",k);
        for(i=26;i>=1;i--){
            if(exist[pailie[i]]){printf("%c",pailie[i]+'A'-1);}
        }
        printf(".");
    }
    else{
        printf("Inconsistency found after %d relations.",k);
    }
    return 0;
}
