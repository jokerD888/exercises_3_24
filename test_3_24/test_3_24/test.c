#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//LeetCode 27. 移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//要求时间复杂度为O(N),空间复杂度为O(1)

//解法
//若对空间和时间无任何要求，可以再创建一个数组num2，遍历一遍原数组,把除去val元素的所有元素放入数组num2,再用num2把原数组覆盖
//或者把每个val元素后面的元素先前移动一位，即可把所有val元素覆盖
//根据题目时间和空间复杂度的要求，“原地移出”，可用两个指针pr,ps，pr遍历数组，ps修改数组元素
// 如：
 //      3 2 6 3 5 3 8            中要移除3
//一开始pr指向3，执行空语句，下一次指向2，执行else语句（用ps在第一个‘3’的位置放入2）,依次往下类推
int removeElement1(int* nums, int numSize, int val)
{
	int start = 0;
	int i = 0;
	for (i = 0; i < numSize; i++)
	{
		if (nums[i] == val)
		{
			start = i;//开始删除，后面的都往前移动一位
			while (start < numSize - 1)
			{
				nums[start] = nums[start + 1];
				start++;
			}

			i--;//减一后再加一，再次比较被删除元素的下标现在所对应的元素
			numSize--;//删除一个，元素个数减一
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
			;//空语句，不需要做任何事故。
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



//26. 删除有序数组中的重复项
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

//思路：与上面函数解法大差不差，区别在于 判断指针ps是否向后移动 进行元素拷贝的条件不用
//只需要从下标1开始，判断是否与前一个元素相同，若相同指针ps不动，若不同则拷贝后面元素
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
			;//空语句，不需要做任何事故。
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
