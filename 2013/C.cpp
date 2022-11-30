
//C: Cost Cutting

#include <iostream>
#include <vector>

using namespace std;

int solve(){
    vector<int>people(3);
    for(int&i:people) cin>>i;
    sort(people.begin(), people.end());
    return people[1];
}

int main(){
    int T;
    cin>>T;
    for(int i = 1; i<=T; ++i){
        int ans = solve();
        cout<<"Case "<<i<<": "<<ans<<"\n";
    }
    return 0;
}