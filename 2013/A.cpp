
//A: Lucky Trees

#include <iostream>
#include <math.h>
#include <vector> 

using namespace std;

int read_input() {
    int t;
    cin >> t;
    return t;
}

bool contains(vector<int>& vv, int value) {
    for (auto v : vv)
        if (v == value) return true;
    return false;
}

int main(){
    int n_rows = read_input();

    int n = pow(2, n_rows-1); // maximum row capacity

    vector<int>current_row(n, 0);

    for(int i = 0; i<n_rows; ++i){
        for(int j = pow(2, i)-1; j>=0; --j)
            current_row[j] = read_input() + current_row[j/2];
    }

    cout << (contains(current_row, 13) ? "lucky\n" : "unlucky\n");
    return 0;
}