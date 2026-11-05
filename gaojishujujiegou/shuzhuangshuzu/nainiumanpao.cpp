#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100002;
inline int lowbit(int x){
    return x&(-x);
}
int tree[N];
int n;
void update(int x,int d){
    while(x<=n){
        tree[x] = max(tree[x],d);
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int ans=0;
    while(x!=0){
        ans=max(ans,tree[x]);
        x-=lowbit(x);
    }
    return ans;
}
struct qujian{
    ll begin;
    ll end;
    int id;
};
bool bijiao1(qujian q1,qujian q2){
    return q1.end<q2.end;
}
int rank1[N];
qujian q[N];
int main(){
    int i,a,d,c;
    ll t,v,b;
    cin>>d>>t;
    for(i=1;i<=d;i++){
        a = d+1-i;
        cin>>q[a].begin>>v;
        b = q[a].begin+t*v;
        q[a].end=b;
        q[a].id=a;
    }
    sort(q+1,q+d+1,bijiao1);
    b=-1;
    for(i=1;i<=d;i++){
        if(q[i].end!=b){
            n++;
        }
        rank1[q[i].id]=n;
        b = q[i].end;
    }
    for(i=1;i<=d;i++){
        a = chaxun(rank1[i]);
        a++;
        update(rank1[i],a);
    }
    cout<<chaxun(n);
    return 0;
}