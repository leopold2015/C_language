#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#define PATH "./libsum.so" //选择加载库的路径
typedef int (*fun)(int,int);
int main()
{
	void *handel;
	char *error;
	fun Sum = NULL;
	handel = dlopen(PATH,RTLD_LAZY| RTLD_GLOBAL);
	if(handel == NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(-1);
	}
	dlerror();
	Sum = dlsym(handel,"sum");
	printf("SUM = %d\n",Sum(7,5));
	dlclose(handel);
	return 0;
}

