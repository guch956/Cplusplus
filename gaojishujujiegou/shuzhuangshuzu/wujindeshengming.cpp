#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=300003;
int n;
ll tree[N];
ll siz[N];
int rankk[N];
int q[N][2];
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d){
    while(x<=n){
        tree[x]+=d;
        x=x+lowbit(x);
    }
}
ll chaxun(int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
struct node{
    int x;
    int bianhao;
}p[N<<1];
bool bijiao(node n1,node n2){
    return n1.x<n2.x;
}
int main(){
    int m,i,a,b;
    ll ans=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        p[2*i-1].x=a;
        p[2*i].x=b;
        p[2*i-1].bianhao=i;
        p[2*i].bianhao=i;
    }
    m = m<<1;
    sort(p+1,p+m+1,bijiao);
    p[0].x=0;
    for(i=1;i<=m;i++){
        if(p[i].x>p[i-1].x+1){
            n++;
            rankk[n]=n;
            siz[n]=p[i].x-p[i-1].x-1;
        }
        if(p[i].x!=p[i-1].x){
            n++;
            rankk[n]=n;
            siz[n]=1;
        }
        if(q[p[i].bianhao][0]){
            q[p[i].bianhao][1]=n;
        }
        else{
            q[p[i].bianhao][0]=n;
        }
    }
    m = m>>1;
    for(i=1;i<=m;i++){
        swap(rankk[q[i][0]],rankk[q[i][1]]);
    }
    for(i=n;i>=1;i--){
        update(rankk[i],siz[i]);
        ans+=siz[i]*chaxun(rankk[i]-1);
    }
    printf("%lld",ans);
    return 0;
}