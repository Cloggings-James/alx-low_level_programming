/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: a pointer to the unsigned long int whose bit is to be set
 * @index: the index of the bit to set, starting from 0
 *
 * Return: 1 if successful, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)  /* check if index is valid */
return (-1);

*n |= (1UL << index);  /* set the bit at the given index to 1 */

return (1);
}

