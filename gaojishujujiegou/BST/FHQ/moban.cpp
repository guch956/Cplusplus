#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100002;
struct {
    int ls;
    int rs;
    int key;
    int pri;
    int size;
} t[N<<2];
int ent,root;
int newnode(int k){
    ent++;
    t[ent].key=k;
    t[ent].pri=rand();
    t[ent].size=1;
    return ent;
}
void push_up(int u){
    t[u].size=t[t[u].ls].size+t[t[u].rs].size+1;
}
void fenlie(int u,int & l,int & r,int x){
    if(u==0){l=r=0;return ;}
    if(t[u].key<=x){
        l=u;
        fenlie(t[u].rs,t[l].rs,r,x);
    }
    else{
        r=u;
        fenlie(t[u].ls,l,t[r].ls,x);
    }
    push_up(u);
}
int hebing(int l,int r){
    if(l==0 || r==0){return l+r;}
    if(t[l].pri<t[r].pri){
        t[r].ls=hebing(l,t[r].ls);
        push_up(r);
        return r;
    }
    else{
        t[l].rs=hebing(t[l].rs,r);
        push_up(l);
        return l;
    }
}
void charu(int x){
    int l,r,c;
    c = newnode(x);
    fenlie(root,l,r,x);
    l = hebing(l,c);
    root=hebing(l,r);
}
void shanchu(int x){
    int l,r,c;
    fenlie(root,l,r,x);
    fenlie(l,l,c,x-1);
    c = hebing(t[c].ls,t[c].rs);
    root=hebing(hebing(l,c),r);
}
int kth(int x){
    int l,r,ans=0;
    fenlie(root,l,r,x-1);
    ans=t[l].size+1;
    root=hebing(l,r);
    return ans;
}
int chaxunkth(int u,int k){
    if(k==t[t[u].ls].size+1){return t[u].key;}
    if(k>t[t[u].ls].size){
        return chaxunkth(t[u].rs,k-t[t[u].ls].size-1);
    }
    else{
        return chaxunkth(t[u].ls,k);
    }
}
int qianqu(int x){
    int l,r,ans=0;
    fenlie(root,l,r,x-1);
    ans=chaxunkth(l,t[l].size);
    root=hebing(l,r);
    return ans;
}
int houji(int x){
    int l,r,ans=0;
    fenlie(root,l,r,x);
    ans=chaxunkth(r,1);
    root=hebing(l,r);
    return ans;
}
int main(){
    int m,opt,x;
    scanf("%d",&m);
    while(m){
        scanf("%d %d",&opt,&x);
        if(opt==1){
            charu(x);
        }
        else if(opt==2){
            shanchu(x);
        }
        else if(opt==3){
            printf("%d\n",kth(x));
        }
        else if(opt==4){
            printf("%d\n",chaxunkth(root,x));
        }
        else if(opt==5){
            printf("%d\n",qianqu(x));
        }
        else{
            printf("%d\n",houji(x));
        }
        m--;
    }
    return 0;
}