
//B: Open Source

#include <iostream>				// This sol uses the advantage of certain datastructures, specifically sets. In order to understand what is going
#include <set>					// on here, READ UP ON SETS and MULTISETS!!!! There are also a BUNCH of c++ functions used. When in doubt go to 
#include <vector>				// https://en.cppreference.com/w/
#include <ctype.h>				// We avoid duplicates of members in each club by using a set, then we call check_duplicates() to remove duplicates
#include <string>				// by iterating through all sets. 
#include <algorithm>			// Then, we sort the final data using a lambda function.
#include <utility>					

using namespace std;

vector<set<string>>CLUBS; //first element of each set will be the name of the club 

void check_duplicates(){
	multiset<string>all_names; //ALL NAMES OF ALL PEOPLE THAT SIGNED UP FOR ANY CLUB
	
	for(set<string>curr_set : CLUBS)
		for(string curr_str : curr_set)
			all_names.insert(curr_str);
			
	for(string name : all_names){ //if a string count is > 1 then remove from all sets
		int cnt = all_names.count(name);
		if(cnt > 1)
			for(set<string>&curr_set:CLUBS)
				curr_set.erase(name);	
	}
}

void solve(){ //heart of program

	while(cin){
		string curr_line;
		getline(cin, curr_line);
		cin>>ws; //needed specifically for getline()
		
		if(curr_line == "1") break;
		
		if(isupper(curr_line[0])){ //if first char is a capital it HAS TO BE A CLUB NAME
			set<string>curr_club; //members of current club 
			curr_club.insert("0"+curr_line); //ADD CLUB NAME (zero so that this will be the 1st element)
	
			while(cin){			
				// FIRST check if is 0 or a new club 
				char check = cin.peek(); //if yes we use peek so that it will still be in the input stream
				if( isupper(check) || check == '1') break;
				string curr_name;
				getline(cin, curr_name);
				curr_club.insert(curr_name); //add name to club
			}
			CLUBS.push_back(curr_club); //add this club and its members to the main vector of CLUBS 
		}
	}
	
	check_duplicates();
	
	vector<pair<string, int>>FINAL_ANS; //<club name, # of names> 
	for(set<string> curr_set : CLUBS){	//fills FINAL_ANS
		string club_name = *curr_set.begin(); //gets first element of set
		club_name.erase(club_name.begin()); //removes the 0 we put at the beginning of all club names
		FINAL_ANS.push_back({club_name, curr_set.size()-1}); 
	}
	
	//SORT
	sort(FINAL_ANS.begin(), FINAL_ANS.end(),
	[](const pair<string, int>&left, const pair<string, int>&right){ //use lambda
		return left.second > right.second;
	});
	//OUTPUTTTTTT FINALLY
	for(pair<string,int>curr : FINAL_ANS) cout<<curr.first<<" "<<curr.second<<"\n";
}

int main(){
	while(true){
		CLUBS.clear();
		char check_end = cin.peek(); //since we dont know how many test cases there are
		if(check_end == '0') break;
		else solve();
	}
	return 0;
}






