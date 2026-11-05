#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002;
struct node{
    int ls;
    int rs;
    int sum;
};
struct y
{
    int zhi;
    int id;
};
int root[N];y p[N];int q[N];
node stack[N<<5];int ent=0;
void newnode(int v){
    ent++;
    stack[ent].sum=v;
    stack[ent].ls=0;stack[ent].rs=0;
}
int build(int oldp,int pl,int pr,int x){
    newnode(stack[oldp].sum+1);
    if(pl==pr){
        return ent;
    }
    int mid=(pl+pr)>>1,c=ent;
    if(x<=mid){
        stack[c].rs=stack[oldp].rs;
        stack[c].ls=build(stack[oldp].ls,pl,mid,x);
    }
    else{
        stack[c].ls=stack[oldp].ls;
        stack[c].rs=build(stack[oldp].rs,mid+1,pr,x);
    }
    return c;
}
int chaxun(int oldp,int newp,int pl,int pr,int k){
    if(pl==pr){return pl;}
    int mid=(pl+pr)>>1,c=stack[stack[newp].ls].sum-stack[stack[oldp].ls].sum;
    if(k<=c){
        return chaxun(stack[oldp].ls,stack[newp].ls,pl,mid,k);
    }
    else{
        return chaxun(stack[oldp].rs,stack[newp].rs,mid+1,pr,k-c);
    }
}
bool bijiao(y y1,y y2){
    return y1.zhi<y2.zhi;
}
int main(){
    int n,m,i,l,r;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].zhi);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<=n;i++){
        q[p[i].id]=i;
    }
    for(i=1;i<=n;i++){
        root[i]=build(root[i-1],1,n,q[i]);
    }
    while(m){
        scanf("%d %d %d",&l,&r,&i);
        printf("%d\n",p[chaxun(root[l-1],root[r],1,n,i)].zhi);
        m--;
    }
    return 0;
}