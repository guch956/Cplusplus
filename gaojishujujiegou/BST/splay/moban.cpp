#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6;
struct {
    int fa;
    int ls;
    int rs;
    int val;
    int siz;
    int cishu;
}t[N];
int ent,root;
void push(int x){t[x].siz=t[t[x].ls].siz+t[t[x].rs].siz+t[x].cishu;}
int isleft(int x){return x==t[t[x].fa].ls;}
int newnode(int v){
    ent++;
    t[ent].val=v;
    t[ent].siz=1;
    t[ent].cishu=1;
    return ent;
}
void rotate(int x){
    int f=t[x].fa,g=t[f].fa,son=isleft(x);
    if(son==1){/*右旋*/
        t[f].ls=t[x].rs;
        if(t[x].rs){t[t[x].rs].fa=f;}
        t[x].rs=f;
    }
    else{
        t[f].rs=t[x].ls;
        if(t[x].ls){t[t[x].ls].fa=f;}
        t[x].ls=f;
    }
    t[f].fa=x;
    t[x].fa=g;
    if(f==t[g].ls){t[g].ls=x;}
    if(f==t[g].rs){t[g].rs=x;}
    push(f);
    push(x);
}
void splay(int x,int goal){
    if(goal==0){root=x;}
    int f,g;
    while(1){
        f = t[x].fa;
        g = t[f].fa;
        if(f==goal){break;}
        if(g!=goal){
            if(isleft(f)==isleft(x)){rotate(f);}
            else{rotate(x);}
        }
        rotate(x);
    }
}
int kth(int k){
    int x=root;
    while(1){
        if(k<=t[t[x].ls].siz){x = t[x].ls;}
        else if(k>t[t[x].ls].siz+t[x].cishu){
            k-=t[t[x].ls].siz+t[x].cishu;
            x = t[x].rs;
        }
        else break;
    }
    splay(x,0);
    return t[x].val;
}
void insert(int v){
    int x=root,y=0;
    while(x){
        if(t[x].val==v){break;}
        y = x;
        if(t[x].val<v){x = t[x].rs;}
        else{x = t[x].ls;}
    }
    if(x){
        t[x].cishu++;
        t[x].siz++;
    }
    else{
        x = newnode(v);
        t[x].fa=y;
        if(y){
            if(v>t[y].val){t[y].rs=x;}
            else{t[y].ls=x;}
        }
    }
    splay(x,0);
}
void find(int v){
    int x=root,y=0;
    while(x){
        if(t[x].val==v){break;}
        y = x;
        if(t[x].val>v){x = t[x].ls;}
        else{x = t[x].rs;}
    }
    if(!x){x = y;}
    splay(x,0);
}
int qianqu(int v){
    int x,y=0;
    find(v);
    if(t[root].val<v){return t[root].val;}
    x = t[root].ls;
    while(x){
        y = x;
        x = t[x].rs;
    }
    splay(y,0);
    return t[y].val;
}
int houji(int v){
    int x,y=0;
    find(v);
    if(t[root].val>v){return t[root].val;}
    x = t[root].rs;
    while(x){
        y = x;
        x = t[x].ls;
    }
    splay(y,0);
    return t[y].val;
}
void del(int v){
    int x,y;
    find(v);
    t[root].cishu--;
    t[root].siz--;
    if(!t[root].cishu){
        t[t[root].ls].fa=0;
        t[t[root].rs].fa=0;
        if(t[root].ls==0 || t[root].rs==0){root=t[root].ls+t[root].rs;return ;}
        y = t[root].ls;
        root=t[root].rs;
        x = kth(1);
        t[y].fa=root;
        t[root].ls=y;
        push(root);
    }
}
int find_rank(int v){
    find(v);
    return t[t[root].ls].siz+(t[root].val<v?t[root].cishu:0)+1;
}
int main(){
    int m,u,n,opt,last=0,ans=0;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d",&u);
        insert(u);
    }
    while(m--){
        scanf("%d %d",&opt,&u);
        u = u^last;
        if(opt==1){
            insert(u);
        }
        else if(opt==2){
            del(u);
        }
        else if(opt==3){
            last=find_rank(u);
            ans = ans^last;
        }
        else if(opt==4){
            last=kth(u);
            ans=ans^last;
        }
        else if(opt==5){
            last=qianqu(u);
            ans=ans^last;
        }
        else{
            last=houji(u);
            ans=ans^last;
        }
    }
    cout<<ans;
    return 0;
}