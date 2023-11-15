#include <iostream>
#include <map>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(NULL);int N,M;map<int,int>a;cin>>N;while(N--){cin>>M;a[M]++;}cin>>N;while(N--){cin>>M;cout<<a[M]<<" ";}}