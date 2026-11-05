#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
    int num;
    double zhi;
    node(int n,double z){num = n;zhi = z;}
    bool operator<(const node & n1)const{
        return zhi<n1.zhi;
    }
};
int main(){
    int n,k,x,i,T;
    double c;
    node u(0,0);
    scanf("%d",&T);
    while(T--){
        priority_queue<node> q;
        scanf("%d %d %d",&n,&k,&x);
        for(i=1;i<=n;i++){
            scanf("%lf",&c);
            q.push(node(1,c));
        }
        while(1){
            u = q.top();
            q.pop();
            if(u.num<=k){
                k-=u.num;
                q.push(node(u.num<<1,u.zhi/2));
            }
            else{
                q.push(node(u.num-k,u.zhi));
                if(k){
                    q.push(node(k,u.zhi/2));
                }
                break;
            }
        }
        while(1){
            u = q.top();
            q.pop();
            if(u.num>=x){break;}
            else{
                x-=u.num;
            }
        }
        printf("%.15f\n",u.zhi);
    }
    return 0;
}