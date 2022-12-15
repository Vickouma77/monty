#include "monty.h"

/**
 * get_int - get char pointer to new str with int
 * @num: number to convert to string
 * Return: char pointer converted as null if fails and malloc.
 */
char *get_int(int num)
{
	long num_v = 0;
	unsigned int tmp;
	int len = 0;
	char *ret;

	tmp = abs_m(num);
	len = len_buff_uint(tmp, 10);

	if (num < 0 || num_v < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	full_buff(tmp, 10, ret, len);
	if (num < 0 || num_v < 0)
		ret[0] = '-';

	return (ret);
}
/**
 * abs_m - abs value of int
 * @i: integer to get absolute value of
 * Return: unsigned int of i
 */
unsigned int abs_m(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}
/**
 * len_buff_uint - length of buff for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 * Return: int of len of buff
 */
int len_buff_uint(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * full_buff - complete buff with numbers
 * @num: number to convert to str
 * @base: b number
 * @buff: buffer to be completed
 * @buff_size: size of buffer
 * Return: void.
 */
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * _isdigit - Entry point
 *
 * Return: if is digit  or not, return 1 else 0
 */
int _isdigit(void)
{
	int i = 0;

	if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
		i++;
	while (globalvar.token2[i])
	{

		if (isdigit(globalvar.token2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
