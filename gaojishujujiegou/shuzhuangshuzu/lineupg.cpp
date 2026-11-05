#include<iostream>
#include<cstdio>
using namespace std;
inline int lowbit(int x){
    return x&(-x);
}
const int N=50003;
int tree_max[N],tree_min[N],A[N];
int n;
void update(int x,int d){
    while(x<=n){
        tree_max[x] = max(tree_max[x],d);
        tree_min[x] = min(tree_min[x],d);
        x+=lowbit(x);
    }
}
int chaxun(int x,int y){
    int ans_max=0,ans_min=0x3f3f3f3f;
    while(x<=y){
        if(x<=y-lowbit(y)+1){
            ans_max=max(ans_max,tree_max[y]);
            ans_min=min(ans_min,tree_min[y]);
            y -=lowbit(y);

        }
        else{
            ans_max=max(ans_max,A[y]);
            ans_min=min(ans_min,A[y]);
            y--;
        }
    }
    return ans_max-ans_min;
}
int main(){
    int m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        tree_min[i]=0x3f3f3f3f;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
        update(i,A[i]);
    }
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        printf("%d\n",chaxun(a,b));
    }
    return 0;
}