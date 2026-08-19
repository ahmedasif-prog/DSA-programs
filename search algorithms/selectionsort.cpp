#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void selectionsort(vector<T> &arr)
{
    for(int i=0;i<arr.size()-1;i++)
    {
        int min_idx=i;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[min_idx]>arr[j]) min_idx=j;
        }
        if (min_idx!=i) swap(arr[i],arr[min_idx]);
    }
}
int main()
{
    vector<double> arr = {5.3,0.5,3.7,4.8};
    selectionsort(arr);
    for(double x:arr)
    {
        cout<<x<<" ";
    }

}