int rangeBitwiseAnd(int left, int right)
{
	int result = right;
	while (right > left)
	{
		result = right & (right - 1);
		right = result;
	}
	return result;
}