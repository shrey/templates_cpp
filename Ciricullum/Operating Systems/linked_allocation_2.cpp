#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class List{
    public :
    int block;
    List *next;

    List(int n){
        this->block=n;
        this->next=NULL;
    }

    void print(){
        List* curr= this ;
        while(curr){
            cout<<curr->block<<((curr->next)?"->":"\n");
            curr=curr->next;
        }
    }
};

typedef struct file {
    string name ;
    int size, blocks;
    List* head,*tail;
} File;

vector<File> files;
int freeblocks[100]={}, memorySize, blockSize, totalBlocks,remainingBlocks, nfile;

void insertFile(){
    File curr;
    cout<<"Enter the name of the file :";
    cin>>curr.name;
    cout<<"Enter the size of the file : ";
    cin>>curr.size;
    cout<<endl;
    curr.blocks = curr.size/blockSize ;
    if(float(curr.size)/(float)blockSize > curr.blocks) curr.blocks++;
    if(curr.blocks > remainingBlocks ) {
        cout<<"File could not be allocated!\n";
        return;
    }
    else {
        List *t, *p;
        for(int j = 0; j < curr.blocks; j++) {
            int r = random()%totalBlocks;
            if(freeblocks[r] == 0) {
                freeblocks[r] = 1;
                remainingBlocks --;
                t = new List(r);
                if(j == 0) {
                    curr.head = t;
                    p = curr.head;
                }
                else {
                    p->next = t;
                    p = t;
                    curr.tail=p;
                }
            }
            else j--;
        }
    }
    files.push_back(curr);
    nfile++;
    if(remainingBlocks  == 0) {
        printf("Memory is fully occupied!\n");
    }
}

void printFiles(){
    printf("\nFile allocation:\n");
    cout<<"FileName\tStarting Block\tEnding Block\tAllocated Blocks\n";
    for(int i = 0; i < nfile; i++) {
        cout<<files[i].name<<"\t\t"<<files[i].head->block<<"\t\t"<<files[i].tail->block<<"\t\t";
        files[i].head->print();
    }
}

void deleteFile(){
    string filename;
    cout<<"Enter the name of the file to be deleted : ";
    cin>>filename;
    cout<<endl;
    int index = -1;
    for(int i=0;i<nfile;i++){
        if(files[i].name==filename){
            index=i;
            break;
        }
    }
    if(index==-1){
        cout<<"File is not present.\n";
        return;
    }
    auto c=files[index].head;
    files.erase(files.begin()+index);
    nfile--;
    while(c){
        freeblocks[c->block]=0;
        remainingBlocks++;
        auto p=c;
        c=c->next;
        free(p);
    }
    cout<<"File has been deleted.\n";
}

void searchFile(){
    string filename;
    cout<<"Enter the name of the file to be searched : ";
    cin>>filename;
    int index=-1;
    for(int i=0;i<nfile;i++){
        if(files[i].name==filename){
            index=i;
            break;
        }
    }
    if(index==-1){
        cout<<"File is not present.\n";
        return;
    }
    cout<<"FileName\tStarting Block\tEnding Block\tAllocated Blocks\n";
    cout<<files[index].name<<"\t\t"<<files[index].head->block<<"\t\t"<<files[index].tail->block<<"\t\t";
    files[index].head->print();
}

void findBlock(){
    string filename;
    cout<<"Enter the name of the file to be searched : ";
    cin>>filename;
    int index = -1;
    for(int i=0;i<nfile;i++){
        if(files[i].name==filename){
            index=i;
            break;
        }
    }
    if(index==-1){
        cout<<"File is not present.\n";
        return;
    }
    int k;
    cout<<"Enter number of block you want to find : ";
    cin>>k;
    int cnt=1;
    auto curr = files[index].head;
    while(curr){
        if(cnt==k){
            cout<<"Block "<<k<<" of the given file is : "<<curr->block<<endl;
            return;
        }
        curr=curr->next;
        cnt++;
    }
    cout<<"File occupies less than "<<k<<" blocks!"<<endl;
}

int main(){
    cout<<"Enter the size of memory : "<<endl;
    cin>>memorySize;
    cout<<"Enter the size of block : "<<endl;
    cin>>blockSize;
    totalBlocks = memorySize/blockSize;
    cout<<"No. of blocks : "<<totalBlocks<<endl;
    remainingBlocks = totalBlocks;
    for(int i = 0; i < totalBlocks; i++) {
        if(freeblocks[i] == 0) cout<<i<<" ";
    }
    cout<<endl;
    nfile=0;
    int x=6;
    cout<<"<---------Menu--------->\n1.Insert a file\n2.Delete a file.\n3.Print existing files.\n4.Search a file. \n5.Find k-th block for a file\n6.Exit\n";
    do{
        cout<<"Enter your choice : \n";
        cin>>x;
        switch(x){
            case 1:
                insertFile();
                break;
            case 2:
                deleteFile();
                break;
            case 3:
                printFiles();
                break;
            case 4:
                searchFile();
                break;
            case 5:
                findBlock();
                break;
            case 6:
                break;
            default:
                cout<<"Enter a valid number.\n";
        }
    }while(x!=6);
    return 0;
}