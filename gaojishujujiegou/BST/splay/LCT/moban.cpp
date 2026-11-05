#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
struct {
    int ch[2];
    int val;
    int sum;
    int fa;
    int lazy;
}t[N];
void push_up(int x){t[x].sum=t[t[x].ch[0]].sum^t[t[x].ch[1]].sum^t[x].val;}
int isroot(int x){
    int f=t[x].fa;
    return t[f].ch[0]!=x && t[f].ch[1]!=x;
}
int isright(int x){return t[t[x].fa].ch[1]==x;}
void rotate(int x){
    int f=t[x].fa,g=t[f].fa,k=isright(x);
    t[f].ch[k]=t[x].ch[k^1];
    k = k^1;
    if(t[x].ch[k]){t[t[x].ch[k]].fa=f;}
    t[x].ch[k]=f;
    t[f].fa=x;
    if(t[g].ch[0]==f){t[g].ch[0]=x;}
    if(t[g].ch[1]==f){t[g].ch[1]=x;}
    t[x].fa=g;
    push_up(f);
    push_up(x);
}
void reverse(int x){
    if(!x){return ;}
    swap(t[x].ch[0],t[x].ch[1]);
    t[x].lazy^=1;
}
void push_down(int x){
    if(t[x].lazy){
        reverse(t[x].ch[0]);
        reverse(t[x].ch[1]);
        t[x].lazy=0;
    }
}
void push(int x){
    if(!isroot(x)){push(t[x].fa);}
    push_down(x);
}
void splay(int x){
    int f,g;
    push(x);
    while(!isroot(x)){
        f = t[x].fa;
        g = t[f].fa;
        if(!isroot(f)){
            if(isright(x)==isright(f)){rotate(f);}
            else{rotate(x);}
        }
        rotate(x);
    }
}
void access(int x){
    for(int child=0;x;child=x,x=t[x].fa){
        splay(x);
        t[x].ch[1]=child;
        push_up(x);
    }
}
void makeroot(int x){
    access(x);splay(x);reverse(x);
}
void split(int x,int y){
    makeroot(x);
    access(y);
    splay(y);
}
void cut(int x,int y){
    split(x,y);
    if(t[y].ch[0]!=x || t[x].ch[1]){return ;}
    t[x].fa=t[y].ch[0]=0;
    push_up(x);
}
int findroot(int x){
    access(x);
    splay(x);
    push_down(x);
    while(t[x].ch[0]){x=t[x].ch[0];push_down(x);}
    splay(x);
    return x;
}
void link(int x,int y){
    makeroot(x);
    t[x].fa=y;
}
int main(){
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&t[i].val);
        t[i].sum=t[i].val;
    }
    while(m--){
        scanf("%d %d %d",&i,&a,&b);
        if(i==0){
            split(a,b);
            printf("%d\n",t[b].sum);
        }
        else if(i==1){
            if(findroot(a)!=findroot(b)){link(a,b);}
        }
        else if(i==2){
            cut(a,b);
        }
        else if(i==3){
            splay(a);t[a].val=b;push_up(a);
        }
    }
    return 0;
}