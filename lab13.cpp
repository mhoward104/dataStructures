//Matthew Howard
//cs 2315
//lab 13



int countOneBits(int t)
{
	


	if(t)
	{

		t &= (t - 1);
		return 1 + countOneBits(t);
		
	}

	return 0;	

}
