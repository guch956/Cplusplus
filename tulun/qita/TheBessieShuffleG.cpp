#include<iostream>
#include<cstdio>
using namespace std;
const int N=100003;
int f[N];
int p[N];
int ys[N];
int len[N];
int begi[N];
bool vis[N];
int main(){
    int n,m,i,q,a,ent=1,l=1,b,cishu;
    scanf("%d %d %d",&m,&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        f[a]=i+1;
    }
    a = 1;
    vis[a]=1;
    begi[a]=1;
    ys[a]=1;
    p[ent++]=a;
    while(a<=n){
        a = f[a];
        ys[a]=ent;
        l++;
        begi[ent]=1;
        p[ent++]=a;
        vis[a]=1;
    }
    len[1]=l;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            l = 0;
            a = i;
            begi[ent]=ent;
            while(!vis[a]){
                l++;
                vis[a]=1;
                ys[a]=ent;
                p[ent]=a;
                begi[ent++]=begi[ys[i]];
                a = f[a];
            }
            len[begi[ys[i]]]=l;
        }
    }
    while(q--){
        scanf("%d",&a);
        if(a>=n){
            b = m+1-a;
            if(b<len[1]){
                printf("%d\n",p[b+1]-1);
            }
            else{
                printf("%d\n",b-len[1]+n+1);
            }
        }
        else{
            b = n-a+1;
            cishu=m-n+1;
            if(begi[ys[b]]==1){
                if(ys[b]+cishu<=len[1]){
                    printf("%d\n",p[ys[b]+cishu]-1);
                }
                else{
                    printf("%d\n",m+1+ys[b]-len[1]);
                }
            }
            else{
                cishu+=ys[b]-begi[ys[b]];
                b = begi[ys[b]];
                cishu%=len[b];
                printf("%d\n",p[b+cishu]-1);
            }
        }
    }
    return 0;
}