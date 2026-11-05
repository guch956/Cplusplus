#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N=100003;
ll p[N];
int q[N];
int head,tail;
int main(){
    int n,i,j;
    ll ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    n++;
    for(i=1;i<=n;i++){
        while(head<tail && (p[i]-p[q[tail]])*(q[tail]-q[tail-1])>=(p[q[tail]]-p[q[tail-1]])*(i-q[tail])){
            tail--;
        }
        q[++tail]=i;
    }
    for(j=head;j<tail;j++){
        for(i=q[j]+1;i<=q[j+1];i++){
            if(i<n){
                ans=((q[j+1]-i)*p[q[j]]+(i-q[j])*p[q[j+1]])*100000/(q[j+1]-q[j]);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
