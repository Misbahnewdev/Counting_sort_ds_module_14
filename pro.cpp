#include<bits/stdc++.h>
using namespace std;

void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Before sort-> ";
    printArray(a,n);
    cout<<endl;
    //step 1 //find max 
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    cout<<"max is -> "<<max<<endl;
    //step 2 //initialize of count array

    int count[max+1];

    for(int i=0;i<=max;i++)
    {
        count[i] = 0;
    }

    //step 3 //frequency count array

    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    cout<<"Frequency count-> ";
    printArray(count,max+1);
    //step //4 cumulative sum// prefix sum

    for(int i=1;i<=max;i++)
    {
        count[i] += count[i-1];
    }
    cout<<endl;
    cout<<"Cumulative Sum -> ";
    printArray(count,max+1);
    //step 5// final arrry --> Backward Traversal of Basic Array
    int final[n];
    for(int i=n-1;i>=0;i--)
    {
       count[a[i]]--;
       int k = count[a[i]];
       final[k] = a[i];
    }
    cout<<endl;
    cout<<"After sort -> ";
    printArray(final,n);
}