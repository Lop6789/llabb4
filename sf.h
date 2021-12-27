void swap(void *x, void *y, size_t l);
static void sort(char *array, size_t size, int (*cmp)(void*,void*), int begin, int end);
void qsort(void *array, size_t nitems, size_t size, int (*cmp)(void*,void*));
