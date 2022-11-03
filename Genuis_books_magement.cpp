#include <iostream>
#include <string>
// #include <limits>
#include <vector>
#include <stdlib.h>
//#include <algorithm>
using namespace std;

vector<vector<string>> books_arr = {

    {"ISBN_13:9780747532743", "Harry_Potter_and_the_Philosopher's_Stone","J.K.Rowling", "3", "2000" },
    {"ISBN_13:9780439064866", "Harry_Potter_and_the_Chamber_of_Secrets","J.K.Rowling", "4", "2000" },
    {"ISBN-13:9780747546290", "Harry_Potter_and_the_Prisoner_of_Azkaban","J.K.Rowling", "10", "2000" },
    {"ISBN_13:9780439139601", "Harry_Potter_and_the_Goblet_of_Fire","J.K.Rowling", "7", "2000" },
    {"ISBN_13:9780439358071", "Harry_Potter_and_the_Order_of_the_Phoenix","J.K.Rowling", "12", "2000" },
    {"ISBN-13:9780439785969", "Harry_Potter_and_the_Half-Blood_Prince","J.K.Rowling", "1", "2000" },
    {"ISBN_13:9780545139700", "Harry_Potter_and_the_Deathly_Hallows","J.K.Rowling", "5", "3000" }
    // ,{"ISBN_13:9781338099133", "Harry_Potter_and_the_Cursed_Child","J.K.Rowling", "7", "3000" }
};// creating a vector to store the book details



bool login();
void displayAllDetails();
void menu();
int search();
void displayBook(int,vector<vector<string>> &books);
void displayCompanyDetails();
void edit();
void addBook(vector<vector<string>> &books);
void delBook(int,vector<vector<string>> &books);
void editBook(int,vector<vector<string>> &books);
// void rearrange(int);
void sales();
void clear(){system("clear");};

int main(){
    cout << "\n\n";
    displayCompanyDetails();
    bool state = login();
    if(state == true){
        clear();
        menu();
    }
    else{
        cout << "\n\n";
        clear();
        cout<< "Application is locked"<<endl;
        cout << "\n\n";

    }

}






bool login(){
    vector<vector<string>> login = {
        {"tonyroyze", "0^6N4iIA0uO2"},
        {"adristeph", "O9K&60!c%3aL" },
        {"$haZly", "m8ctb0g@2T0Z"},
        {"$arah", "I@Ap25@MJ5y8" },
        {"admin", "abc123"}
    };
    string uname, pass;
    bool unamecorrect;
    for(int attempts=0; attempts<3; attempts++){
        cout << "Insert user name : ";
        cin >> uname;
        for(int rc=0; rc<login.size(); rc++){
            string x = login[rc][0];
            string y = login[rc][1];
            if (uname == x){
                cout << "Insert password : ";
                cin >> pass;
                unamecorrect = true;
                if (pass == y){
                    cout << "\n\n";
                    return true;
                }
                else{
                    cout<<"Password is incorrect try again"<<endl;
                }
            }
        }
        if (unamecorrect != true)
            cout<<"User name is incorrect try again"<<endl;
        cout << "\n\n";
    }
    return false;
}

