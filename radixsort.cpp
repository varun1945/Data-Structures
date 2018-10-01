#include<iostream>
using namespace std;
void count_sort(int ,int ,int );
int getmax(int *a,int n)
{
    int max=0;
    int min=0;
    for(int i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}
void count_sort(int *a,int n,int exp)
{
    int i;
    int count[20];
    int output[20];
    for(i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
    }
    
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    
    for(i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
    
}
void radix_sort(int *a,int n)
{
    
    int exp,i;
    int data=getmax(a,n);
    for(exp=1;data/exp>0;exp=exp*10)
    {
        count_sort(a,n,exp);
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int i,n;
    int a[20];
    cout<<"enter size";
    cin>>n;
    cout<<"enter elements";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix_sort(a,n);
}



