#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class IndexBlock{
    public :
    int blockid;
    vector<int> blocks;

    void print(){
        for(int i=0;i<this->blocks.size();i++){
            cout<<this->blocks[i]<<(i==this->blocks.size()-1?"\n":",");
        }
    }
};

typedef struct file {
    string name ;
    int size, blocks;
    IndexBlock* idx;
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
    curr.blocks = curr.size/blockSize + (curr.size%blockSize?1:0);
    if(float(curr.size)/(float)blockSize > curr.blocks) curr.blocks++;
    if(curr.blocks > remainingBlocks ) {
        cout<<"File could not be allocated!\n";
        return;
    }
    else {
        IndexBlock* t = new IndexBlock();
        int r = random()%totalBlocks;
        while(freeblocks[r]==1) r=random()%totalBlocks;
        t->blockid = r;
        freeblocks[r] = 1;
        remainingBlocks --;
        for(int j = 0; j < curr.blocks ; j++) {
            int r = random()%totalBlocks;
            if(freeblocks[r] == 0) {
                freeblocks[r] = 1;
                remainingBlocks --;
                t->blocks.push_back(r);
            }
            else j--;
        }
        curr.idx = t;
    }
    files.push_back(curr);
    nfile++;
    if(remainingBlocks  == 0) {
        printf("Memory is fully occupied!\n");
    }
}

void printFiles(){
    printf("\nFile allocation:\n");
    cout<<"FileName\tIndexedBlock\tAllocated Blocks\n";
    for(int i = 0; i < nfile; i++) {
        cout<<files[i].name<<"\t\t"<<files[i].idx->blockid<<"\t\t";
        files[i].idx->print();
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
    auto c=files[index].idx;
    files.erase(files.begin()+index);
    nfile--;
    for(int i = 0;i<c->blocks.size();i++){
        freeblocks[c->blocks[i]] = 0;
    }
    free(c);
    cout<<"File has been deleted.\n";
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
    int x=5;
    cout<<"<---------Menu--------->\n1.Insert a file\n2.Delete a file.\n3.Print existing files.\n4.Exit\n";
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
                break;
            default:
                cout<<"Enter a valid number.\n";
        }
    }while(x!=4);
    return 0;
}