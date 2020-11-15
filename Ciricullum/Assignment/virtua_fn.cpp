#include <iostream>
#include<fstream>
#include<string.h>
#define SIZE 80
using namespace std;

void WriteFile(){
    string data = "";
    string l = "";
    cout<<"Enter the text:\n";
    while(getline(cin,l) && !l.empty()) {
        data+=l+'\n';
    }
    ofstream F("Data.txt");
    F<<data;
    F.close();
}

int CountWords(){
    int count=0;
    ifstream F("Data.txt");
    char word[SIZE];
    while(!F.eof()){
        F>>word;
        count++;
    }
    count--;
    F.close();
    return count;
}

int CountLines(){
    int count=0;
    ifstream F("Data.txt");
    char l[SIZE];
    while(F.getline(l,SIZE)){
        count++;
    }
    F.close();
    return count;
}

int CountCharacters(){
    int count=0;
    ifstream F("Data.txt");
    char ch;
    while(!F.eof()){
        ch=F.get();
        if(ch!='\n' && ch!=' '){
            count++;
        }
    }
    count--;
    F.close();
    return count;
}

int main(){
    WriteFile();
    cout<<endl;
    cout<<"Number of lines:"<<CountLines()<<"\n";
    cout<<"Number of words:"<<CountWords()<<"\n";
    cout<<"Number of characters:"<<CountCharacters()<<"\n";
    return 0;
}
