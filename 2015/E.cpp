
//E: Adjacent Means

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

void manual (int case_num);
void solve (int case_num);

int get_input(){
    int input;
    cin>>input;
    return input;
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);

    int N = get_input();
    for(int i = 1; i<=N; ++i) solve(i);
}

//Seems like the super mean is literally just the normal mean
void solve( int case_num){
    int n = get_input();
    vector<double>vals(n);
    for(auto&i:vals) cin>>i;
    sort(vals.begin(), vals.end());
    if(n % 2 == 0){
        cout<<"Case #"<<case_num<<": "<< (vals[n/2-1]+vals[n/2])/2.0 <<"\n";
    }else{
        cout<<"Case #"<<case_num<<": "<< vals[n/2] <<"\n";
    }
}

//Im not sure if " I tried writing a program to do this, but it's too slow"
//is supposed to hint that youre NOT supposed to do this by calculating everything
//normally but here it is still in case:

void manual (int case_num){
    int n = get_input();
    vector<double>vals(n);
    for(auto&i:vals) cin>>i;
    while(vals.size() != 1){
        for(int i = 0; i+1 < vals.size(); ++i){
            vals[i] = (vals[i] + vals[i+1])/2;
        }
        vals.pop_back();
    }
    cout<<"Case #"<<case_num<<": "<<vals[0]<<"\n";
}

