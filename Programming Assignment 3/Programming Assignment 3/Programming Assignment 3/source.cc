int countGroups(long num)
{
	int count = 0;
	int flag = 0;

	// using while loop
	while (num)
	{
		// checking last binary digit of number if it is 1 or not
		if (num & 1 == 1)
			flag++;
		// now if current last digit is 0 check if it had (1s or 1) just before
		else
		{
			if (flag != 0)
				count++;
			flag = 0;
		}
		// shifting number towards right by 1 binary bit
		num >>= 1;
	}
	// in the case of 1s in last position
	if (flag != 0)
		count++;
	// return result
	return count;
}

int main(void)
{
	// test cases in the provided main function
	int answer1 = countGroups(207);
	int answer2 = countGroups(0x1ACE);
	int answer3 = countGroups(0x8000000F);

	printf("%d\n", answer1);
	printf("%d\n", answer2);
	printf("%d\n", answer3);

	return 0;
}