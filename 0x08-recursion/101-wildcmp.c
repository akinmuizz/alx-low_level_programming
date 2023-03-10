#include "main.h"

int strlen_no_wilds(char *str);
void iterate_wild(char **wildstr);
char *postfix_match(char *str, char *postfix);
int wildcmp(char *s1, char *s2);

/**
 * strlen_no_wilds - Returns the length of a string
 * ignoring wildcard charcaters
 * @str: The string to be measured
 *
 * Return: the length
 */

int strlen_no_wilds(char *str)
{
	int len = 0, index = 0;

	if (*(str + index))
	{
		if (*str != '*')
			len++;

		index++;
		len += strlen_no_wilds(str + index);
	}

	return (len);
}

/**
 * iterate_wild - iiterates through a string located at a wildcard
 * until it points to a non wildcard character
 * @wildstr: the string to be iterated through
 */

void iterate_wild(char **wildstr)
{
	if (**wildstr == '*')
	{
		(*wildstr)++;
		iterate_wild(wildstr);
	}
}

/**
 * postfix_match - Checks if a string str matches the postfix of
 * another string potentially containing wildcards
 * @str: the string to be matched
 * @postfix: the postfix
 *
 * Return: if str and postfix are idntical- a pointer to null byte
 * located at end of postfix
 * otherwise - a pointer to the first unmatched character in postfix
 */

char *postfix_match(char *str, char *postfix)
{
	int str_len = strlen_no_wilds(str) - 1;
	int postfix_len = strlen_no_wilds(postfix) - 1;

	if (*postfix == '*')
		iterate_wild(&postfix);

	if (*(str + str_len - postfix_len) == *postfix && *postfix != '\0')
	{
		postfix++;
		return (postfix_match(str, postfix));
	}

	return (postfix);
}

/**
 * wildcmp - compares two strings, considering wildcard characters
 * @s1: the first string to be compared
 * @s2: the scond string to be compared - may contain wildcards
 *
 * Return: if the strings can be considered identical - 1
 * otherwise - 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		iterate_wild(&s2);
		s2 = postfix_match(s1, s2);
	}

	if (*s2 == '\0')
		return (1);

	if (*s1 != *s2)

		return (0);

	return (wildcmp(++s1, ++s2));
}
