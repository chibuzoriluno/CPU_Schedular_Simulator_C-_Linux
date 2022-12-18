#include <iostream> 
#include <fstream>

using namespace std;

int main(void) { 
ofstream ourfile; 
ourfile.open("input.txt");
ourfile << "5:0:3\n4:1:2\n3:1:1\n4:2:2\n3:3:1";
ourfile.close();
return 0;
}
