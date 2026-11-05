#include<cstdio>
const int N=100002;
struct node
{
    double sum;
    double squ;
};
node tree[N<<2];
double tag[N<<2];
double q[N];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p){
    tree[p].sum=tree[ls(p)].sum+tree[rs(p)].sum;
    tree[p].squ=tree[ls(p)].squ+tree[rs(p)].squ;
}
void addtag(int p,double len,double d){
    tree[p].squ+=2*d*tree[p].sum+len*d*d;
    tree[p].sum+=len*d;
    tag[p]+=d;
}
void push_down(int p,int len){
    addtag(ls(p),(len+1)>>1,tag[p]);
    addtag(rs(p),len>>1,tag[p]);
    tag[p]=0;
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p].sum=q[pl];
        tree[p].squ=q[pl]*q[pl];
        tag[p]=0;
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int l,int r,double d){
    if(l<=pl && r>=pr){addtag(p,pr-pl+1,d);return ;}
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1);
    if(l<=mid)update(ls(p),pl,mid,l,r,d);
    if(r>mid)update(rs(p),mid+1,pr,l,r,d);
    push_up(p);
}
node chaxun(int p,int pl,int pr,int l,int r){
    if(l<=pl && r>=pr){return tree[p];}
    int mid=(pl+pr)>>1;node ans,a;
    ans.squ=0;ans.sum=0;
    push_down(p,pr-pl+1);
    if(l<=mid){
        a=chaxun(ls(p),pl,mid,l,r);
        ans.squ+=a.squ;ans.sum+=a.sum;
    }
    if(r>mid){
        a=chaxun(rs(p),mid+1,pr,l,r);
        ans.squ+=a.squ;ans.sum+=a.sum;
    }
    return ans;
}
int main(){
    int n,m,i,a,b,k;node x;
    double d;
    /*freopen("P1471_2.in","r",stdin);
    freopen("P1471_2.out","w",stdout);*/
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lf",&q[i]);
    }
    build(1,1,n);
    while(m--){
        scanf("%d %d %d",&k,&a,&b);
        if(k==1){
            scanf("%lf",&d);
            update(1,1,n,a,b,d);
        }
        else if(k==2){
            x = chaxun(1,1,n,a,b);
            printf("%.4lf\n",x.sum/(b-a+1));
        }
        else{
            x = chaxun(1,1,n,a,b);
            d = (x.squ-x.sum*x.sum/(b-a+1))/(b-a+1);
            printf("%.4lf\n",d);
        }
    }
    return 0;
}