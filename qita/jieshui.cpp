#include<cstdio>
#include<algorithm>
struct ren{
    int time;
    int biaohao;
};
bool bijiao(ren & r1,ren & r2){
    return r1.time<r2.time;
}
int main(){
    using namespace std;
    int n,i;
    double s=0;
    ren *p;
    scanf("%d",&n);
    p = new ren[n];
    for(i=0;i<n;i++){
        scanf("%d",&p[i].time);
        p[i].biaohao=i+1;
    }
    sort(p,p+n,bijiao);
    for(i=0;i<n;i++){
        printf("%d ",p[i].biaohao);
        s += (n-1-i)*p[i].time;
    }
    s = s/n;
    printf("\n%.2f",s);
    return 0;
}