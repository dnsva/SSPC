
#include <iostream>

using namespace std;

void solve(){
    double total; 
    for(int i = 0; i<12; ++i){
        double month_val; 
        cin>>month_val;
        total += month_val;
    }

    for(int i = 100; i*3 < total; i*=3){
        //!!! IN book
    }

}

int main(){
    int N;
    cin>>N;
    for(int i = 2; i<=N; ++i){
        cout<<i<<" ";
        solve();
    }
    return 0;
}