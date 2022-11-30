
//B: Ecological Bin Packing

#include <iostream>
#include <vector>

using namespace std;

struct box{
    int brown, green, clear, sum; //amount of each bottle
    box(bool b){
        cin>>brown>>green>>clear;
        sum = brown + green + clear; //find sum
    }
};

int main(){
    box first_box(true), second_box(true), third_box(true); //make boxes
    vector<box> boxes {first_box, second_box, third_box}; //store them in a vector
    sort(boxes.begin(), boxes.end(), [](box&box1, box&box2){return box1.sum > box2.sum;}); //SORT in DESCENDING order

    vector<char>label_order; //which box has what bottles (since we start with a DESCENDING list, this will be flipped)
    vector<char>available_labels = {'B', 'C', 'G'}; //alphabetical order
    int min_moves = 0; //stores minimum swaps needed

    for(box b : boxes){ //for each box find what LABEL it will have
        char max_label; //max label so far
        int max_amount = -1; //amount of max label so far
        for(char label: available_labels){ //go through available labels and find max
            if(label == 'B' && b.brown > max_amount){
                max_label = 'B';
                max_amount = b.brown;
            }else if(label == 'C' && b.clear > max_amount){
                max_label = 'C';
                max_amount = b.clear;
            } else if(label == 'G' && b.green > max_amount){
                max_label = 'G';
                max_amount = b.green;
            }
        }
        for(int i = 0; i<available_labels.size(); ++i) //remove label used from available labels
            if(available_labels[i] == max_label)
                available_labels.erase(available_labels.begin()+i);

        if(max_label == 'B') min_moves += b.green + b.clear; //these three lines move the remaining bottles
        else if(max_label == 'G') min_moves += b.brown + b.clear;
        else min_moves += b.brown + b.green;

        label_order.push_back(max_label); //add label 
    }

    reverse(label_order.begin(), label_order.end()); //flip back
    string str_order(label_order.begin(), label_order.end()); //turn vector<char> into string

    cout << str_order <<"\n";
    cout<< min_moves <<"\n";
}
