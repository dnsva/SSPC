
//A: Curly Balance

#include <iostream>
#include <vector>

using namespace std;

bool solve(){
    //get input
    string sequence;
    cin>>sequence;
    vector<char>s(sequence.begin(), sequence.end());
    int n = sequence.size();
    //check start & end
    if(s[n-1] == '{' || s[0] == '}') return 0;
    //split in half and check that way the rest
    //first half
    int open_1 = 0, closed_1 = 0;
    for(int i = 0; i<n/2; ++i) (s[i] == '{') ? ++open_1 : ++closed_1;
    if(closed_1 > open_1) return 0;
    //second half
    int open_2 = 0, closed_2 = 0;
    for(int i = n/2; i<n; ++i) (s[i] == '{') ? ++open_2 : ++closed_2;
    if(open_2 > closed_2) return 0;
    // total open has to equal total closed
    if(open_1 + open_2 != closed_1 + closed_2) return 0;
    //if passed all tests
    return 1;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        bool ans = solve();
        (ans) ? cout<<"T\n" : cout<<"F\n";
    }
    return 0;
}

