#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int prev=1;
        int a=1;
        int b=1;
        int ans=1;
        for(int i=2;i<n;i++){
            if(arr[i]>arr[i-1]){
                a++;
            }else{
                b++;
            }
            if(b>prev){
                prev=a;
                b=1;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}