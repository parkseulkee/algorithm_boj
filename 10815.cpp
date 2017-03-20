#include<stdio.h>
#include<cstdio>
#include<algorithm>
//#pragma warning(disable:4996)

#define N 500000
using namespace std;
int arr1[N];
int arr2[N];
int main()
{
	int sg = 0;
	int cg = 0;
	scanf("%d", &sg);
	for (int i = 0; i < sg; i++)
		scanf("%d", &arr1[i]);
	scanf("%d", &cg);
	for (int i = 0; i < cg; i++)
		scanf("%d", &arr2[i]);

	sort(arr1, arr1 + sg);

	for (int i = 0; i < cg; i++) {
		int start = 0, end = sg;
		while (1)
		{
			if (start > end) {
				printf("0 ");
				break;
			}
			if (arr1[(int)(start + end) / 2] > arr2[i])
				end = (int)(start + end) / 2 - 1;
			else if (arr1[(int)(start + end) / 2] < arr2[i])
				start = (int)(start + end) / 2 + 1;
			else if (arr1[(int)(start + end) / 2] == arr2[i])
			{
				printf("1 ");
				break;
			}
			else
			{
				printf("0 ");
				break;
			}
		}
	}
	return 0;
}