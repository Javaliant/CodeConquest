/* Author: Luigi Vincent
*
*/

#include <stdio.h>

int main() {
	int n = 1;
	puts(*(char *)&n == 1 ? "LittleEndian" : "BigEndian");
}