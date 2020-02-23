/****
思路：
将nums1 和 nums2 拼接，然后排序。找出中间值。


****/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 冒泡排序
    void sort_vector(vector<int> &num)
    {
        int i=0,j=1,num1;
        for(i=0;i<num.size();i++)
        {
            bool flag = false;   //  表示本趟冒泡排序是否发生交换的标志
            for(j=1;j<num.size()-i;j++)
            {
                if(num[j]<num[j-1])
                {   // 交换
                    num1 = num[j-1];
                    num[j-1] = num[j];
                    num[j] = num1;
                    flag = true;
                }
            }
            if(flag == false)   //未交换，说明已经有序，停止排序
            return;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len;
		double num = 0;
        for(int i=0;i<nums2.size();i++)  // 拼接
        {
        	nums1.push_back(nums2[i]);
		}
		
		sort_vector(nums1);     // 排序
		
        cout  << "nums1 中元素：\n" ;
		for(int i=0;i<nums1.size();i++)
		{
			cout << nums1[i] <<"  ";
		}
        
        cout << "nums1 中个数：" << nums1.size()<<"\n";
        
        
        if(nums1.size()%2 == 0)    //  偶数个
        {
        	num = (nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2.0;
            return num;
        }
        else 
        {
        	num = nums1[(nums1.size()-1)/2];
        	return num;
		}
        
    }
    
    void print_vector(vector<int> a)
	{
		cout  << "a 中元素：\n" ;
		for(int i=0;i<a.size();i++)
		{
			cout << a[i] <<"  ";
		}
		cout << "\n";
	}
};

int main()
{
	Solution *s = new Solution;
	vector<int> nums1,nums2;
	nums1.push_back(1);
	nums1.push_back(3);
	nums2.push_back(2);
//	nums2.push_back(4);
//	nums2.push_back(5);
	
	s->print_vector(nums1);
	s->print_vector(nums2);
	
	
	cout << "中位数："<<s->findMedianSortedArrays(nums1,nums2);
	
	return 0;
	
}
