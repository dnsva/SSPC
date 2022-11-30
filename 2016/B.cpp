
//B: Sweet-16 Sale

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int p, d, m, wallet; // p - original price, d - amount to subtract by, m - minimum game price
    cin>>p>>d>>m>>wallet;

    int games = 0; // games bought 
    int current_price = p;

    while(wallet-current_price>= 0){
        wallet -= current_price;
        ++games;
        if(current_price - d <= m){
            current_price = m;
        }else{
            current_price -= d;
        }
    }

    cout<<games<<"\n";
}


