#include<iostream>
#include<algorithm>
struct guan{
    int p;
    int l;
    int h;
};
bool bijiao(guan & g1,guan & g2){
    return g1.p<g2.p;
}
int main(){
    using namespace std;
    int n,m,k,i,j,new1=1,old1=0,g1=0,buxing=2147483643;
    int *x,*y,**hei;
    guan *g;
    cin>>n>>m>>k;
    x = new int[n];
    y = new int[n];
    hei = new int*[m+1];
    g = new guan[k];
    for(i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(i=0;i<k;i++){
        cin>>g[i].p>>g[i].l>>g[i].h;
    }
    sort(g,g+k,bijiao);
    for(i=0;i<=m;i++){
        hei[i] = new int[2];
        hei[i][0]=0;
    }
    hei[0][0]=buxing;
    for(i=0;i<=n-1;i++){
        for(j=1;j<=x[i];j++){
            hei[j][new1]=buxing;
        }
        for(j=x[i]+1;j<=m;j++){
            hei[j][new1]=min(hei[j-x[i]][old1],hei[j-x[i]][new1])+1;
            hei[j][new1]=min(buxing,hei[j][new1]);
        }
        for(j=m-x[i]+1;j<=m;j++){
            hei[m][new1]=min(hei[m][new1],hei[j][old1]+1);
            hei[m][new1]=min(hei[m][new1],hei[j][new1]+1);
        }
        for(j=1;j<=m-y[i];j++){
            hei[j][new1]=min(hei[j][new1],hei[j+y[i]][old1]);
        }
        if(g[g1].p==i+1){
            for(j=1;j<=g[g1].l;j++){
                hei[j][new1]=buxing;
            }
            for(j=g[g1].h;j<=m;j++){
                hei[j][new1]=buxing;
            }
            g1++;
        }
        for(j=1;j<=m;j++){
            if(hei[j][new1]!=buxing){
                break;
            }
        }
        if(j==m+1){
            cout<<0<<endl;
            cout<<g1-1;
            return 0;
        }
        old1 = 1-old1;
        new1 = 1-new1;
    }
    j = buxing;
    for(i=1;i<=m;i++){
        j = min(j,hei[i][old1]);
    }
    cout<<1<<endl;
    cout<<j;
    return 0;
}