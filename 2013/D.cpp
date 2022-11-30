
//D: Counting Weekend Days

#include <iostream>

using namespace std;

int month_to_days(string m){
    if(m == "JAN") return 31;
    else if(m == "FEB") return 28;
    else if(m == "MAR") return 31;
    else if(m == "APR") return 30;
    else if(m == "MAY") return 31;
    else if(m == "JUN") return 30;
    else if(m == "JUL") return 31;
    else if(m == "AUG") return 31;
    else if(m == "SEP") return 30;
    else if(m == "OCT") return 31;
    else if(m == "NOV") return 30;
    else return 30;
}
int day_to_num(string d){
    if(d == "SUN") return 1;
    else if(d == "MON") return 2;
    else if(d == "TUE") return 3;
    else if(d == "WED") return 4;
    else if(d == "THU") return 5;
    else if(d == "FRI") return 6;
    else return 7;
}

void solve(){
    string mnt, day;
    cin>>mnt>>day;

    int m = month_to_days(mnt);
    int d = day_to_num(day);

    if(m == 28) cout<<"8\n";        //28 days
    else if(m == 30){               //30 days
        if(d == 6) cout<<"10\n";
        else if(d == 5) cout<<"9\n";
        else cout<<"8\n";
    }else{                          //31 days
        if(d == 5 || d == 6) cout<<"10\n";
        else if(d == 4 || d == 6) cout<<"9\n";
        else cout<<"8\n";
    }
}

int main(){
    int T;
    cin>>T;
    for(int i = 0; i<T; ++i) solve();
    return 0;
}
