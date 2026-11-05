#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000003;
struct node{
    int id;
    int a;
}p[N];
int zu[N];
bool bijiao(node n1,node n2){
    return n1.a>n2.a;
}
int main(){
    int n,ok=0,i,k,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&p[i].a);
        p[i].id=i;
    }
    sort(p+1,p+n+1,bijiao);
    for(i=1;i<n-1;i++){
        k = p[1].a+i;
        if(p[k+1].a<=i && k<=n-p[i+1].a){
            ok = 1;
            for(t=1;t<=i;t++){zu[p[t].id]=1;}
            for(t=i+1;t<=k;t++){zu[p[t].id]=2;}
            for(t=k+1;t<=n;t++){zu[p[t].id]=3;}
            break;
        }
        k = n-p[1].a;
        if(i>=p[i+1].a && k-i>=p[k+1].a){
            ok = 1;
            for(t=1;t<=i;t++){zu[p[t].id]=1;}
            for(t=i+1;t<=k;t++){zu[p[t].id]=3;}
            for(t=k+1;t<=n;t++){zu[p[t].id]=2;}
            break;
        }
    }
    if(ok){
        printf("YES\n");
        for(i=1;i<=n;i++){
            printf("%d",zu[i]);
        }
    }
    else{
        printf("NO");
    }
    return 0;
}