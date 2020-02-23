/*****
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000

*****/ 

#include <vector>
#include <iostream>
using namespace std;

/***
先从头遍历s，从第一个字符开始查找是否有相同字符，记录查到第一个相同字符之间的长度。返回最大长度的字符串

***/

class Solution {
public:
	
	bool isPalindrome(string s)
    {
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i] != s[s.length()-i-1])
            return false;
        }
        return true;
    }
	//  头尾双向遍历 
    string longestPalindrome(string s) {
        string max_str,st_str;
        int maxlen = 0;    //  记录最大长度
        char str;      //  存储当前字符
        max_str = max_str + s[0];
        for(int i=0;i<s.length();i++)
		{
		    for(int j=s.length()-1;j>i;j--)
			{
				st_str = max_str;
				if(s[i] == s[j])
				{
					max_str.append(s,i,j-i+1);	//追加 
				}	
				if(isPalindrome(max_str) == 1)  // 是回文
				{
					maxlen = j-i+1;	
				} 
				else
				{
					max_str = st_str;
					st_str.clear();
				}
			}	
		} 
    }
}; 

int main()
{
	Solution *s = new Solution;
	string max_s;
	bool p = true;    //  1:true  0:false
	string str = "abcba";
	max_s = s->longestPalindrome(str);
	for(int i=0;i<max_s.length();i++)
	{
		cout << max_s[i] << "  ";
	}

	return 0; 
}
