#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

const int SIZE = 5;

struct Process{
int burst_time, arrival_time, priority;
};

struct Prc{
int waiting_time;
};

void fcfs(Process processes[], Prc prcs[], int num_processes){

int totalWT =0;
int current_time = 0;
for (int i = 0; i < num_processes; i++){

// Calculate the waiting time for the current process
prcs[i].waiting_time = current_time - processes[i].arrival_time;
totalWT += prcs[i].waiting_time;

// Increment the current time by the burst time of the current process
current_time += processes[i].burst_time;

}

double avgWT = (double)totalWT / num_processes;

 // Open the output file
ofstream outputFile("output.txt");

// Write the waiting time and average waiting time to the output file
outputFile << "Scheduling Method: First Come First Served\n"<<"Process Waiting Times:"<<endl;
for (int i = 0; i < num_processes; i++){
outputFile <<"P"<<i + 1<<": "<<prcs[i].waiting_time<<" ms"<< endl;
}
outputFile <<"Average waiting time: "<<avgWT<<" ms"<< endl;

// Close the output file
outputFile.close();

}


int main(){


//Declare an array to stor the input data
Process processes[SIZE];

//Declare an array to store  arrival time
Prc prcs[SIZE];

//open the input file
ifstream myFileStream("input.txt");

//if input file does not exist, print message to screen
if (!myFileStream.is_open()){
cout<<"File failed to open"<<endl;
return 0;
}
string line;
string bt;
string at;
string py;
int counter = -1;

//read the values from the file and store them in the array
while(getline(myFileStream, line)){

counter = counter + 1;

stringstream ss(line);

getline(ss, bt, ':');
getline(ss, at, ':');
getline(ss, py, ':');

processes[counter].burst_time = stoi(bt);
processes[counter].arrival_time = stoi(at);
processes[counter].priority = stoi(py);

cout<<processes[counter].burst_time<<"\t"<<processes[counter].arrival_time<<"\t"<<processes[counter].priority<<endl;

}

myFileStream.close();

fcfs(processes, prcs, SIZE);
}
