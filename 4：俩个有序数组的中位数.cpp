/****
˼·��
��nums1 �� nums2 ƴ�ӣ�Ȼ�������ҳ��м�ֵ��


****/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // ð������
    void sort_vector(vector<int> &num)
    {
        int i=0,j=1,num1;
        for(i=0;i<num.size();i++)
        {
            bool flag = false;   //  ��ʾ����ð�������Ƿ��������ı�־
            for(j=1;j<num.size()-i;j++)
            {
                if(num[j]<num[j-1])
                {   // ����
                    num1 = num[j-1];
                    num[j-1] = num[j];
                    num[j] = num1;
                    flag = true;
                }
            }
            if(flag == false)   //δ������˵���Ѿ�����ֹͣ����
            return;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len;
		double num = 0;
        for(int i=0;i<nums2.size();i++)  // ƴ��
        {
        	nums1.push_back(nums2[i]);
		}
		
		sort_vector(nums1);     // ����
		
        cout  << "nums1 ��Ԫ�أ�\n" ;
		for(int i=0;i<nums1.size();i++)
		{
			cout << nums1[i] <<"  ";
		}
        
        cout << "nums1 �и�����" << nums1.size()<<"\n";
        
        
        if(nums1.size()%2 == 0)    //  ż����
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
		cout  << "a ��Ԫ�أ�\n" ;
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
	
	
	cout << "��λ����"<<s->findMedianSortedArrays(nums1,nums2);
	
	return 0;
	
}
