#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100003;
ll jiazhi[N][11];
struct node1{
    int id;
    ll chu;
}c[N];
bool bijiao(node1 & n1,node1 & n2){
    return n1.chu<n2.chu;
}
struct node{
    int id;
    ll v;
    bool operator<(const node & n1)const{
        return v>n1.v;
    }
    node(int i1,ll v1){id=i1;v=v1;}
};
struct {
    int id;
    int geshu;
    int down,up;
}p[N<<7];
int main(){
    int n,i,j,m,k,num;
    ll s=0,ans=0;
    node u(1,0);
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        scanf("%lld",&chu[i]);
        s+=chu[i];
        for(j=2;j<=m;j++){
            scanf("%lld",&jiazhi[i][j]);
        }
    }
    return 0;
}
