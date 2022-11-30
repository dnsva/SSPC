
//D: Caesar's Cipher

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    int n, k;
    string s;
    cin>>n>>s>>k;

    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    vector<char>shifted (n);

    for(char c: s){

        //1) CHECK I - Letter? 
        if(isalpha(c)){

            //2) CHECK II - Lowercase? Uppercase?
            if(islower(c)){

                //3) SHIFT!
                for(int i = 0; i<26; ++i){
                    if(c == lowercase[i]){
                        //Check if overflows & whether you have to loop
                        if(i+k>=26) shifted.push_back(lowercase[i+k-26]);
                        //Normal case
                        else shifted.push_back(lowercase[i+k]);
                    }
                }

            }else{

                //3) SHIFT!
                for(int i = 0; i<26; ++i){
                    if(c == uppercase[i]){
                        //Check if overflows & whether you have to loop
                        if(i+k>=26) shifted.push_back(uppercase[i+k-26]);
                        //Normal case
                        else shifted.push_back(uppercase[i+k]);
                    }
                }

            }

        }else{
            shifted.push_back(c);
        }
    }
    
    //Turn the vector into a string
    string encoded(shifted.begin(), shifted.end());
    cout<<encoded<<"\n";

    return 0;
}
