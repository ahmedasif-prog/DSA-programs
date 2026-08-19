#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void insertionsort(vector<T>&arr)
{
    for(int i=1;i<arr.size();i++)
    {
        T key = arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    vector<double> arr = {5.3,0.5,3.7,4.8};
    insertionsort(arr);
    for(double x:arr)
    {
        cout<<x<<" ";
    }

}