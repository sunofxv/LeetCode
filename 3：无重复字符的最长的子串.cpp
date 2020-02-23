/******
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。


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
			return true;   //如果存在相同的 返回真 
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
                if(!isEXIT(str,s[i]))   //判重复   不重复 
                {
                	
                    str[count] = s[i];
                    count++;    //累加
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
 研究了一下，Test test = new Test()右侧的new操作符创建的是指针变量，左侧的类属于非标量。
问题解决：将 Solution s 改成 Solution *s 即可 
 ***/
