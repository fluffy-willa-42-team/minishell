#include <stdio.h>

/**
 * @brief Test program to check the arg give by bash or zsh to a bin.
 */
int	main(int ac, char **av)
{
	if (ac == 0)
	{
		printf("WTF? argc == 0 ?!\n");
		return (1);
	}
	if (ac == 1)
	{
		printf("Will print the raw argv from the bash call\n    Exemple:\n        %s \"test\" 123\4 abc\\>d\\|e\n", av[0]);
		return (1);
	}
	for (int i = 1; i < ac; i++)
		printf("[%d]: ->[%s]<-\n", i, av[i]);
	return 0;
}
