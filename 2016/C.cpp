//C: Palindrome Index

#include <iostream>
#include <vector>

using namespace std;

inline bool check_palindrome(string s){
    //1) check if string is palindrome
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end());
    if(s == s_reversed) return true;

    return false;
}

void solve(){
    string s;
    cin>>s;
    
    //1) check if already a palindrome
    bool check = check_palindrome(s);
    if(check){
        cout<<"-1\n";
        return;
    }

    //2) remove each index and check if palindrome
    for(int i = 0; i<s.size(); ++i){
        string temp = s;
        temp.erase(temp.begin()+i);
        bool check = check_palindrome(temp);
        if(check){
            cout<<i<<"\n";
            return;
        }
    }
    
    //3) if cant be made into palindrome
    cout<<"-1\n";
    return;
}


int main(){
    int T;
    cin>>T;
    //solve each test case 
    for(int i = 0; i<T; ++i){
        solve();
    }
}