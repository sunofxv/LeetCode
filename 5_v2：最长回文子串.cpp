/*****
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000

*****/ 

#include <vector>
#include <iostream>
using namespace std;

/***
�ȴ�ͷ����s���ӵ�һ���ַ���ʼ�����Ƿ�����ͬ�ַ�����¼�鵽��һ����ͬ�ַ�֮��ĳ��ȡ�������󳤶ȵ��ַ���

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
	//  ͷβ˫����� 
    string longestPalindrome(string s) {
        string max_str,st_str;
        int maxlen = 0;    //  ��¼��󳤶�
        char str;      //  �洢��ǰ�ַ�
        max_str = max_str + s[0];
        for(int i=0;i<s.length();i++)
		{
		    for(int j=s.length()-1;j>i;j--)
			{
				st_str = max_str;
				if(s[i] == s[j])
				{
					max_str.append(s,i,j-i+1);	//׷�� 
				}	
				if(isPalindrome(max_str) == 1)  // �ǻ���
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
