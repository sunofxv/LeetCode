/*
	请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

    如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
    假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
    该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0 。

提示：

    本题中的空白字符只包括空格字符 ' ' 。
    假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [?231,  231 ? 1]。如果数值超过这个范围，请返回  INT_MAX (231 ? 1) 或 INT_MIN (?231) 。

*/
#include <math.h>
#include<iostream>
using namespace std;

int myFunction(string str)
{
	//查询到第一个非空字符
	int head = 0;
	int tag=0,mtag,headtag=0;
	int num;
	int count,numcount;
	char cnum[100];
	HEAD:if(str[head] == ' ' || str[head] == '0')
	{
		headtag = 1;
		if(str[head] == '0' &&head+1 < str.length() && (str[head+1] < 48 || str[head+1] > 57))
		{
            return 0;
        }
        
		else
		    head++;
            goto HEAD;
	}
	if(str[head]<48 && str[head] > 57 && str[head] != '+' && str[head] != '-')
	{
		return 0;
	}
	// 判断第一个非空字符是否为 + -
	if(str[head] == '+')
	{
		tag = 0;
		head++;
	}
	else if(str[head] == '-')
	{
		tag = 1;
		head++;
	}
	HEA:if(str[head] == ' ' || str[head] == '0')
	{
		head++;
		goto HEA;
	}
	count = 0;
	while(str[head] >= 48 && str[head] <= 57)
	{
		
		cnum[count] = str[head];
		count++;
		head++;
	} 
	num = 0;
	numcount = count;
    if(numcount > 10)
    {
        if(tag == 0)
        return INT_MAX;
        else if(tag == 1)
        return INT_MIN;
    }
    if(numcount==10 )
	{
			int mtag = (cnum[0]-'0')*100000+(cnum[1]-'0')*10000+(cnum[2]-'0')*1000+(cnum[3]-'0')*100+(cnum[4]-'0')*10+(cnum[5]-'0');
			if(mtag >= 214748) 
			{
				mtag = (cnum[6]-'0')*1000+(cnum[7]-'0')*100+(cnum[8]-'0')*10+(cnum[9]-'0');
				if(mtag>3647)
				{
					if(tag == 0)
	                return INT_MAX;
	                else if(tag == 1)
	                return INT_MIN;
				}
				
			}
		
	}
	for(int i=0;i<numcount;i++)
	{
		num = num+(cnum[count-1]-'0')*pow(10,i);
		count --;
	}
	if(tag == 0)
	{
		return num;
	}
	else if(tag == 1)
	{
		if((0-num) < INT_MIN)
		return INT_MIN;
		else if((0-num) > INT_MIN)
		{
			return (0-num);
		}
	}
    return 0;
}

int main()
{
	int num;
	num = myFunction("    ");
	cout << num;
	return 0;
}
 
