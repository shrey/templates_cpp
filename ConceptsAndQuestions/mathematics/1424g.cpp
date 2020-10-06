

//Shrey Dubey

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
#include <math.h>
#include<climits>
using namespace std;

void findMaxGuests(int arrl[], int exit[], int n)
{
   sort(arrl, arrl+n);
   sort(exit, exit+n);

   int guests_in = 1, max_guests = 1, time = arrl[0];
   int i = 1, j = 0;

   while (i < n && j < n)
   {
      if (arrl[i] < exit[j])
      {
          guests_in++;
          if (guests_in > max_guests)
          {
              max_guests = guests_in;
              time = arrl[i];
          }
          i++;
      }
      else
      {
          guests_in--;
          j++;
      }
   }

   cout<<time<<" "<<max_guests<<"\n";
}

int main()
{

        int n;
        cin>>n;
        int arr[n],arr2[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i]>>arr2[i];
        }
        findMaxGuests(arr,arr2,n);

    return 0;
}