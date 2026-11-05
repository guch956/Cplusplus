#include<iostream>
#include<cstdio>
const int N=100003;
struct {
    int sum;
    int tag;
}tree[N<<2][26];
int q[N];
int num[26];
int n;
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
void push_up(int p,int k){
    tree[p][k].sum=tree[ls(p)][k].sum+tree[rs(p)][k].sum;
}
void addtag(int p,int len,int x,int k){
    tree[p][k].sum=x*len;
    tree[p][k].tag=x;
}
void push_down(int p,int len,int k){
    if(tree[p][k].tag!=-1){
        addtag(ls(p),(len+1)>>1,tree[p][k].tag,k);
        addtag(rs(p),len>>1,tree[p][k].tag,k);
        tree[p][k].tag=-1;
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p][q[pl]].sum=1;
        return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    for(int i=0;i<=25;i++){
        tree[p][i].tag=-1;
        push_up(p,i);
    }
}
void update(int p,int pl,int pr,int l,int r,int x,int k){
    if(l<=pl && r>=pr){
        addtag(p,pr-pl+1,x,k);
        return ;
    }
    int mid=(pl+pr)>>1;
    push_down(p,pr-pl+1,k);
    if(l<=mid){update(ls(p),pl,mid,l,r,x,k);}
    if(r>mid){update(rs(p),mid+1,pr,l,r,x,k);}
    push_up(p,k);
}
int chaxun(int p,int pl,int pr,int l,int r,int k){
    if(l<=pl && r>=pr){return tree[p][k].sum;}
    int mid=(pl+pr)>>1,ans=0;
    push_down(p,pr-pl+1,k);
    if(l<=mid){ans+=chaxun(ls(p),pl,mid,l,r,k);}
    if(r>mid){ans+=chaxun(rs(p),mid+1,pr,l,r,k);}
    return ans;
}
void caozuo(int l,int r){
    int i,s=-1,a=0;
    for(i=0;i<=25;i++){
        num[i]=chaxun(1,1,n,l,r,i);
        if(num[i]%2==1){
            if(s!=-1){
                return;
            }
            s = i;
        }
    }
    for(i=0;i<=25;i++){
        if(num[i]>0){
            update(1,1,n,l,r,0,i);
            if(i==s){
                update(1,1,n,(l+r-num[i]+1)/2,(l+r+num[i]-1)/2,1,i);
            }
            else{
                update(1,1,n,l+a,l+a+(num[i]/2)-1,1,i);
                update(1,1,n,r-a-(num[i]/2)+1,r-a,1,i);
                a+=num[i]/2;
            }
        }
    }
}
void dfs(int p,int pl,int pr){
    if(pl==pr){
        for(int i=0;i<=25;i++){
            if(tree[p][i].sum==1){
                q[pl]=i;
            }
        }
        return ;
    }
    int mid=(pl+pr)>>1;
    dfs(ls(p),pl,mid);
    dfs(rs(p),mid+1,pr);
}
int main(){
    int m,i,a,b;
    char c;
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%c",&c);
        q[i]=c-'a';
    }
    build(1,1,n);
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        caozuo(a,b);
    }
    dfs(1,1,n);
    for(i=1;i<=n;i++){
        printf("%c",q[i]+'a');
    }
    return 0;
}