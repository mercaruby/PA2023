#include "Color.h"


float limit(int x)
{
	if (x > 1)
	{
		x = 1;
		
	}
	if (x < 0)
	{
		x = 0;
	}	


	return x;
}