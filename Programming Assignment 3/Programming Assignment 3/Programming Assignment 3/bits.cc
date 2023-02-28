#include <stdio.h>

void print3dPoint(int point)
{
	int x = (point >> 20) & 0x3FF;
	int y = (point >> 10) & 0x3FF;
	int z = point & 0x3FF;
	printf("(%d, %d, %d)\n", x, y, z);
}

int swapBytes(int num)
{
	int firr = (num & 0x000000FF) << 8;
	int secc = (num & 0x0000FF00) >> 8;
	int thir = (num & 0x00FF0000) << 8;
	int four = (num & 0xFF000000) >> 8;
	int answer = (four | thir | secc | firr) | 0x0;
	return answer;
}


int countGroups(int num)
{
	int count = 0;
	int previous = 0;
	unsigned int mask = 0x80000000;

	for (int i = 0; i < 32; i++)
	{
		if (previous == 0 && (mask & num) != 0)
		{
			count++;
			previous = 1;
		}
		else if ((mask & num) == 0)
		{
			previous = 0;
		}
		mask = mask >> 1;
	}
	return count;
}

