#include<bits/stdc++.h>
using namespace std;
float median(int nums1[],int nums2[],int m,int n)
{
     if(m>n)
     return median(nums1,nums2,n,m);
    int low=0,high=m,medianpos=((m+n)+1)/2;
    while(low<=high)
    {
         int cut1=(low+high)/2;
         int cut2=medianpos-cut1;
         int L1 = (cut1==0)?INT_MIN:nums1[cut1-1];
         int L2 = (cut2==0)?INT_MIN:nums2[cut2-1];
         int r1 = (cut1==m)?INT_MAX:nums1[cut1];
         int r2 = (cut2==n)?INT_MAX:nums1[cut2];
         if(L1<=r2&&L2<=r1)
         {
              if((m+n)%2!=0)
               return max(L1,L2);
              else
               return (max(L1,L2)+min(r1,r2))/2.0;
         }
         else
          if(L1<r1)
          high=cut1-1;
         else  low=cut1+1;
    }
    return 0.0;
}
int main()
{
     int num1[]={1,4,7,10,12};
     int num2[]={2,3,6,15};
     int m=sizeof(num1)/sizeof(num1[0]);
     int n=sizeof(num2)/sizeof(num2[0]);
     cout<<"The Median of two shorted arry is "<<median(num1,num2,m,n);
     return 0;
}
