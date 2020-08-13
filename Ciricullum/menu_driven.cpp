

//Shrey Dubey

//Contact Me at wshrey09@gmail.com

//menu drives program for unsorted array


#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;


void insert(int arr[], int &n){
    int num;
    cout<<"Enter number to be inserted: ";cin>>num;
    arr[n] = num;
    n++;
}

void delete_num(int arr[], int &n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int i;
    bool is_there = false;
    int num;
    cout<<"Enter number to be deleted: ";cin>>num;
    for(i = 0; i<n; i++){
        if(arr[i] == num){
            is_there = true;
            break;
        }
    }
    if(!is_there){
        cout<<"ENTER A VALID NUMBER"<<endl;
        return;
    }
    //i is the index to be deleted
    for(int j = i; j<n-1; j++){
        swap(arr[j],arr[j+1]);
    }
    n--;
}

void display(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }

    fo(n){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void find_min(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int max = INT_MIN;
    fo(n){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<<"MAX IS: "<<max<<endl;
}

void find_max(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int min = INT_MAX;
    fo(n){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<"MIN IS: "<<min<<endl;
}

void search(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int num;
    cout<<"Enter number to be searched: ";cin>>num;
    fo(n){
        if(arr[i] == num){
            cout<<"Present at index: "<<i<<endl;
            return;
        }
    }
    cout<<"Not Present"<<endl;
}


int main(){
    int arr[10000];
    int choice;
    int n = 0;
    do{
        cout<<"INSERT(1)"<<endl;
        cout<<"DELETE(2)"<<endl;
        cout<<"SEARCH(3)"<<endl;
        cout<<"DISPLAY(4)"<<endl;
        cout<<"FIND MIN(5)"<<endl;
        cout<<"FIND MAX(6)"<<endl;
        cout<<"EXIT(7)"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            insert(arr,n);
            break;
        case 2:
            delete_num(arr,n);
            break;
        case 3:
            search(arr,n);
            break;
        case 4:
            display(arr,n);
            break;
        case 5:
            find_min(arr,n);
            break;
        case 6:
            find_max(arr,n);
            break;
        case 7:
            cout<<"THANK YOU FOR INTERACTING"<<endl;
            break;
        default:
            cout<<"PLEASE ENTER A VALID QUERY"<<endl;
            break;
        }
    }while(choice!=7);



}