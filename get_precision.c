#include "main.h"

/**
 * get_calc_precision - Calculates the precision for printing
 * @formatted_String: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_calc_precision(const char *formatted_String, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (formatted_String[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; formatted_String[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(formatted_String[curr_i]))
		{
			precision *= 10;
			precision += formatted_String[curr_i] - '0';
		}
		else if (formatted_String[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
