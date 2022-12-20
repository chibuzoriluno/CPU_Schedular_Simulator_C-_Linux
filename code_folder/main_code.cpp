#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

struct input_structure{
int burst_time, arrival_time, priority;
}input_data[5];

int main(){
ifstream myFileStream("input.txt");
if (!myFileStream.is_open()){
cout<<"File failed to open"<<endl;
return 0;
}
string line;
string bt;
string at;
string py;
int counter = -1;

while(getline(myFileStream, line)){
counter = counter + 1;
stringstream ss(line);
getline(ss, bt, ':');
getline(ss, at, ':');
getline(ss, py, ':');
input_data[counter].burst_time = stoi(bt);
input_data[counter].arrival_time = stoi(at);
input_data[counter].priority = stoi(py);
cout<<input_data[counter].burst_time<<"\t"<<input_data[counter].arrival_time<<"\t"<<input_data[counter].priority<<endl;

}

}
