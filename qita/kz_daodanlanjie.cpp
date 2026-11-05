#include<iostream>
#include<algorithm>
struct juli{
    int a1;
    int a2;
};
bool bijiao(juli & j1,juli & j2){
    return j1.a1<j2.a1;
}
juli A[100000];
int B[100001];
int main(){
    using namespace std;
    int x1,y1,x2,y2,n,x,y,i,d;
    while(cin>>x1>>y1>>x2>>y2 && x1!=EOF){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>x>>y;
            A[i].a1 = (x-x1)*(x-x1)+(y-y1)*(y-y1);
            A[i].a2 = (x-x2)*(x-x2)+(y-y2)*(y-y2);
        }
        sort(A,A+n,bijiao);
        B[n] = 0;
        for(i=n-1;i>=0;i--){
            B[i] = max(B[i+1],A[i].a2);
        }
        d = B[0];
        for(i=1;i<=n;i++){
            d = min(d,A[i-1].a1+B[i]);
        }
        cout<<d<<endl;
    }
    return 0;
}