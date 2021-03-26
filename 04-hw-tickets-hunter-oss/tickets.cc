/*
 *        File: tickets.cc
 *      Author: Hunter
 *        Date: March 26th 2021
 * Description: Read license plates from input and determine violations
 */

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

vector<string> licNums;

string toUpperCase(string s)
{
    for(int i =0; i< s.length(); i++)
    {
    s[i] = toupper(s[i]);
    }

return s;
}

void loadData(string file){
string line;
try{
    ifstream MyReadFile(file);

    while (getline (MyReadFile, line))
    {
    licNums.push_back(toUpperCase(line));
    }
}catch(exception e){
cout<<"Error: File Not Found"<<endl;
}

}

bool isValid(string lic){
int valid[8];
int flag =1;
for(int i =0; i<8; i++){
valid[i] = 0;
}
string s = toUpperCase(lic);
for(int i =0 ; i<8; i++){
if(i == 0 || i==1){
if(s[i] >=65 && s[i]<=90){
valid[i] =1;
}else{
valid[i] =0;
}
}else{
if(s[i]>=48 && s[i]<=57){
valid[i] = 1;
}else{
valid[i] =0;
}
}
}

for(int i =0; i<8; i++){
if(valid[i] == 0){
flag =0;
}
}

return flag;
}

int violationCount(string s){
int count =0;
for(int i = 0; i < licNums.size(); i++){
if(toUpperCase(s) == licNums[i]){
count++;
}
}
return count;
}

void display(string s){
cout<<"Driver License "<<toUpperCase(s)<<" has "<<violationCount(s)<<" violation's." << endl;
cout<<"Driver License "<<toUpperCase(s)<<" should be suspended.";
}

int main(){

string line,file;
string input;
int suspendedLic = 0;
cout<<"Enter the data file name: ";
cin >> file;

loadData(file);

while(true){
cout<<"\nEnter a license number(Q/q to quit): ";
cin>>input;

if( input == "Q" || input == "q"){
break;
}

if(!isValid(input)){
cout<<"Error: "<<input<<" is an invalid license number.";
continue;
}

int t = violationCount(input);

if(t >= 6){
display(input);
suspendedLic++;
}else{
cout<<"Driver License "<<toUpperCase(input)<<" has "<<violationCount(toUpperCase(input))<<" violations. " << endl;
}
}
cout<<"Total Number of suspended License's: "<<suspendedLic;

return 0;
}