void displayAllDetails(const vector<vector<string>> &books){
    clear();
    cout.setf(ios::left);
    cout.width(25);
    cout << "ISBN No";
    cout.width(45);
    cout<< "Title";
    cout.width(20);
    cout << "Author";
    cout.width(15);
    cout << "Quanitity";
    cout.width(7);
    cout << "Price"<<endl<<endl;
    for(int rc=0; rc<books.size(); rc++){
        for(int cc=0; cc<books[rc].size(); cc++){
            int w;
            switch(cc){
                case 0:
                    w = 25;
                    break;
                case 1:
                    w = 45;
                    break;
                case 2:
                    w = 20;
                    break;
                case 3:
                    w = 15;
                    break;
                case 4:
                    w = 7;
                    break;
            }
            cout.setf(ios::left);
            cout.width(w);
            cout<<books[rc][cc];
        }cout<<endl;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    clear();
    cout << "\n\n";
    menu();
}

int search(const vector<vector<string>> &books){
    string bname;
    cout << "Insert book name : ";
    cin >> bname;
    for (int rc =0; rc<books.size() ;rc++){
        vector<string> temp = books[rc];
        auto it = find(temp.begin(), temp.end(), bname);
        if (it != temp.end()){
            int index = it -  temp.begin();
            //cout << "index found   :   " <<index<<endl;
            //cout << "row found     :   " <<rc<<endl;
            return rc;
        }

    }
    cout << "\n\n";
    return(-1);

}

void displayBook(int rowc, vector<vector<string>> &books){
    cout.setf(ios::left);
    cout.width(25);
    cout << "ISBN No";
    cout.width(45);
    cout<< "Title";
    cout.width(20);
    cout << "Author";
    cout.width(15);
    cout << "Quanitity";
    cout.width(7);
    cout << "Price"<<endl<<endl;
    for(int cc=0; cc<books[rowc].size(); cc++){
        int w;
        switch(cc){
            case 0:
                w = 25;
                break;
            case 1:
                w = 45;
                break;
            case 2:
                w = 20;
                break;
            case 3:
                w = 15;
                break;
            case 4:
                w = 7;
                break;
        }
        cout.setf(ios::left);
        cout.width(w);
        cout<<books[rowc][cc];
    }
    cout << "\n\n\n";
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
}




void menu(){
    clear();
    char option;
    int rc;
    cout << "Options" << endl;
    cout << "Display Books        --- D" << endl;
    cout << "Search for Book      --- S" << endl;
    cout << "Edit Books           --- E" << endl;
    cout << "Logout               --- O" << endl;
    cout << "Sales Portal         --- M" << endl;
    cout << "Quit Application     --- Q" << endl;// how to do?
    cout << "View Company Details --- V" << endl;
    cout << "\n\n";
    cout << "Enter Option : ";
    cin >> option;

    cout << "\n\n";
    switch (option) {
        case 'D':
            displayAllDetails(books_arr);
            break;
        case 'S':
            rc = search(books_arr);
            if (rc != -1){
                cout << "\n\n\n";
                displayBook(rc,books_arr);
            }

            else{
                cout<<"Searched book is unavailable\n\n\n";
                system( "read -n 1 -s -p \"Press any key to continue...\"" );
            }
            menu();
            break;
        case 'E':
            edit();
            break;
        case 'O':
            main();
            break;
        case 'M':
            sales();
            break;
        case 'Q':
            cout << "Quitting the Application"<<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            clear();
            exit(0);
            break;
        case 'V':
            displayCompanyDetails();
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            menu();
            break;
	    default:
            cout<<"Sorry that is not an option"<<endl<<endl;
            system( "read -n 1 -s -p \"Press any key to continue...\"" );
            menu();
    }
}

void edit(){
    clear();
    char option;
    int rc;
    cout << "Options" << endl;
    cout << "Add a New Book  --- N" << endl;
    cout << "Delete a Record --- X" << endl;
    cout << "Change a Record --- C" << endl;
    cout << "Go to Main Menu --- M" << endl;
    cout << "\n\n";
    cout << "Enter Option : ";
    cin >> option;
    cout << "\n\n";
    int row;
    switch (option) {
        case 'N':
            addBook(books_arr);
            break;
        case 'X':
            rc = search(books_arr);
            if (rc != -1)
                delBook(rc,books_arr);
            else
                cout<<"Searched book is unavailable\n\n\n";
            break;
        case 'C':
            rc = search(books_arr);
            if (rc != -1)
                editBook(rc,books_arr);
            else
                cout<<"Searched book is unavailable\n\n\n";
            break;
        case 'M':
            menu();
            break;
        default:
            cout<<"Sorry that is not an option"<<endl;
            break;
    }
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    edit();

}

void addBook(vector<vector<string>> &books){
    vector<string>temp; //creating a temperary vector
    bool state;
    clear();
    do
    {
        string isbn, bname, aname, quantity,price;
        char exit;
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
        books.push_back(temp);
        cout<<"\n\n";
        cout<< "To exit enter X :";
        cin >> exit;

        if(exit == 'X' || exit == 'x'){
            state = false;
        }
        else{
            state = true;
        }
        cout<< "Book successfully added"<<endl;
        cout<<"\n\n";
    }while (state == true);
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    //edit();
    menu();
}
void delBook(int row, vector<vector<string>> &books){
    vector<string>temp = books_arr[row];
    int size = temp.size();
    for(int cc=0; cc<size; cc++){
        // books.erase(books.begin()+cc);
        temp.pop_back();
    }cout<<endl;
    books_arr[row]=temp;
    cout<< "Book successfully deleted"<<endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    menu();

}
void editBook(int row, vector<vector<string>> &books){
    vector<string>temp; //creating a temperary vector
    string isbn, bname, aname, quantity,price;
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
    books[row] = temp;
    cout<< "Book successfully edited"<<endl;
    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    //edit();
    menu();
}
// void rearrage(int rc)
// {
//
// }
void displayCompanyDetails(){
    clear();
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout<< "| \t\t\t Company Name : GENIUS BOOKS \t\t\t\t |"<<endl;
    cout<< "| \t\t\t Company Phone Number : 011-2799729 \t\t\t |"<<endl;
    cout<< "| \t\t\t Company Email : info@geniusbooks.lk \t\t\t |"<<endl;
    cout<<"---------------------------------------------------------------------------------"<<endl;
    cout << "\n\n";



}
void sales(){
    clear();
    vector<int> quantities = {3, 4, 10, 7, 12, 1, 5};
    vector<int> price = {2000, 2000, 2000, 2000, 2000, 2000, 3000};
    vector<int> itemprices;
    vector<int> qtz;
    vector<int> totalprices;
    vector<string> booknames;
    int qty, rc, ip, tp, tot =0;
    string bname;
    bool state;
    do
    {
        rc = search(books_arr);
        if (rc != -1){

            //cout << "book found" << endl;
            cout << "\n\n\n";
            displayBook(rc,books_arr);
            cout<<"\n\n";
            cout<< "Enter Quanitity : ";
            cin >> qty;
            qtz.push_back(qty);

            booknames.push_back(books_arr[rc][1]);

            itemprices.push_back(price[rc]);
            tp = price[rc] * qty;
            totalprices.push_back(tp);
            quantities[rc] -= qty;
            cout <<"Books left :"<< quantities[rc]<<endl;;
            tot += tp;
        }

        else
            cout<<"Searched book is unavailable\n\n\n";

        char exit;

        cout<< "To exit enter X :";
        cin >> exit;

        if(exit == 'X' || exit == 'x'){
            state = false;
        }
        else{
            state = true;
        }
        cout<<"\n\n";
    }while (state == true);

    //priting bill
    displayCompanyDetails();
    cout.setf(ios::left);
    cout.width(55);
    cout<< "Book Name";
    cout.width(7);
    cout << "Price";
    cout.width(12);
    cout << "Quantity";
    cout.width(9);
    cout << "Total"<<endl;


    for (int a=0;a<booknames.size();a++){
        if (qtz[a] != 0){
            cout.setf(ios::left);
            cout.width(55);
            cout<< booknames[a];
            cout.width(7);
            cout << itemprices[a];
            cout.width(12);
            cout << qtz[a];
            cout.width(9);
            cout<<totalprices[a]<<"\n\n\n";
        }
    }
    cout << "---------------------------------------------------"<<endl;
    cout << "TOTAL : " << tot <<endl;

    system( "read -n 1 -s -p \"Press any key to continue...\"" );
    menu();
}
