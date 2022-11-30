
#include <iostream>
#include <cmath>

using namespace std;

void solve(){
    int sides_n;
    cin>>sides_n;
    vector<double>sides(sides_n, 0);
    for(double&i:sides) cin>>i;
    //TO FIND HYPOTENUSE 
    sort(sides.begin(), sides.end());
    //SET VALUES and FIND SEMI PERIMETER (s)
    double a = sides[0], b = sides[1], c = sides[2], s = (a+b+c)/2;
    //USE HERON'S FORMULA
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    //Output ans 
    printf("%.2f", area);
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<n; ++i){
        solve();
    }
    return 0;
}