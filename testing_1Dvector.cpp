#include <iostream>
#include <string>
#include <vector>
using namespace std;


void print(vector<int> &data){
    for(int i=0; i<data.size(); i++){
        cout<<data[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    vector<int> data = {1, 2, 3};
    data.push_back(12); //add element
    cout<<data[3]<<endl;
    data.pop_back(); //remove last element
    data.push_back(21);
    print(data);
	return 0;
}
