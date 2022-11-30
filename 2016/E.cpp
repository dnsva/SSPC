
//E: Party Rabbits

#include <iostream>
#include <vector>

using namespace std;

//Find number of rabbits by month n
void solve(int n){ 
    vector<int>rabbits(n+1);
    rabbits[0] = 1; //base cases
    rabbits[1] = 1;
    for(int i = 2; i<=n; ++i){
        rabbits[i] = rabbits[i-1] + rabbits[i-2];
    }
    cout<<rabbits[n]<<"\n";
}

int main(){
    int m, n;
    cin>>m;
    for(int i = 0; i<m; ++i){
        cin>>n;
        solve(n);
    }
    int random_0;  // cin the 0 they give at the end of input
    cin>>random_0; 
    return 0;
}
