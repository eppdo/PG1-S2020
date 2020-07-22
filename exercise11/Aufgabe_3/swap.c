void swap(void* a, void* b, int t_size)
{
	for (int i = 0; i < t_size; ++i)
	{
		*((char*)a + i) ^= *((char*)b + i);
		*((char*)b + i) ^= *((char*)a + i);
		*((char*)a + i) ^= *((char*)b + i);
	}
}