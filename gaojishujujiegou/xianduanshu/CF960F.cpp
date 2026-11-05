#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
struct {
    int ls;
    int rs;
    int ma;
}t[N*24];
int ent;
int root[N];
void push_up(int p){
    t[p].ma=max(t[t[p].ls].ma,t[t[p].rs].ma);
}
int chaxun(int p,int pl,int pr,int l,int r){
    if(r<pl || l>pr){return 0;}
    if(p==0){return 0;}
    if(l<=pl && r>=pr){return t[p].ma;}
    int mid=(pl+pr)>>1,ans=0;
    ans = max(ans,chaxun(t[p].ls,pl,mid,l,r));
    ans = max(ans,chaxun(t[p].rs,mid+1,pr,l,r));
    return ans;
}
void update(int & p,int pl,int pr,int x,int d){
    if(p==0){p = ++ent;}
    if(pl==pr){t[p].ma=max(t[p].ma,d);return ;}
    int mid=(pl+pr)>>1;
    if(x<=mid){update(t[p].ls,pl,mid,x,d);}
    else{update(t[p].rs,mid+1,pr,x,d);}
    push_up(p);
}
int main(){
    int n,m,i,ans=0,a,b,w,c,M=100001;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&w);
        c = chaxun(root[a],1,M,1,w)+1;
        ans = max(ans,c);
        update(root[b],1,M,w++,c);
    }
    printf("%d",ans);
    return 0;
}