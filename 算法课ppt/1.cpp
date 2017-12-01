#include<iostream>
using namespace std;
typedef long long LL;
template<class T>inline T Mod(T a,T b){a%=b;return a<0?a+b:a;}///计算
template<class T,class Tb> inline T PowMod(Tb a,T b,T c)/**a^b mod c 要求c*c不溢出**/
{
    if(c==1)return 0;
    if(c<=0)return -1;
    a=Mod(a,(Tb)c);
    Tb ret(1L%c);
    while(b){if(b&0x1)ret=ret*a%c;a=a*a%c;b>>=1;}
    return (T)ret;
}
LL func(LL x, LL n, LL p){
    if (n==0) return 1;
    if ( n%2==0 ){
        LL m=n/2-1;
        LL s1=func(x, m, p);
        LL s2=( PowMod(x, m+1, p)*s1 )%p;
        return ( s1+s2+PowMod(x, n, p) )%p;
    }else{
        LL m=n/2;
        LL s1=func(x, m, p);
        LL s2=( PowMod(x, m+1, p)*s1 )%p;
        return ( s1+s2 )%p;
    }
}
int main(){
    LL x,n,p;
    while ( cin>>x>>n>>p ){
        cout<<func(x,n-1,p)<<endl;

    }
}
