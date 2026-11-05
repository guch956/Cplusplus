#include<iostream>
#include<algorithm>
using namespace std;
struct point{
    int x;
    int y;
};
bool bijiao(point & p1,point & p2){
    return (p1.x+p1.y)<(p2.x+p2.y);
}
inline int juli(point & p1,point & p2){
    if(p2.x>=p1.x && p2.y>=p1.y){
        return p2.x+p2.y-p1.x-p1.y;
    }
    else{
        return 0;
    }
}
int main(){
    int n,k,i,j,l,h,m,**q,ans=0,s;
    cin>>n>>k;
    point *p;
    p = new point[n];
    q = new int*[n];
    for(i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        q[i] = new int[k+1];
    }
    sort(p,p+n,bijiao);
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++){
            q[i][j]=j+1;
            for(l=0;l<i;l++){
                s = juli(p[l],p[i]);
                if(s>0){
                    if(j>=s-1){
                        q[i][j] = max(q[i][j],q[l][j-s+1]+s);
                    }
                }
            }
        }
        ans = max(ans,q[i][k]);
    }
    cout<<ans;
    return 0;
}