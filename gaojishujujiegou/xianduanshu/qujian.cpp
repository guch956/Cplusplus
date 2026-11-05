#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500003;
int tree[N<<3];
int tag[N<<3];
struct qujian{
    int duandian;
    bool left;
    int id;
}p[N<<1];
int p1[N][2],ent;
struct node{
    int len;
    int id;
}p2[N];
bool bijiao(qujian & q1,qujian & q2){
    return q1.duandian<q2.duandian;
}
bool bijiao1(node & n1,node & n2){
    return n1.len<n2.len;
}
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int x){tree[x]=max(tree[ls(x)],tree[rs(x)]);}
void addtag(int p,int d){
    tree[p]+=d;
    tag[p]+=d;
}
void push_down(int p){
    addtag(ls(p),tag[p]);
    addtag(rs(p),tag[p]);
    tag[p]=0;
}
void update(int p,int pl,int pr,int l,int r,int d){
    if(l<=pl && r>=pr){addtag(p,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p);
    if(l<=mid){update(ls(p),pl,mid,l,r,d);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,d);}
    push_up(p);
}
void add(int l,bool is){
    ent++;
    p[ent].id=(ent+1)>>1;
    p[ent].duandian=l;
    p[ent].left=is;
}
int main(){
    int n,m,i,j,ans=0x3f3f3f3f,num=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p1[i][0],&p1[i][1]);
        p2[i].len=p1[i][1]-p1[i][0];
        p2[i].id=i;
        add(p1[i][0],1);
        add(p1[i][1],0);
    }
    sort(p+1,p+2*n+1,bijiao);
    p[0].duandian=-1;
    for(i=1;i<=2*n;i++){
        if(p[i].duandian!=p[i-1].duandian){num++;}
        if(p[i].left){p1[p[i].id][0]=num;}
        else{p1[p[i].id][1]=num;}
    }
    sort(p2+1,p2+n+1,bijiao1);
    j = 0;
    for(i=1;i<=n;i++){
        update(1,1,num,p1[p2[i].id][0],p1[p2[i].id][1],1);
        while(1){
            if(j){update(1,1,num,p1[p2[j].id][0],p1[p2[j].id][1],-1);}
            j++;
            if(tree[1]<m){break;}
        }
        j--;
        if(j){update(1,1,num,p1[p2[j].id][0],p1[p2[j].id][1],1);}
        if(tree[1]>=m){
            ans = min(ans,p2[i].len-p2[j].len);
        }
    }
    if(ans==0x3f3f3f3f){ans=-1;}
    printf("%d",ans);
    return 0;
}