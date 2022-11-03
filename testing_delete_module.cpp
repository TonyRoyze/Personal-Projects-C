#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<string>> books_arr{
    {"1", "A","J. K. Rowling", "3", "2000" },
    {"2", "B","J. K. Rowling", "4", "2000" },
    {"3", "C","J. K. Rowling", "10", "2000" }
};

void delete_element(vector<string>& books)
  {
      cout<<books.size();
      int size = books.size();
      for(int cc=0; cc<size; cc++){

          // books.erase(books.begin()+cc);
          books.pop_back();
      }cout<<endl;

  };

  void displayAllDetails(const vector<vector<string>> &books){


      for(int rc=0; rc<books.size(); rc++){
          for(int cc=0; cc<books[rc].size(); cc++){
              string p = books[rc][cc];
              cout<< p<<"\t";
              
          }cout<<endl;
      }
      cout << "\n\n";
};
void rearrange(vector<vector<string>> &books, int row){

    for(int rc=row; rc<books.size(); rc++){
        for(int cc=0; cc<books[rc].size(); cc++){
            string p = books[rc][cc];
            books[rc-1][cc] = p;

        }cout<<endl;
    }
    cout << "\n\n";
}

int main()
 {
    int row;
    cin>>row;
    delete_element(books_arr[row]);
    displayAllDetails(books_arr);
    row ++;
    rearrange(books_arr,row);
    displayAllDetails(books_arr);
 }
