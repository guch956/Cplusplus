#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int P=1e8-3;
const int N=100003;
struct huochai{
    int a;
    int b;
    int id;
}p[N];
bool bijiaoa(huochai & h1,huochai & h2){
    return h1.a<h2.a;
}
bool bijiaob(huochai & h1,huochai & h2){
    return h1.b<h2.b;
}
inline int lowbit(int x){return x&(-x);}
int tree[N];
int weizhi[N];
int zhi[N];
int n;
void update(int x,int d){
    while(x<=n){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x){
    int an=0;
    while(x){
        an+=tree[x];
        x-=lowbit(x);
    }
    return an;
}
int main(){
    int i;
    int ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&p[i].a);
        p[i].id=i+1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&p[i].b);
    }
    sort(p,p+n,bijiaoa);
    for(i=0;i<n;i++){
        weizhi[i+1]=p[i].id;
    }
    sort(p,p+n,bijiaob);
    for(i=0;i<n;i++){
        zhi[p[i].id]=weizhi[i+1];
    }
    for(i=n;i>=1;i--){
        ans+=chaxun(zhi[i]);
        update(zhi[i],1);
        ans%=P;
    }
    cout<<ans;
    return 0;
}