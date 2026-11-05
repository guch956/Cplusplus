#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int P=1e9+1;
int dp[20][250];
long long ans[1000];
int vaild[12][250];
int geshu[12];
int lie[20];
bool finish[100003];
struct node{
    int zhi;
    int mi2;
    node(int m2,int z){mi2=m2;zhi=z;}
    bool operator<(const node & n1)const{
        return zhi>n1.zhi;
    }
};
void init(){
    int i,m,j,num,k;
    for(i=1;i<=11;i++){
        m = 1<<i;num = 0;
        for(j=0;j<m;j++){
            for(k=0;k<i;k++){
                if(j&(1<<k) && j&(1<<(k+1))){break;}
            }
            if(k==i){vaild[i][num++]=j;}
        }
        geshu[i]=num;
    }
}
void update(int k){
    int i,j;
    if(k==0){
        for(i=0;i<geshu[lie[0]];i++)dp[0][i]=1;
        return ;
    }
    for(i=0;i<geshu[lie[k]];i++){
        dp[k][i]=0;
        for(j=0;j<geshu[lie[k-1]];j++){
            if((vaild[lie[k]][i]&vaild[lie[k-1]][j])==0){
                dp[k][i]=(dp[k][i]+dp[k-1][j])%P;
            }
        }
    }
}
int fa[100003];
int siz[100003];
int find(int x){
    if(fa[x]!=x){fa[x]=find(fa[x]);}
    return fa[x];
}
void hebing(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b){
        fa[b]=a;
        siz[a]+=siz[b];
    }
}
int main(){
    int n,i,ma2,num=0;
    long long an=1;
    node u(0,1);
    ma2=0;
    priority_queue<node> q;
    init();
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        fa[i]=i;siz[i]=1;
    }
    q.push(u);
    while(1){
        u = q.top();
        q.pop();
        if(u.zhi>n){break;}
        if(finish[u.zhi]){continue;}
        finish[u.zhi]=1;
        num++;
        ma2 = max(ma2,u.mi2);
        lie[u.mi2]++;
        for(i=u.mi2;i<=ma2;i++){update(i);}
        for(i=0;i<geshu[lie[ma2]];i++){
            ans[num]=(ans[num]+dp[ma2][i])%P;
        }
        q.push(node(u.mi2+1,u.zhi*2));
        q.push(node(u.mi2,u.zhi*3));
    }
    for(i=1;i<=n;i++){
        if(i%2==0){hebing(i,i/2);}
        if(i%3==0){hebing(i,i/3);}
    }
    for(i=1;i<=n;i++){
        if(fa[i]==i){
            an = an*ans[siz[i]]%P;
        }
    }
    printf("%lld",an);
    return 0;
}