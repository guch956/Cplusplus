#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int P=1e9+7;
const int prime=80051;
const int maxsz=1600000;
class hashtable{
    public:
    int head[prime],nex[maxsz];
    int key[maxsz];int state[maxsz];
    int sz;
    void clear(){
        sz=0;
        memset(head,-1,sizeof(head));
    }
    void push(int s,int d){
        int x=s%prime,i;
        for(i=head[x];i!=-1;i=nex[i]){
            if(state[i]==s){
                key[i]+=d;
                key[i]%=P;
                return;
            }
        }
        state[sz]=s;
        key[sz]=d;
        nex[sz]=head[x];
        head[x]=sz++;
    }
}H0,H1,*f0,*f1;
int main(){
    int n,m,i,j,k,s,a;
    char c;
    f0=&H0;
    f1=&H1;
    scanf("%d %d",&n,&m);
    f0->clear();
    f1->clear();
    f0->push(0,1);
    for(i=0;i<n;i++){
        cin>>c;
        a = (1<<m)-1;
        for(k=0;k<f0->sz;k++){
            s = f0->state[k];
            f1->push((s&a)<<1,f0->key[k]);
            if(c=='.'){
                if(m>=2){
                    if((f0->state[k]&1)==0 && (f0->state[k]&2)==0){
                        f1->push(((s&a)<<1)+1,f0->key[k]);
                    }
                }
                else{
                    if((f0->state[k]&1)==0){
                        f1->push(((s&a)<<1)+1,f0->key[k]);
                    }
                }
            }
        }
        f0->clear();
        swap(f0,f1);
        for(j=1;j<m;j++){
            cin>>c;
            for(k=0;k<f0->sz;k++){
                s = f0->state[k];
                f1->push(s&(~(1<<j)),f0->key[k]);
                if(c=='.'){
                    if((s&(1<<j))==0 && (s&(1<<(j-1)))==0 && (s&(1<<(j+1)))==0 && (s&(1<<(j+2)))==0){
                        f1->push(s|(1<<j),f0->key[k]);
                    }
                }
            }
            f0->clear();
            swap(f0,f1);
        }
    }
    s = 0;
    for(i=0;i<f0->sz;i++){
        s+=f0->key[i];
        s%=P;
    }
    printf("%d",s);
    return 0;
}