#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500000;
int tree[N+2][2];
int ans=0x3f3f3f3f;
inline int lowbit(int x){return x&(-x);}
struct point{
    int x;
    int y;
}p[N];
int n;
bool bijiao(point po1,point po2){
    return po1.y<po2.y;
}
void update(int x,int k,int d){
    while(x<=N){
        tree[x][k]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x,int k){
    int ans=0;
    while(x>0){
        ans+=tree[x][k];
        x-=lowbit(x);
    }
    return ans;
}
void erfen(){
    int l=1,r=N,mid,s0,s1,s,r0=chaxun(N,0),r1=chaxun(N,1);
    while(l<r){
        mid=(l+r)>>1;
        s0=chaxun(mid,0);s1=chaxun(mid,1);
        s = max(s0,s1);
        if(s+s0 > r0 && s+s1 > r1){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    s0=chaxun(l,0);s1=chaxun(l,1);
    ans=min(ans,max(s0,s1));
    s0=r0-chaxun(l-1,0);s1=r1-chaxun(l-1,1);
    ans=min(ans,max(s0,s1));
}
int main(){
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        p[i].x=(a+1)/2;
        p[i].y=(b+1)/2;
        update(p[i].x,1,1);
    }
    sort(p+1,p+n+1,bijiao);
    b = 1;
    for(i=1;i<=N;i++){
        for(a=b;p[a].y==i;a++){
            update(p[a].x,0,1);
            update(p[a].x,1,-1);
        }
        erfen();
        b = a;
    }
    cout<<ans;
    return 0;
}