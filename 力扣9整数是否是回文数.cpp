/*
	�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
*/

#include <iostream> 
using namespace std;

#include <math.h>
//
//bool isPalindrome(int x)
//{
//	int length;
//	int num = x; 
//	// ���ж�����
//	if(x <= 0)
//	return false;
//	else
//	{
//		// ��ȡ x ��λ�� 
//		while(num)
//		{
//			num = num/10;
//			length++;
//		}
//		while(length>1)
//		{
//			if((x%10) == int(x/pow(10,length-1)))
//			{
//				if(x/pow(10,length-1) == 0)
//				return false; 
//				x = (x-x%10*pow(10,length-1)-x%10)/10;
//				num = x;
//				// ��ȡ x ��λ�� 
//				while(num)
//				{
//					num = num/10;
//					length++;
//				}
//			}
//			else
//			return false;
//		}
//	} 
//	return true;
//}
bool isPalindrome(int x)
{
	if(x < 0)
	return false;
	if(x == 0)
	return true;
	int num=0;
	num = x;
	int rnum=0;
	while(num)
	{
		rnum = rnum*10+num%10;
		num = num/10;	
	}
	return rnum == x;
}
int main()
{
	bool tag = isPalindrome(1000021);
	cout << tag;
	return 0;
}
