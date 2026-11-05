#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100003;
struct boots{
    int s;
    int d;
    int bianhao;
}bo[N];
int ma=1;
struct {
    int last;
    int next;
}link[N];
bool ans[N];
bool bijiaob(boots & b1,boots & b2){
    return b1.s>b2.s;
}
struct zhuan{
    int f;
    int weizhi;
}zh[N];
bool bijiaoz(zhuan & z1,zhuan & z2){
    return z1.f>z2.f;
}
void del(int x){
    link[link[x].last].next=link[x].next;
    link[link[x].next].last=link[x].last;
    ma=max(ma,link[x].next-link[x].last);
}
int main(){
    int n,i,j,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&zh[i].f);
        zh[i].weizhi=i;
        link[i].last=i-1;
        link[i].next=i+1;
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&bo[i].s,&bo[i].d);
        bo[i].bianhao=i;
    }
    sort(zh+1,zh+n+1,bijiaoz);
    sort(bo,bo+m,bijiaob);
    j=1;
    for(i=0;i<m;i++){
        while(j<=n && zh[j].f>bo[i].s){
            del(zh[j].weizhi);
            j++;
        }
        if(ma<=bo[i].d){
            ans[bo[i].bianhao]=true;
        }
    }
    for(i=0;i<m;i++){
        if(ans[i]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
