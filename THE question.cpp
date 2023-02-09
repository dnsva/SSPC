
// Anna Denisova, 2022-23

/*
There is a 1000x1000 square cake. We use a knife to cut the cake. The problem is after a series of cutting, how many partitions the cake will have.
Assumption: 
	1. The number of cutting will be no more than 8.
	2. After cutting, the length of any edge of the partition will be no less than 1.
	3. The vertex coordinates of the cake are (0,0)(0,1000)(1000,1000)(1000,0).
	4. The intersections of the cut line and the cake edge are two.
Input:
	The first line of input is an integer M, then a blank line followed by M datasets. There is a blank line between datasets. 
	The first line of each dataset is the number of the cutting. The following lines contain the information of the cut lines. Each line has 4 integer numbers, which represent the coordinate of the intersection of the cut line and cake edge.
Output:
	The output for each dataset is the number of partitions of the cake.
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct line { //stores endpoints of line 
  double x1;
  double y1;
  double x2;
  double y2;
  
  line(double x1, double y1, double x2, double y2)
    : x1{x1} 
    , y1{y1}
    , x2{x2}
    , y2{y2}
  {}

};

void solve() { //treats each dataset

  int n; //number of lines in total
  cin>>n;

  //counter stores num of partitions (the answer)
  int counter = n + 1; //we start at n+1 and then add on POIs as we get lines

  vector<line> lines; //stores all lines ever given

  int x1, y1, x2, y2; //temp points for each line (used for getting input) 

  for (int i = 0; i < n; ++i) { //for each line
    cin >> x1 >> y1 >> x2 >> y2; //get its points

    line l1 = line(x1, y1, x2, y2); //construct the line 
    

    set<pair<double, double> > POIS; //make a set (no dups) of POIS of l1 and all prev lines

    for (line l2 : lines) { //go through all prev lines 

      // first check if lines are parallel (no poi)
      // if they are parallel the formula later used does not work 
      double m1, m2; //slopes of each line 
      m1 = (l1.y2 - l1.y1) / (l1.x2 - l1.x1);
      m2 = (l2.y2 - l2.y1) / (l2.x2 - l2.x1);
      if (m1 == m2) continue; //if parallel get out of loop

      // NOT PARALLEL SO FIND POI
      double x, y; // POI points
      double x1 = l1.x1, x2 = l1.x2, x3 = l2.x1, x4 = l2.x2; //norm x points
      double y1 = l1.y1, y2 = l1.y2, y3 = l2.y1, y4 = l2.y2; //norm y points
      //CALCULATE POI
      x = ((x1 - x2) * (x4 * y3 - x3 * y4) - (x3 - x4) * (x2 * y1 - x1 * y2)) /
          ((y2 - y1) * (x3 - x4) - (x1 - x2) * (y4 - y3)); 
      y = ((y2 - y1) * (x4 * y3 - x3 * y4) - (y4 - y3) * (x2 * y1 - x1 * y2)) /
          ((x1 - x2) * (y4 - y3) - (y2 - y1) * (x3 - x4));

      // CHECK IF VALID (in bounds)
      if (x >= 0 && x <= 1000 && y >= 0 && y <= 1000) {
        POIS.insert(make_pair(x, y)); //if valid add to set 
      }

    }

    lines.push_back(l1); //add this line to the prev lines list
    counter += POIS.size(); //add the num of POIs found to counter

  }

  cout << "ANS IS " << counter << "\n"; //The answer
}

int main() {
	
	int M; //the num of datasets
	cin>>M;
	for(int i = 0; i<M; ++i){
		solve(); //call function to deal with each testcase 
	}
	return 0;
}
