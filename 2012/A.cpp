
#include <iostream>
#include <vector> 

using namespace std;

void print_commas(double avg){

    //First slit int up into digits then loop
    vector<int>digits;
    int avg_int = avg; //cast to int 
    while(avg_int > 0){
        int digit = avg_int%10;
        avg_int /= 10;
        digits.push_back(digit);
    }
    reverse(digits.begin(), digits.end());

    //Cout
    for(int i = 0; i<digits.size(); ++i){
        cout<<digits[i];
        if(i%3 == 0 && i != digits.size()-1 && !((i == 0) && digits.size() <= 3)){
            cout<<",";
        }
    }
    cout<<"."<<int((avg - int(avg))*100.0);
}

void solve(){
    double total; 
    for(int i = 0; i<12; ++i){
        double month_val; 
        cin>>month_val;
        total += month_val;
    }
    double avg = total / 12;
    cout<<"$";
    print_commas(avg);
    cout<<" $";
    print_commas(avg*0.1);
    cout<<"\n";
}

int main(){
    int N;
    cin>>N;
    for(int i = 1; i<=N; ++i){
        cout<<i<<" ";
        solve();
    }
    return 0;
}