

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

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
    public:
        MinHeap(int C){
            capacity = C;
            heap_size = 0;
            harr = new int[capacity];
        }
        int parent(int i){ return ((i-1)/2); }

        int left(int i){ return (2*i+1); }

        int right(int i){ return (2*i+2); }

        void minHeapify(int i){
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if(l<heap_size && harr[l]<harr[i])
                smallest = l;
            if(r<heap_size && harr[r]<harr[smallest])
                smallest = r;
            if(smallest!=i){
                // cout<<harr[i]<<" "<<harr[smallest]<<endl;
                swap(harr[i],harr[smallest]);
                // cout<<harr[i]<<" "<<harr[smallest]<<endl;
                // cout<<harr[0]<<endl;
                minHeapify(smallest);
            }
        }
        void printHeap(){
            for(int i = 0; i<heap_size; i++){
                cout<<harr[i]<<" ";
            }cout<<endl;
        }

        void insertKey(int k){
            if(heap_size == capacity){
                cout<<"OVERFLOW"<<endl;
                return;
            }
            heap_size++;
            int i = heap_size-1;
            harr[i] = k;
            while(i!=0 && harr[parent(i)]>harr[i]){
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
            // cout<<k<<" "<<heap_size<<endl;

        }


        int extractMin(){
            if(heap_size<=0){
                return INT_MAX;
            }
            if(heap_size == 1){
                heap_size--;
                return harr[0];
            }
            int root = harr[0];
            harr[0] = harr[heap_size-1];
            heap_size--;
            minHeapify(0);
            return root;

        }

        void decreaseKey(int i, int new_val){
            harr[i] = new_val;
            while(i!=0 && harr[parent(i)]>harr[i]){
                swap(harr[i],harr[parent(i)]);
                i = parent(i);
            }
        }
        void deleteKey(int i){
            decreaseKey(i,INT_MIN);
            extractMin();
        }
        int getMin(){
            return harr[0];
        }

};

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    // h.printHeap();
    cout << h.extractMin() << " ";
    // h.printHeap();
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}