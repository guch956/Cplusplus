#include<iostream>
#include<algorithm>
#define ll long long 
const int N=50000;
ll tree1[N];ll tree2[N];
int n;
inline int lowbit(int x){return x&(-x);}
void update(int x,ll d,ll t[]){
    while(x<=n){
        t[x]+=d;
        x+=lowbit(x);
    }
}
ll chaxun(int x,ll t[]){
    ll ans=0;
    while(x!=0){
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}
struct node{
    int id;
    ll zhi;
};
bool bijiao(node n1,node n2){
    return n1.zhi<n2.zhi;
}
node q[N];int p[N];
int main(){
    using namespace std;
    int d,i;ll ans;
    cin>>d;
    for(i=1;i<=d;i++){
        cin>>q[i].zhi;
        q[i].id=i;
    }
    sort(q+1,q+d+1,bijiao);
    ans=-1;
    for(i=1;i<=d;i++){
        if(q[i].zhi!=ans){
            n++;
        }
        p[q[i].id]=n;
        ans=q[i].zhi;
    }
    ans=0;
    for(i=1;i<=d;i++){
        ans+=chaxun(p[i]-1,tree1);
        update(p[i],1,tree2);
        update(p[i],chaxun(p[i]-1,tree2),tree1);
    }
    cout<<ans;
    return 0;
}