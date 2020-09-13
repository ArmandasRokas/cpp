/*
    Jeg kunne også lave en class, som hedder bag og
    har alle disse metoder.
*/

#include <iostream> 
#include<set>                
#include<string>
                    
using std::cin; 
using std::cout;                 
using std::set;
using std::string;

template <typename T>
int controller(set<T>& list);

template <typename T>
void add(set<T>& list, T element){
    list.insert(element);
}
template <typename T>
void del(set<T>& list, int number){
    list.erase(number);
}

template <typename T>
void print(set<T> list){
    // for (std::set<int>::iterator it=list.begin(); it!=list.end(); ++it)
    // { 
    //    cout << ' ' << *it;
    // }
    for(auto e : list){
        cout << e <<  " ";
    }
}

template <typename T>
void qry(set<T> list, T element){
    bool is_in = list.find(element) != list.end();
    if(is_in){
        cout << "T";
    } else {
        cout << "F";
    }
}

// void qry(set<int> list, int e){
//     bool is_in = list.find(e) != list.end();
//     cout << is_in;
//     }


int main () // This the main entry of the program
{
    
    // add(bag, 1);
    // add(bag, 2);
    // print(bag);
    set<int> bag;
    while(controller(bag));
  //  print(bag);
    
    return 0;
}

template <typename T>
int controller(set<T>& list){
    string command;
    cin >> command; 
    int number;

    if(command == "add"){
        cin >> number;
        add(list, number);
        return 1;
    } else if(command == "del"){
        cin >> number;
        del(list, number);
        return 1;
    } else if(command == "qry"){
        cin >> number;
        qry(list, number);
        return 1;
    } else if(command == "quit"){
        return 0;
        // Quit
    } else{
        // Wrong command
    }
}
