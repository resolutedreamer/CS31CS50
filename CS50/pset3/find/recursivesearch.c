bool search(int value, int values[], int n)
{
    // this is a recursive searching algorithm written with a good amount of help from kasey
	bool valueisfound = false;
	int center = n/2;
	
	if (n == 0)
		return false;
	
	if(value == value[center])
		valueisfound = true;
		
	else
	{
		if(value < value[center])
		{
			valueisfound = search(value, values, center);
		}

		valueisfound = search(value, (values + center + 1), (n - (center + 1));
	}
	
	return valueisfound;
}
