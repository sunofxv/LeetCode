/******
����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ�� 1:

����: "abcabcbb"
���: 3 
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��


*********/
#include<iostream> 
using namespace std;

class Solution {
public:
	bool isEXIT(string s,char c)
	{
		for(int i=0;i < s.length();i++)
		{
			if(c == s[i])
			return true;   //���������ͬ�� ������ 
		}
		return false;
	}
	
    int lengthOfLongestSubstring(string s) {
		int count=1,max = 1;
        char str[128] = {s[0]};
        for(int i=0;i< s.length();i++)
        {
            for(int j=0;j<count;j++)
            {
                if(!isEXIT(str,s[i]))   //���ظ�   ���ظ� 
                {
                	
                    str[count] = s[i];
                    count++;    //�ۼ�
                    break;
                }
                else
                {
                	if(max < count)
                	max = count;
                	count = 1;
				}
				if(i == s.length()-1)
				{
					if(max < count)
					max = count;
				}
            }
        }
        return max;
    }
    
};

int  main()
{
	Solution *s = new Solution;
//	bool test = s->isEXIT("pwk",'w');
	int max = s->lengthOfLongestSubstring("pwwkew");
	
	cout << max <<"\n";
	
//	cout << test;
	
	return 0;
 } 
 
 
 /***
 
 error: conversion from 'Test*' to non-scalar type 'Test' requested
 �о���һ�£�Test test = new Test()�Ҳ��new��������������ָ����������������ڷǱ�����
���������� Solution s �ĳ� Solution *s ���� 
 ***/
