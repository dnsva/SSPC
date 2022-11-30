

//A: Missing Numbers

#include <iostream>
#include <vector>

using namespace std;

int main(){

    //1) Get input
    int n, m;
    cin>>n;
    vector<int>a(n);
    for(auto&i:a) cin>>i;
    cin>>m;
    vector<int>b(m);
    for(auto&i:b)cin>>i;

    //2) Sort
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    //3) Loop and cout if num is missing 
    for(int i = 0; i<m; ++i){
        if(a[i] != b[i]){
            a.emplace(a.begin()+i, -1);
            cout<<b[i]<<" ";
        }
    }

    cout<<"\n";
    return 0;

}