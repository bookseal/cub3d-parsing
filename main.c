#include "main.h"

int main(void)
{
	t_vars *var;
	char *cub_str = "./test.cub";
	var = parsing(cub_str);
	if (!var)
		exit(1);

	return (0);
}