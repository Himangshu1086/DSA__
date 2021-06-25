#include<bits/stdc++.h>

using namespace std;

     int binarySearch( vector<int>& num2, int l, int r , int x)
    {
        
        int mid =l+(r-l)/2;
        if(x==num2[mid])
            return mid;
        
        if(num2[mid]< x)
            return binarySearch(num2 , mid+1 , r ,x);
        else
            return binarySearch(num2 , l , mid-1 ,x);
    };
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> num;
        set<int> nu1(nums1.begin() , nums1.end());
        set<int> nu2(nums2.begin() , nums2.end());
        vector<int> num1(nu1.begin() , nu1.end());
        vector<int> num2(nu2.begin() , nu2.end());
        
        sort(num1.begin() , num1.end());
        sort(num2.begin() , num2.end());
        
        
        if(num1.size() >= num2.size())
        {
            for(int i=0 ;i<num2.size();i++)
            {
                int n = binarySearch(num1 , 0 , num1.size()-1 , num2[i] );
                num.push_back(num1[n]);
            }
             
        }
        else
        {
            for(int i=0 ;i<num1.size();i++)
            {
                int n = binarySearch(num2 , 0 , num2.size()-1 , num1[i] );
                num.push_back(num2[n]);
            }
        }
        set<int> s(num.begin(), num.end());
        vector<int>v(s.begin() , s.end());
        return v;
    }


int main()
{
   
       vector<int> nums1{1, 2, 2, 1};
       vector<int>nums2{2,2};
  cout <<  intersection( nums1,  nums2) ;

}