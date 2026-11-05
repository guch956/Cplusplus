#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int x[400003];
int main(){
    int n,i,sum=0,a,b;
    priority_queue<int> q;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(sum<=x[i]){
            q.push(a);
            sum+=a;
        }
        else{
            b = q.top();
            if(b>a){
                q.pop();
                q.push(a);
                sum = sum-b+a;
            }
        }
    }
    printf("%d",q.size());
    return 0;
}