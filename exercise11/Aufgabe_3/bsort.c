void swap(void* a, void* b, int t_size);

void bsort(void* a, int t_size, int a_size, int (*compare) (const void*, const void*))
{
	for (int i = 0; i < (a_size - 1); ++i)
	{
		for (int j = 0; j < (a_size - i - 1); j++)
		{
			void* x = ((char*)a + (j * t_size));
			void* y = ((char*)a + ((j + 1) * t_size));

			if ((*compare) (x, y) > 0)
			{
				swap(x, y, t_size);
			}
		}
	}
}