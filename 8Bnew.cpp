#include<iostream>
using namespace std;


int partition(string name[] ,int credit[],int s , int p , int e){
    int pivot = credit[s];
    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
        if (credit[i]<pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s+cnt;
    swap(credit[pivotIndex],credit[s]);
    swap(name[pivotIndex],name[s]);

    int i=s;
    int j=e;
    while (i<pivotIndex && j >pivotIndex)
    {
        while (credit[i]<credit[pivotIndex])
        {
            i++;
        }
        while (credit[j]>credit[pivotIndex])
        {
            j--;
        }
        if (i<pivotIndex && j >pivotIndex)
        {
            swap(credit[i++],credit[j--]);
            swap(name[i++],name[j--]);
        }
        
    }
    return pivotIndex;    
}

void quicksort(string name[],int credit[],int s , int e){
    if (s>=e)
    {
        return;
    }
    int p = partition(name ,credit,s,p,e);
    quicksort(name ,credit,s,p-1);
    quicksort(name, credit,p+1,e);
}


int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the number of students: ";
    cin>>n;
    string names[n];
    int credits[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the name : ";
        cin>>names[i];
        cout<<"Enter the credit : ";
        cin>>credits[i];
    }
    quicksort(names,credits,0,n-1);
    cout<<"Top 3 students: "<<endl;
    for (int i = n-1; i >= n-3; i--)
    {
        cout<<names[i]<<" : ";
        cout<<credits[i]<<endl;
    }
    
    
    
    return 0;
}
