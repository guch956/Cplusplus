#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=1000003;
ll p1[N<<1],p2[N<<1],A[N],B[N];
int q[N<<1],head,tail;
bool keyi[N];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
        p1[i] = p1[i-1]+A[i]-B[i];
    }
    B[0] = B[n];
    for(i=1;i<=n;i++){
        p2[i] = p2[i-1]+A[n+1-i]-B[n-i];
    }
    for(i=n+1;i<=(n<<1);i++){
        p1[i] = p1[i-1]+A[i-n]-B[i-n];
        p2[i] = p2[i-1]+A[(n<<1|1)-i]-B[(n<<1)-i];
    }
    head=1;tail=0;
    for(i=1;i<=n;i++){
        while(head<=tail && p1[i]<=p1[q[tail]]){
            tail--;
        }
        tail++;
        q[tail]=i;
    }
    for(i=1;i<=n;i++){
        while(q[head]<i){
            head++;
        }
        if(p1[q[head]]>=p1[i-1]){
            keyi[i]=1;
        }
        while(head<=tail && p1[i+n]<=p1[q[tail]]){
            tail--;
        }
        tail++;
        q[tail]=i+n;
    }
    head = 1;tail=0;
    for(i=1;i<=n;i++){
        while(head<=tail && p2[i]<=p2[q[tail]]){
            tail--;
        }
        tail++;
        q[tail]=i;
    }
    for(i=1;i<=n;i++){
        while(q[head]<i){
            head++;
        }
        if(p2[q[head]]>=p2[i-1]){
            keyi[n+1-i]=1;
        }
        while(head<=tail && p2[i+n]<=p2[q[tail]]){
            tail--;
        }
        tail++;
        q[tail]=i+n;
    }
    for(i=1;i<=n;i++){
        if(keyi[i]){printf("TAK\n");}
        else {printf("NIE\n");}
    }
    return 0;
}