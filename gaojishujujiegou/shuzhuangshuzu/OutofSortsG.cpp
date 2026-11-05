#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
inline int lowbit(int x){return x&(-x);}
int tree[N][2];
int n;
void update(int x,int d,int k){
    while(x<=n){
        tree[x][k]+=d;
        x+=lowbit(x);
    }
}
int chaxun(int x,int k){
    int a=0;
    while(x){
        a+=tree[x][k];
        x-=lowbit(x);
    }
    return a;
}
struct node{
    int id;
    int zhi;
}p[N];
bool bijiao(node n1,node n2){
    return n1.zhi==n2.zhi?n1.id<n2.id:n1.zhi<n2.zhi;
}
int A[N];
int main(){
    int i,j,ans=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].zhi);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){
        A[p[i].id]=i;
        update(i,1,1);
    }
    j=0;
    for(i=1;i<n;i++){
        update(A[i],1,0);
        update(A[i],-1,1);
        while(chaxun(j+1,0)+chaxun(j+1,1)<=i){
            j++;
        }
        ans=max(ans,max(chaxun(j,1),i-chaxun(j+1,0)));
    }
    printf("%d",ans);
    return 0;
}

