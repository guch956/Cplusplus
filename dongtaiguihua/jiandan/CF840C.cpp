#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=303;
const ll P=1e9+7;
ll dp[2][N][N];
int fa[N];
int siz[N];
ll A[N];
int find(int x){
    if(fa[x]!=x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void hebing(int x,int y){
    int a = find(x),b = find(y);
    if(a!=b){
        fa[a] = b;
        siz[b]+=siz[a];
    }
}
bool issqu(ll a){
    ll l = 1,r = 1000000000,mid;
    while(l<r){
        mid = (l+r+1)>>1;
        if(mid*mid<=a){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    if(l*l==a){return true;}
    return false;
}
int main(){
    int n,i,l,p,s,now=1,old=0,num = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&A[i]);
        fa[i] = i;
        siz[i] = 1;
    }
    for(i=1;i<=n;i++){
        for(l=i+1;l<=n;l++){
            if(issqu(A[i]*A[l])){
                hebing(i,l);
            }
        }
    }
    dp[old][0][0] = 1;l = 2;
    for(i=1;i<=n;i++){
        if(fa[i]==i){
            num++;
            l--;
            for(p=0;p<num;p++){
                for(s=0;s<=p+1 && s<l;s++){
                    dp[now][p][0] = (dp[now][p][0]+dp[old][p][s]*(num-p)%P)%P;
                    dp[now][p][0] = (dp[now][p][0]+dp[old][p+1][s]*(p+1)%P)%P;
                }
            }
            swap(now,old);
            memset(dp[now],0,sizeof(dp[now]));
            for(l=2;l<=siz[i];l++){
                num++;
                for(p=0;p<num;p++){
                    for(s=0;s<=p+1 && s<l;s++){
                        if(num+s-2*l-p+2 >= 0){
                            dp[now][p][s] = dp[now][p][s]+dp[old][p][s]*(num+s-2*l-p+2)%P;
                        }
                        if(s>0 && p>0){
                            dp[now][p][s] = dp[now][p][s]+dp[old][p-1][s-1]*(2*l-s-1)%P;
                        }
                        dp[now][p][s] = (dp[now][p][s]+dp[old][p+1][s]*(p+1-s)%P)%P;
                    }
                }
                swap(now,old);
                memset(dp[now],0,sizeof(dp[now]));
            }
        }
    }
    printf("%lld",dp[old][0][0]);
    return 0;
}