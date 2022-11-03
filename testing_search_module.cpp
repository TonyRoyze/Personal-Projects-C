#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;




int main(){
    vector<vector<string>> books_arr = {

        {"ISBN 13: 9780747532743", "Harry_Potter_and_the_Philosopher’s_Stone","J. K. Rowling", "3", "2000" },
        {"ISBN 13: 9780439064866", "Harry_Potter_and_the_Chamber_of_Secrets","J. K. Rowling", "4", "2000" },
        {"ISBN 13: 9780747546290", "Harry_Potter_and_the_Prisoner_of_Azkaban","J. K. Rowling", "10", "2000" },
        {"ISBN 13: 9780439139601", "Harry_Potter_and_the_Goblet_of_Fire","J. K. Rowling", "7", "2000" },
        {"ISBN 13: 9780439358071", "Harry_Potter_and_the_Order_of_the_Phoenix","J. K. Rowling", "12", "2000" },
        {"ISBN 13: 9780439785969", "Harry_Potter_and_the_Half-Blood_Prince","J. K. Rowling", "1", "2000" },
        {"ISBN 13: 9780545139700", "Harry_Potter_and_the_Deathly_Hallows","J. K. Rowling", "5", "3000" }
        // ,{"ISBN 13: 9781338099133", "Harry_Potter_and_the_Cursed_Child","J. K. Rowling", "7", "3000" }
    };
    // vector<string> books_arr = {
    //     {"2", "Harry Potter and the Prisoner of Azkaban","J. K. Rowling", "4", "2000" },
    // };

    string target = "Harry_Potter_and_the_Chamber_of_Secrets";
    int row;
     for (int i =0; i<books_arr.size() ;i++){
         vector<string> temp = books_arr[i];
         auto it = find(temp.begin(), temp.end(), target);
         if (it != temp.end()){
             int index = it -  temp.begin();
             cout << "index found   :   " <<index<<endl;
             row=i;
         }

     }
     vector<string> temp2 = books_arr[row];
     for (auto det : temp2){
         cout<< det << ","<<"\t";
     }
     cout<<endl<<endl;


}
