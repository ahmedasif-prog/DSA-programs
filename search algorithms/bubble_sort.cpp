#include<iostream>
#include<vector>
using namespace std;
template <typename T> 
void bubble_sort(vector<T> &arr)
{
    
    for(int i=0;i<arr.size()-1;i++)
    {
        bool swapped = false;
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            
        }
        if(!swapped){
            break;
        }  
    }
}
int main()
{
    vector<double> arr = {1.3,0.5,3.7,4.8};
    bubble_sort(arr);
    for(double x:arr)
    {
        cout<<x<<" ";
    }

}