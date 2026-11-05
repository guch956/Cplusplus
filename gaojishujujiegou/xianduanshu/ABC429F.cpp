#include<iostream>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=200003;
struct {
    int g[3][3];
}t[N<<2];
int ditu[N][3];
char s[N];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
inline void up(int p,int pl){
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=i;j<3;j++){
            for(k=i;k<=j;k++){
                if(ditu[pl][k]==1)break;
            }
            if(k==j+1)t[p].g[i][j]=j-i;
            else t[p].g[i][j]=INF;
            t[p].g[j][i]=t[p].g[i][j];
        }
    }
}
void push_up(int p){
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            t[p].g[i][j]=INF;
            for(k=0;k<3;k++){
                t[p].g[i][j]=min(t[ls(p)].g[i][k]+t[rs(p)].g[k][j]+1,t[p].g[i][j]);
            }
        }
    }
}
void build(int p,int pl,int pr){
    if(pl==pr){
        up(p,pl);return ;
    }
    int mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);
}
void update(int p,int pl,int pr,int x){
    if(pl==pr){
        up(p,pl);return ;
    }
    int mid=(pl+pr)>>1;
    if(x<=mid)update(ls(p),pl,mid,x);
    else update(rs(p),mid+1,pr,x);
    push_up(p);
}
int main(){
    int n,q,i,r,c;
    scanf("%d",&n);
    for(c=0;c<3;c++){
        scanf("%s",s+1);
        for(i=1;i<=n;i++){
            if(s[i]=='.')ditu[i][c]=0;
            else ditu[i][c]=1; 
        }
    }
    build(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        r--;
        ditu[c][r]=1-ditu[c][r];
        update(1,1,n,c);
        printf("%d\n",t[1].g[0][2]>=INF?-1:t[1].g[0][2]);
    }
    return 0;
}