

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



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

int search_ind(int arr[], int n, int num){
    int s = 0, e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == num){
            return mid;
        }
        else if(arr[mid]>num){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

void search_no(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int s = 0, e = n-1;
    int num;
    cin>>num;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == num){
            cout<<"Found Number at index: "<<mid<<endl;
            return;
        }
        else if(arr[mid]>num){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    cout<<"Not Present"<<endl;
}

void insert(int arr[], int &n){
    int num;
    cin>>num;
    arr[n] = num;
    n++;
    sort(arr,arr+n);
}
void delete_num(int arr[], int &n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    int num;
    cin>>num;
    arr[search_ind(arr,n,num)] = INT_MAX;
    sort(arr,arr+n);
    n--;
}
void find_max(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    cout<<"MAX IS: "<<arr[n-1]<<endl;
}
void find_min(int arr[], int n){
    if(n == 0){
        cout<<"EMPTY ARRAY"<<endl;
        return;
    }
    cout<<"MIN IS: "<<arr[0]<<endl;
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
int main(){
    int arr[1000];
    int n = 0;
    int choice;
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
            search_no(arr,n);
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