#include<stdio.h>

// function to print a rectangle of pluses and dashes of given width and height
void printRectangle(int width, int height)
{
	int i, j;
	if (width > 0 && height > 0)
	{
		for (i = 1; i <= height; i++)
		{
			for (j = 1; j <= width; j++)
			{
				if (i == 1 || i == height)
				{
					printf("+");
				}
				else
				{
					if (j == 1 || j == width)
						printf("+");
					else
						printf("-");
				}
			}
			printf("\n");
		}
	}
}

void printTriangle(int base)
{
	int i, j;
	i = 1;
	while (i <= base)
	{
		j = 1;
		while (j <= base - i)
		{
			printf(" ");
			j++;
		}
		if (i == 1 || i == base)
		{
			j = 1;
			while (j <= i)
			{
				printf("+");
				j++;
			}
			printf("\n");
		}
		else
		{
			j = 1;
			while (j <= i)
			{
				if (j == 1 || j == i) {
					printf("+");
				}
				else {
					printf("-");
				}
				j++;
			}
			printf("\n");
		}
		i++;
	}
}

void printFormat(int maxVal, int col, int multi) {
	if(multi >1)
	if (maxVal % multi == 0)
	{
		maxVal--;
	}
	if (maxVal == 1)
	{
		printf("1");
		printf("\n");
	}
	else if (maxVal > 0 && multi <= maxVal)
	{
		if (col < 1)
		{
			if (multi < 2)
			{
				for (int i = 1; i <= maxVal; i++)
				{
					//if (i % multi != 0)
					//{
					if (i == maxVal)
					{
						printf("%d", i);
					}
					else
					{
						printf("%dX\t", i);
					}
					//}
				}
			}
			else
			{
				for (int i = 1; i <= maxVal; i++)
				{
					if (i % multi != 0)
					{
					if (i == maxVal)
					{
						printf("%d", i);
					}
					else
					{
						printf("%dX\t", i);
					}
					}
				}
			}
			printf("\n");
		}
		else if (col == 1)
		{
			//maxVal++;
			for (int i = 1; i <= maxVal; i++)
			{
				if (i % multi != 0)
				{
					printf("%d", i);
					printf("\n");
				}
				if (col == multi)
				{
					printf("%d", i);
					printf("\n");
				}
			}
		}
		else if (multi < 2)
		{
			int counter = 0;
			for (int i = 1; i <= maxVal; i++)
			{
				if (counter % col == col - 1)
				{
					if (i == maxVal)
					{
						printf("%d", i);
						printf("\n");
						counter = 0;
					}
					else
					{
						printf("%d", i);
						counter++;
					}

					if (counter == col)
					{
						printf("\n");
						counter = 0;
					}
				}
				else
				{
					if (i == maxVal)
					{
						printf("%d", i);
						printf("\n");
						counter = 0;
					}
					else
					{
						printf("%dX\t", i);
						counter++;
					}

					if (counter == col)
					{
						printf("\n");
						counter = 0;
					}
				}

			}
		}
		else
		{
			int counter = 0;
			for (int i = 1; i <= maxVal; i++)
			{
				if (i % multi != 0)
				{
					if (counter % col == col - 1)
					{
						if (i == maxVal)
						{
							printf("%d", i);
							printf("\n");
							counter = 0;
						}
						else
						{
							printf("%d", i);
							counter++;
						}

						if (counter == col)
						{
							printf("\n");
							counter = 0;
						}
					}
					else
					{
						if (i == maxVal)
						{
							printf("%d", i);
							printf("\n");
							counter = 0;
						}
						else
						{
							printf("%dX\t", i);
							counter++;
						}

						if (counter == col)
						{
							printf("\n");
							counter = 0;
						}
					}
				}
			}
		}
	}
}


