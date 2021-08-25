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
   List* head;
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
   cout<<"FileName\tAllocated Blocks\n";
   for(int i = 0; i < nfile; i++) {
       cout<<files[i].name<<"\t\t";
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
