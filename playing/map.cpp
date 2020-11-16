#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(void){
	std::map<string,string> string_map;
	string_map["abc"] = "def";
	string_map["abc"] = "second"; // Updates abc value
	std::cout << string_map["abc"] << endl;
}
