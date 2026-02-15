#include <iostream>

using namespace std;

int main(){
    int menue_number;
    cout <<" >:< # Welcon my rastorant # >:<" << endl;
    cout << "choose a number "<< endl;
    cin >> menue_number;

    switch(menue_number)
    {
        case 1:
           cout << "You chose Burger"<<endl;
           break;
        case 2:
          cout << "You chose Pizza" << endl;
          break;
        case 3:
           cout << "You chose Sandwitch" << endl;
           break;
        case 4:
          cout <<"Exiting program" << endl;
          break;
        default:
        cout << "Invalid choicd";
    }
    return 0;
}
