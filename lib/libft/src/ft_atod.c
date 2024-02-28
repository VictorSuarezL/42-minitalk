#include <libft.h>

double ft_atod(char *str)
{
	long int_part;
	double dec_part;
	int	i;
	int	is_negative;
	double pow;

	i = 0;
	int_part = 0;
	is_negative = 1;
	dec_part = 0;
	pow = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		int_part = int_part * 10 + str[i] - '0';
		++i;
	}
	if (str[i] == '.')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		pow /= 10;
		dec_part = dec_part + (str[i] - '0') * pow;
		++i;
	}	
	return(is_negative *(int_part + dec_part));
}