#include<iostream>
#include<vector>
using namespace std;
template <typename T>
void combsort(vector<T> &arr)
{
    bool swapped = true;
    int n = arr.size();
    int gap = n;
    while(gap>1||swapped)
    {
        gap = gap/1.3;
        if(gap<1) gap=1;
        swapped = false;
        for(int i=0;i+gap<n;i++)
        {
            if(arr[i]>arr[i+gap])
            {
                swap(arr[i],arr[i+gap]);
                swapped = true;
            }
        }
    }
}
int main()
{
    vector<double> arr = {5.3,0.5,3.7,4.8};
    combsort(arr);
    for(double x:arr)
    {
        cout<<x<<" ";
    }

}