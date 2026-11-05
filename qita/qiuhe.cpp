#include<iostream>
#include<cstdio>
#define ll long long
const int N=100003;
const int P=10007;
ll bianhao[N],num[N];
int head[N],nex[N];
int ent;
int number[N];
void add(int b,int c,int n){
    ent++;
    nex[ent]=head[c];
    bianhao[ent]=b;
    num[ent]=n;
    head[c]=ent;
}
int main(){
    int n,m,i,a,j;
    ll l0,l1,sx0,sx1,sn0,sn1,s0,s1;
    ll ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){scanf("%d",&number[i]);}
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        add(i,a,number[i]);
    }
    for(i=1;i<=m;i++){
        s0=s1=sn0=sn1=sx0=sx1=l0=l1=0;
        for(j=head[i];j;j=nex[j]){
            if(bianhao[j]&1){
                sx1=(sx1+bianhao[j])%P;
                sn1=(sn1+num[j])%P;
                s1 = (bianhao[j]*num[j]%P+s1)%P;
                l1++;
            }
            else{
                sx0=(sx0+bianhao[j])%P;
                sn0=(sn0+num[j])%P;
                s0 = (bianhao[j]*num[j]%P+s0)%P;
                l0++;
            }
        }
        ans = (sx0*sn0%P+((l0-2)*s0%P)+ans)%P;
        ans = (sx1*sn1%P+((l1-2)*s1%P)+ans)%P;
    }
    ans = (ans%P+P)%P;
    printf("%d",ans);
    return 0;
}