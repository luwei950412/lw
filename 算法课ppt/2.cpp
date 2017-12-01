#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
typedef long long LL;
struct PackingSquares{
    long long leastArea(vector <int> a){
        LL sum=0;
        while ( !a.empty() ){
            int q = *max_element(a.begin(), a.end() );
            sum += 1LL<<(2*q);
            bool can = 1;
            for (int i=a.size()-1; i>=0; i-- ){
                if ( a[i]==q ) can=0;
                if ( a[i]==q || can ) a.erase( a.begin()+i );
            }
        }
        return sum;
    }
};
int main(){
    PackingSquares test;
    vector<int> a={3,4,1,4};
    cout<<test.leastArea(a)<<endl;
    return 0;
}
