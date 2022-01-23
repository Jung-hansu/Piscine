#include <stdlib.h>
#include <stdio.h>
char	*ft_strjoin(int size, char **strs, char *sep);

int		main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc(4 * sizeof(strs));
	strs[0] = "lol";
	strs[1] = "1234";
	strs[2] = "poiuic";
	strs[3] = "1234";
	strs[4] = "asdf";
	separator = " && ";
	index = 0;
/*	printf("=====REAL ANSWER=====\n");
	printf("result with size = 0 : $$\n");
	printf("result with size = 1 : $lol$\n");
	printf("result with size = 2 : $lol1234$\n");
	printf("result with size = 3 : $lol1234poiuic$\n");
*/
	printf("=====YOUR ANSWER=====\n");
	while (index < 6)
	{
		result = ft_strjoin(index, strs, separator);
		printf("result with size = %d : $%s$\n", index, result);
		free(result);
		index++;
	}
}
