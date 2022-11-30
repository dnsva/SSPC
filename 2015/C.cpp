
//C: Super Addition

#include <iostream>
#include <math.h>

using namespace std;

int get_input(){
    int input;
    cin>>input;
    return input;
}

void solve(){
    int ans = 0;
    int m = get_input();
    for(int i = m-1; i>=0; --i){
        int dig_1 = get_input(), dig_2 = get_input();
        ans += pow(10,i)*(dig_1+dig_2);
    }
    cout<<ans<<"\n";
}

int main(){
    int n = get_input();
    for(int i = 0; i<n; ++i) solve();
    return 0;
}

