#include <iostream>
#include <vector>
using namespace std;

vector<std::vector<int>>MyVector;

void add();
int main(){

    add();
    add();

    cout << "Rows in the 2d vector: " << MyVector.size() <<
    endl << "Collumns in the 1st row: " << MyVector[0].size() <<
    endl;

    for(int rc=0; rc<MyVector.size(); rc++){
        for(int cc=0; cc<MyVector[0].size(); cc++){
            cout<<MyVector[rc][cc]<<"\t";}
    }
    cout<<endl;
}

void add(){
    vector<int>temp;

    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    MyVector.push_back(temp);
}
