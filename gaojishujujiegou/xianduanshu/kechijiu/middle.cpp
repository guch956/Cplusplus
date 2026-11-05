#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20003;
const int INF=0x3f3f3f3f;
int tma[N<<6],tmi[N<<6],tag[N<<6],ls[N<<6],rs[N<<6];
int root[N];
int ent;
void push_up(int p){
    tma[p]=max(tma[ls[p]],tma[rs[p]])+tag[p];
    tmi[p]=min(tmi[ls[p]],tmi[rs[p]])+tag[p];
}
void build(int & r,int pl,int pr){
    r = ++ent;
    if(pl==pr){tma[r]=tmi[r]=-pl;return ;}
    int mid=(pl+pr)>>1;
    build(ls[r],pl,mid);
    build(rs[r],mid+1,pr);
    push_up(r);
}
void add(int & now,int last,int pl,int pr,int l,int r){
    now = ++ent;
    if(l<=pl && r>=pr){
        tag[now]=tag[last]+2;
        tma[now]=tma[last]+2;
        tmi[now]=tmi[last]+2;
        ls[now]=ls[last];
        rs[now]=rs[last];
        return;
    }
    int mid=(pl+pr)>>1;
    tag[now]=tag[last];
    if(l<=mid && r>mid){
        add(ls[now],ls[last],pl,mid,l,r);
        add(rs[now],rs[last],mid+1,pr,l,r);
    }
    else{
        if(l<=mid){
            add(ls[now],ls[last],pl,mid,l,r);
            rs[now]=rs[last];
        }
        else{
            add(rs[now],rs[last],mid+1,pr,l,r);
            ls[now]=ls[last];
        }
    }
    push_up(now);
}
int chaxun1(int ro,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tma[ro];}
    int mid=(pl+pr)>>1,ans=-INF;
    if(l<=mid){ans = max(ans,chaxun1(ls[ro],pl,mid,l,r));}
    if(r>mid){ans = max(ans,chaxun1(rs[ro],mid+1,pr,l,r));}
    ans+=tag[ro];
    return ans;
}
int chaxun2(int ro,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tmi[ro];}
    int mid=(pl+pr)>>1,ans=INF;
    if(l<=mid){ans = min(ans,chaxun2(ls[ro],pl,mid,l,r));}
    if(r>mid){ans = min(ans,chaxun2(rs[ro],mid+1,pr,l,r));}
    ans+=tag[ro];
    return ans;
}
struct node{
    int val;
    int id;
}p[N];
bool bijiao(node & n1,node & n2){
    return n1.val<n2.val;
}
int main(){
    int n,i,q,l,r,mid,a;
    int ch[4],last=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].val);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    build(root[n+1],1,n);
    for(i=n;i>=1;i--){
        add(root[i],root[i+1],1,n,p[i].id,n);
    }
    scanf("%d",&q);
    while(q--){
        for(i=0;i<4;i++){scanf("%d",&ch[i]);}
        for(i=0;i<4;i++){ch[i]=(ch[i]+last)%n;ch[i]++;}
        sort(ch,ch+4);
        l = 1;r = n;
        while(l<r){
            mid=(l+r+1)>>1;
            if(ch[0]==1){a = min(0,chaxun2(root[mid],1,n,1,ch[1]-1));}
            else{a = chaxun2(root[mid],1,n,ch[0]-1,ch[1]-1);}
            if(chaxun1(root[mid],1,n,ch[2],ch[3])>=a){l = mid;}
            else{r = mid-1;}
        }
        last = p[l].val;
        printf("%d\n",last);
    }
    return 0;
}
