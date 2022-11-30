
//D: Jumping Puzzle

#include <iostream>
#include <vector>

using namespace std;

void solve( int case_num ){ 
    int n; // row & col length
    cin>>n;

    vector<int>board(n*n); 
    for(auto&i:board)cin>>i;

    int correct_pos_n = 0; //number of numbers in their correct pos already
    for(int i = 0; i<n*n; ++i){
        if(board[i] == i) ++correct_pos_n;
    }

    cout<<"Case "<<case_num<<": "<<(n*n-1) - correct_pos_n<<"\n";
}

int main(){
    int t;
    cin>>t;
    for(int i = 1; i<=t; ++i) solve(i);
}
