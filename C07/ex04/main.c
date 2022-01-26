#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	int	test;

	test = 0;
	printf("%s\n", ft_convert_base("2147483647", "0123456789", "0123456789abcdef"));
	//[7fffffff]
	printf("%s\n", ft_convert_base("---------7fffffff", "0123456789abcdef", "01")); 	
	//[-1111111111111111111111111111111]
	printf("%s\n", ft_convert_base("---+--0001023a", "0123456789", "0123456789")); 	
	//[-1023]
	printf("%s\n", ft_convert_base("-0", "0123456789", "abcdefghij")); 	
	//[a]
	printf("%s\n", ft_convert_base(" \t\t\t ---+++ff-f", "0123456789abcdef", "0123456789")); 	
	//[-255]
	printf("%s\n", ft_convert_base("aasdffeessddfffss", "asedf", "ss")); 	//[null	printf("%s\n", ft_convert_base("  -+-+- -+asdf", "ai sdf", "fdsa")); 	//[null]
	printf("%s\n", ft_convert_base("\t\t\t\t \v --++-asdf", "asdf", "fd-as")); 	
	//[null]
	printf("%s\n", ft_convert_base("   -+a", "abcde", "")); 	
	//[null]
	printf("%s\n", ft_convert_base(" -+d", "", "df")); 	
	//[null]
	printf("test: %d\n", test);
	printf("(!test): %d\n", (!test));
}
