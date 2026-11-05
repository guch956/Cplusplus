#include<iostream>
#include<cstdio>
using namespace std;
const int N=2100000;
struct {
    int ch[2];
    char val;
    int fa;
    int siz;
}t[N];
int ent,root;
char str[N];
int get(int x){return t[t[x].fa].ch[1]==x;}
void update(int x){t[x].siz=t[t[x].ch[0]].siz+t[t[x].ch[1]].siz+1;}
int build(int l,int r,int f){
    if(l>r){return 0;}
    int cnt=++ent;
    int mid=(l+r)>>1;
    t[cnt].fa=f;
    t[cnt].val=str[mid];
    t[cnt].ch[0]=build(l,mid-1,cnt);
    t[cnt].ch[1]=build(mid+1,r,cnt);
    update(cnt);
    return cnt;
}

void rotate(int x){
    int k=get(x),f=t[x].fa,g=t[f].fa;
    t[f].ch[k]=t[x].ch[k^1];
    k = k^1;
    if(t[x].ch[k]){t[t[x].ch[k]].fa=f;}
    t[f].fa=x;
    t[x].ch[k]=f;
    t[x].fa=g;
    if(g){
        if(t[g].ch[0]==f){t[g].ch[0]=x;}
        else{t[g].ch[1]=x;}
    }
    update(f);
    update(x);
}
void splay(int x,int goal){
    if(goal==0){root=x;}
    int f,g;
    while(1){
        f = t[x].fa;g = t[f].fa;
        if(f==goal){break;}
        if(g!=goal){
            if(get(x)==get(f)){rotate(f);}
            else{rotate(x);}
        }
        rotate(x);
    }
}
int kth(int u,int k){
    if(k==t[t[u].ch[0]].siz+1){return u;}
    if(k<=t[t[u].ch[0]].siz){return kth(t[u].ch[0],k);}
    else{return kth(t[u].ch[1],k-t[t[u].ch[0]].siz-1);}
}
void insert(int L,int len){
    int x = kth(root,L),y = kth(root,L+1);
    splay(x,0);
    splay(y,x);
    t[y].ch[0]=build(1,len,y);
    update(y);
    update(x);
}
void del(int L,int R){
    int x=kth(root,L),y=kth(root,R+1);
    splay(x,0);
    splay(y,x);
    t[y].ch[0]=0;
    update(y);
    update(x);
}
void print(int u){
    if(!u){return ;}
    print(t[u].ch[0]);
    printf("%c",t[u].val);
    print(t[u].ch[1]);
}
int main(){
    int q,pos=1,len,i,x,y;
    char opt[10],c;
    ent=2;
    t[1].siz=2;
    t[1].ch[1]=2;
    t[2].siz=1;
    t[2].fa=1;
    root=1;
    scanf("%d",&q);
    while(q--){
        scanf("%s",opt);
        if(opt[0]=='M'){scanf("%d",&len);pos=len+1;}
        else if(opt[0]=='I'){
            scanf("%d",&len);
            for(i=1;i<=len;i++){
                c = getchar();
                while(c<32 || c>126){c = getchar();}
                str[i]=c;
            }
            insert(pos,len);
        }
        else if(opt[0]=='D'){
            scanf("%d",&len);
            del(pos,pos+len);
        }
        else if(opt[0]=='G'){
            scanf("%d",&len);
            x = kth(root,pos);
            y = kth(root,pos+len+1);
            splay(x,0);
            splay(y,x);
            print(t[y].ch[0]);
            printf("\n");
        }
        else if(opt[0]=='P'){pos--;}
        else{pos++;}
    }
    return 0;
}