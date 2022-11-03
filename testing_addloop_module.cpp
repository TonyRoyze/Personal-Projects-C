#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<string>> books_arr;

int main()
{
    vector<string>temp; //creating a temperary vector
    bool state;
    do
    {
        string isbn;
        string bname;
        string aname;
        string quantity;
        string price;
        char x;
        cout<< "Enter ISBN No. : ";
        cin >> isbn;
        cout<< "Enter Book Name : ";
        cin >> bname;
        cout<< "Enter Author Name : ";
        cin >> aname;
        cout<< "Enter Quantity : ";
        cin >> quantity;
        cout<< "Enter Price : ";
        cin >> price;

        temp.push_back(isbn);
        temp.push_back(bname);
        temp.push_back(aname);
        temp.push_back(quantity);
        temp.push_back(price);
        books_arr.push_back(temp);
        cout<<"\n\n";
        cout<< "To exit enter X :";
        cin >> x;

        if(x == 'X' || x == 'x'){
            state = false;
        }
        else{
            state = true;
        }
    }while (state == true);
}
