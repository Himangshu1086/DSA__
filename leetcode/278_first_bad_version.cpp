// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

	class Solution {
	public:
	    int binarySearch(int l , int r , long long n )
	{
	    if (r >= l) {

        int mid = l + (r - l) / 2;
        
        if (!isBadVersion(mid))
            return binarySearch(mid + 1 , r , n);
        else
        {
            if(!isBadVersion(mid-1))
                return mid;
            else
                return binarySearch( l , mid - 1 , n );
                
        }
    }


    return -1;
	}
	    int firstBadVersion(int n) {
	        return binarySearch(1 , n , n);
	    }
	};