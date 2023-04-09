/**
 * flip_bits - returns the number of bits needed
 * @n: first number
 * @m: second number
 *
 * Return: number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int count = 0;
unsigned long int diff = n ^ m;

while (diff)
{
count += diff & 1;
diff >>= 1;
}
return (count);
}
