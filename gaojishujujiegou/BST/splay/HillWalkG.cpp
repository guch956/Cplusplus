#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
struct node{
    int x;
    int id;
    int y;
    bool shan;
}p[N<<1];
bool bijiao(node & n1,node & n2){
    return n1.x==n2.x?n1.y<n2.y:n1.x<n2.x;
}
double xianduan[N][2];
int root;
struct {
    int ch[2];
    int fa;
    int id;
}t[N];
int ent,weizhi[N];
int isright(int x){return t[t[x].fa].ch[1]==x;}
void rotate(int x){
    int k=isright(x),f=t[x].fa,g=t[f].fa;
    t[f].ch[k]=t[x].ch[k^1];
    k = k^1;
    if(t[x].ch[k]){t[t[x].ch[k]].fa=f;}
    t[x].ch[k]=f;
    t[f].fa=x;
    t[x].fa=g;
    if(t[g].ch[0]==f){t[g].ch[0]=x;}
    if(t[g].ch[1]==f){t[g].ch[1]=x;}
}
void splay(int x,int goal){
    if(goal==0){root=x;}
    int f,g;
    while(1){
        f = t[x].fa;
        g = t[f].fa;
        if(f==goal){break;}
        if(g!=goal){
            if(isright(x)==isright(f)){rotate(f);}
            else{rotate(x);}
        }
        rotate(x);
    }
}
inline double zhi(double x,int i){
    return x*xianduan[i][0]+xianduan[i][1];
}
bool cmp(double x,int i1,int i2){
    return zhi(x,i1)<zhi(x,i2);
}
int insert(double x,int i){
    int y=0,r=root;
    while(r){
        y = r;
        if(cmp(x,i,t[r].id)){r=t[r].ch[0];}
        else{r=t[r].ch[1];}
    }
    t[++ent].fa=y;
    t[ent].id=i;
    if(y){if(cmp(x,i,t[y].id)){t[y].ch[0]=ent;}
        else{t[y].ch[1]=ent;}}
    splay(ent,0);
    return ent;
}
int del(int wz){
    int y;
    splay(wz,0);
    y = t[wz].ch[0];
    while(t[y].ch[1]){y=t[y].ch[1];}
    if(y==0){root=t[wz].ch[1];t[root].fa=0;return 0;}
    splay(y,wz);
    root=y;
    t[y].fa=0;
    if(t[wz].ch[1]){t[t[wz].ch[1]].fa=y;}
    t[y].ch[1]=t[wz].ch[1];
    return t[y].id;
}
int main(){
    int n,now=1,ans=1,i,j;
    double a,b,c,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        xianduan[i][0]=(d-b)/(c-a);
        xianduan[i][1]=b-xianduan[i][0]*a;
        j = 2*i-1;
        p[j].x=a;
        p[j].id=i;
        p[j].y=b;
        j++;
        p[j].x=c;
        p[j].id=i;
        p[j].y=d;
        p[j].shan=1;
    }
    sort(p+1,p+2*n+1,bijiao);
    for(i=1;i<=2*n;i++){
        if(p[i].shan){
            a = del(weizhi[p[i].id]);
            if(p[i].id==now){
                now = a;
                if(now){ans++;}
            }
        }
        else{
            weizhi[p[i].id]=insert(p[i].x,p[i].id);
        }
    }
    printf("%d",ans);
    return 0;
}