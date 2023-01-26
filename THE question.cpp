
// Anna Denisova

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct line {
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

void solve() { //main function

  int n; //number of lines in total
  cin >> n;

  //counter stores num of sections (the answer)
  int counter = n + 1; //we start at n+1 and then add on POIs as we get lines

  vector<line> lines; //stores all lines ever given

  int x1, y1, x2, y2; //temp points for each line (used for input) 

  for (int i = 0; i < n; ++i) { //for each line
    cin >> x1 >> y1 >> x2 >> y2; //get its points

    line l1 = line(x1, y1, x2, y2); //construct the line 
    //cout << "CURRENT LINE # " << i + 1 << "\n";

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
  solve();
  return 0;
}
