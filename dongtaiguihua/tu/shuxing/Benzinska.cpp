#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N=200003;
struct node{
    int x;
    int y;
}g[N];
bool bijiao(node & n1,node & n2){
    return n1.x<n2.x;
}
int main(){
    priority_queue<int> q;
    int n,i,j,X,d=0,ans=-1;
    scanf("%d %d %d",&n,&g[0].y,&X);
    for(i=1;i<=n;i++){
        scanf("%d",&g[i].x);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&g[i].y);
    }
    sort(g+1,g+n+1,bijiao);
    q.push(g[0].y);
    j = 1;
    while(d<X){
        if(q.empty()){
            printf("-1");
            return 0;
        }
        else{
            i = q.top();q.pop();
            d = d+i;
            ans++;
            while(j<=n && g[j].x<=d){
                q.push(g[j].y);
                j++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}