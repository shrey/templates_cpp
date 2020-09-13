#include<iostream>
#include<fstream>
#include<stack>
using namespace std;


int computeSpaces(char ch[]){
    int spaces = 0;
    while(ch[spaces]==' '){
        spaces++;
    }
    return spaces;
}

int main(){
    FILE* filePointer;
    int bufferLength = 255;
    char buffer[bufferLength];
    stack <int> s;
    s.push(-1);
    filePointer = fopen("file.txt", "r");
    int line = 1;
    while(fgets(buffer, bufferLength, filePointer)) {
        int spaces = computeSpaces(buffer);
        cout<<spaces<<endl;
        if(spaces == s.top()){
            s.pop();
        }
        else if(spaces<s.top()){
            cout<<"Line "<<line<<" has error"<<"\n";
            break;
        }
        else{
            s.push(spaces);
        }
        line++;
        // cout<<buffer<<endl;
    }
    if(!s.empty()){
        cout<<"There are extra lines"<<endl;
    }

    fclose(filePointer);

}
