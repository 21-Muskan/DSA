#include<iostream>
using namespace std;

void conquere(int array[],int s, int mid ,int e){
    int merge[e-s+1];
    int ind1=s;
    int ind2=mid+1;
    int x =0;
    while (ind1<=mid && ind2<=e)
    {
        if (array[ind1]<array[ind2])
        {
            merge[x++]=array[ind1++];
        }
        else{
            merge[x++]=array[ind2++];
        }
    }
    while (ind1<=mid)
    {
        merge[x++]=array[ind1++];
    }
    while (ind2<=e)
    {
        merge[x++]=array[ind2++];
    }

    for (int i = 0 ; i<x; i++)
    {
        array[s+i]=merge[i];
    }
    
}

void mergesort(int array[] , int s , int e){
    if (s>=e)
    {
        return;
    }
    int mid = (e+s)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    conquere(array,s,mid,e);
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    int array[n];
    cout<<"Enter the credits obtained : ";
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    mergesort(array,0,n-1);
    cout<<"Sorted Credits: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< array[i] << " ";
    }
    return 0;
}
