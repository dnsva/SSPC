
//C: Longest Nap 

#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

struct time{
    int total_mins, hours, mins;
    time(int h, int m){
        total_mins = h*60+m;
        hours = h;
        mins = m;
    }  
    time(int m){
        total_mins = m;
        mins = m%60;
        hours = (m-mins)/60;
    }
};

time get_input(){
    //get input if its a time ONLY (so dont read prof's desc)
    while(cin){
    	char c = cin.get();
    	if(isdigit(c)){
    		cin.putback(c);
    		break;
		}
	}
    int h, m; char colon;
    cin>>h>>colon>>m;
    h -= 10; //since we PRETEND times are 00:00 to 8:00 instead of 10:00 to 18:00
    return {h, m};
}

void solve(){
    int s;
    cin>>s;
    vector<bool>available (8*60+1, true); //element for each min of time 
    for(int i = 0; i<s; ++i){
        time start = get_input(), end = get_input();
        for(int j = start.total_mins+1; j <= end.total_mins; ++j) available[j] = false; //busy 
    }
    //find largest interval of free time 
    int ans = 0, cnt = 0, ans_start_index, start_index = 0; //ans is the num of mins for nap
    for(int i = 0; i<8*60+1; ++i){
        if(i > 0 && available[i] && !available[i-1]) start_index=i-1; //start index
        if(available[i]) ++cnt;
        else{
        	if(ans < cnt){
        		ans = cnt;
        		ans_start_index = start_index;
			}
			cnt = 0;
        }
    }
    if(ans < cnt){ //this last if is needed for if ans is a suffix like 0111
		ans = cnt;
		ans_start_index = start_index;
	}
    time start {ans_start_index+10*60}; //time of start of longest nap
    time len {ans};
	//output     
    cout<<"the longest nap starts at "<<start.hours<<":";
    if(start.mins > 9 ) cout<<start.mins;
    else cout<<"0"<<start.mins;
    cout<<" and will last for ";
    if(len.hours>0) cout<<len.hours<<" hours and ";
    cout<<len.mins<<" minutes.\n";
}

int main(){
    int TC;
    cin>>TC;
    for(int i = 1; i<=TC; ++i){
        cout<<"Day #"<<i<<": ";
        solve();
    }
    return 0;
}









