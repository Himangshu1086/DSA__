#include<bits/stdc++.h>

using namespace std;


// - Compare x with the middle element.
// - If x matches with the middle element, we return the mid index.
// - Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
// - Else (x is smaller) recur for the left half.

// 1 2 3 4 5 6 7

int binarySearch( int arr[] , int l , int r , int x)
{
    if (r >= l) {

        int mid = l + (r - l) / 2;
        if ( x > arr[mid])
            return binarySearch(arr , mid + 1 , r , x);
        if (x == arr[mid])
            return mid;
        else
            return binarySearch(arr , l , mid - 1 , x );

    }


    return -1;
}

int main()
{

    int arr [] = { 1, 2, 3,        4 , 5, 6 , 7};
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout <<  binarySearch(arr        , 0 , n - 1 , x);

}
