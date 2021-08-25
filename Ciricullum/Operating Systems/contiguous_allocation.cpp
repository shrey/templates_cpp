#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

typedef struct file {
   string name ;
   int size, blocks;
   int idx;
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
       int cnt=0;int ind=-1;bool poss =false;
       for(int i=0 ;i<totalBlocks;i++){
           if(freeblocks[i]==0){
               cnt++;
               if(cnt==1) ind=i;
               if(cnt==curr.blocks) {poss=true;break;}
           }
           else{
               cnt=0;
           }
       }
       if(poss){
           curr.idx = ind;
           for(int i = 0 ;i<curr.blocks ;i++){
               freeblocks[curr.idx+i]=1;
               remainingBlocks--;
           }
       }
       else{
           cout<<"File could not be allocated because there are no contiguous blocks.\n";
           return;
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
   cout<<"FileName\tStarting Block\tAllocated Blocks\n";
   for(int i = 0; i < nfile; i++) {
       cout<<files[i].name<<"\t\t"<<files[i].idx<<"\t\t";
       for( int j=0 ; j < files[i].blocks ; j++){
           cout<<files[i].idx+j<<(j==files[i].blocks-1?"\n":",");
       }
       cout<<endl;
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
   auto c=files[index];
   files.erase(files.begin()+index);
   nfile--;
   for(int i = 0;i<c.blocks;i++){
       freeblocks[c.idx+i]=0;
       remainingBlocks++;
   }
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
