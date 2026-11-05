#include<iostream>
#include<algorithm>
struct a{
    int height;
    int limit;
};
bool bijiao(a & b1,a& b2){
    return b1.limit<b2.limit;
}
a A[4000];
int p[40001];
int main(){
    using namespace std;
    int k,i,j,d=0,n,x,y,s=0;
    cin>>k;
    for(i=0;i<k;i++){
        cin>>x>>y>>n;
        /*   高度     数量      限制*/
        s = max(s,y);
        for(j=0;j<n;j++){
            A[d].height=x;A[d].limit=y;
            d++;
        }
    }
    sort (A,A+d,bijiao);
    p[0]=1;
    for(i=0;i<d;i++){
        for(j=A[i].limit;j>=A[i].height;j--){
            if(p[j-A[i].height]){
                p[j]=1;
            }
        }
    }
    for(j=s;j>=0;j--){
        if(p[j]){
            cout<<j;
            return 0;
        }
    }
}