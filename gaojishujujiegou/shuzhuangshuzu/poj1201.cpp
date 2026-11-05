#include<iostream>
#include<cstdio>
using namespace std;
const int N=50001;
inline int lowbit(int x){return x&(-x);}
int tree[N];
int chaxun(int x){
    int a=0;
    while(x){
        a+=tree[x];
        x-=lowbit(x);
    }
    return a;
}
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int head[N],to[N],nex[N],le[N];
int ent;
void add(int a,int b,int c){
    ent++;
    to[ent]=c;
    le[ent]=a;
    nex[ent]=head[b];
    head[b]=ent;
}
struct {
    int pre;
    int suf;
}p[N];
void del(int x){
    p[p[x].pre].suf=p[x].suf;
    p[p[x].suf].pre=p[x].pre;
}
int main(){
    int i,n,a,b,c,x,j,num;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&a,&b,&c);
        b++;
        add(a,b,c);
    }
    for(i=0;i<=N;i++){p[i].pre=i-1;p[i].suf=i+1;}
    for(i=1;i<=N;i++){
        x = i;
        for(j=head[i];j;j=nex[j]){
            num = chaxun(i)-chaxun(le[j]);
            if(num<to[j]){
                num = to[j]-num;
                while(num--){
                    update(x,1);
                    del(x);
                    x = p[x].pre;
                }
            }
        }
    }
    printf("%d",chaxun(N));
    return 0;
}