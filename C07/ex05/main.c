char	**ft_split(char *str, char *charset);
int	ft_is_sep(char c, char *charset);

#include<stdio.h>

int main(int argc, char *argv[])
{
	char	**ret;
	if (argc != 3) return (0);
	int i;

	ret = ft_split(argv[1], argv[2]);
	printf("%s %s\n", argv[1], argv[2]);
	printf("tab start\n");
	i = 0;
	while (ret[i] != 0)
	{
		printf("tab[%d]: %s\n", i, ret[i]);
		i++;
	}
	printf("tab end\n\n");
	return (0);
}
