#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//LeetCode 27. �Ƴ�Ԫ��
//����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣
//Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//Ҫ��ʱ�临�Ӷ�ΪO(N),�ռ临�Ӷ�ΪO(1)

//�ⷨ
//���Կռ��ʱ�����κ�Ҫ�󣬿����ٴ���һ������num2������һ��ԭ����,�ѳ�ȥvalԪ�ص�����Ԫ�ط�������num2,����num2��ԭ���鸲��
//���߰�ÿ��valԪ�غ����Ԫ����ǰ�ƶ�һλ�����ɰ�����valԪ�ظ���
//������Ŀʱ��Ϳռ临�Ӷȵ�Ҫ�󣬡�ԭ���Ƴ�������������ָ��pr,ps��pr�������飬ps�޸�����Ԫ��
// �磺
 //      3 2 6 3 5 3 8            ��Ҫ�Ƴ�3
//һ��ʼprָ��3��ִ�п���䣬��һ��ָ��2��ִ��else��䣨��ps�ڵ�һ����3����λ�÷���2��,������������
int removeElement1(int* nums, int numSize, int val)
{
	int start = 0;
	int i = 0;
	for (i = 0; i < numSize; i++)
	{
		if (nums[i] == val)
		{
			start = i;//��ʼɾ��������Ķ���ǰ�ƶ�һλ
			while (start < numSize - 1)
			{
				nums[start] = nums[start + 1];
				start++;
			}

			i--;//��һ���ټ�һ���ٴαȽϱ�ɾ��Ԫ�ص��±���������Ӧ��Ԫ��
			numSize--;//ɾ��һ����Ԫ�ظ�����һ
		}
	}
	return start;

}
int removeElement(int* nums,int numSize,int val)
{
	int* pr = nums;
	int* ps = nums;
	int i = 0;
	int j = 0;
	for (i = 0; i < numSize; i++)
	{
		if (*(pr + i) == val)
		{
			;//����䣬����Ҫ���κ��¹ʡ�
		}
		else
		{
			*(ps + j) = *(pr + i);
			j++;
		}
	}
	return j;
}
int main(void)
{
	int nums[8] = { 0,1,2,2,3,0,4,2 };
	int val = 2;
	int len= removeElement1(nums,8, val);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}



//26. ɾ�����������е��ظ���
//����һ���������� nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

//˼·�������溯���ⷨ����������� �ж�ָ��ps�Ƿ�����ƶ� ����Ԫ�ؿ�������������
//ֻ��Ҫ���±�1��ʼ���ж��Ƿ���ǰһ��Ԫ����ͬ������ָͬ��ps����������ͬ�򿽱�����Ԫ��
int removeDuplicates(int* nums, int numsSize) 
{
	int* pr = nums;
	int* ps = nums;
	int i = 0;
	int j = 1;
	for (i = 1; i < numsSize; i++)
	{
		
		if (*(pr+i) == *(pr-1+i))
		{
			;//����䣬����Ҫ���κ��¹ʡ�
		}
		else
		{
			*(ps + j) = *(pr + i);
			j++;
		}
	}
	return j;
}

//int main(void)
//{
//	int nums[14] = { 0,0,0,1,1,1,2,2,3,3,4,5,6,6 };
//	int len = removeDuplicates(nums, 14);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	return 0;
//}
