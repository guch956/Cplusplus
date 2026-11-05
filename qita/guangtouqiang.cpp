#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=50003;
int A[N],n;
int check(int x){
    int i,j=1;
    for(i=x+1;i<=n;i++){
        if(2*A[j]<=A[i]){
            j++;
            if(j==x+1){return 1;}
        }
    }
    return 0;
}
int main(){
    int i,l,r,mid;
    freopen("kangaroo.in","r",stdin);
    freopen("kangaroo.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    sort(A+1,A+n+1);
    l = 0;r = n>>1;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid)){l = mid;}
        else{r = mid-1;}
    }
    printf("%d",l);
    return 0;
}