int len (int ptr);
void *max(void *p1, size_t datasize, size_t size, int (*compar)(const void *, const void*));
void swap(void *p1, void *p2, size_t size);
void QuickSort(void *origArr, size_t datasize, size_t size, int (*compar)(const void *, const void *));
void ShellSort(void *origArr, size_t datasize, size_t size, int (*compar)(const void *,const void*));
void RadixSort(void *origArr, size_t datasize, size_t size, int (*compar)(const void *,const void*));



