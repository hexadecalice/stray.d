#include <iostream> 

/*
 * So here's the deal with console graphics/scaling:
 * Apple/Linux uses <sys/ioctl>
 * Windows uses <windows.h>
 *
 * Two different header files, but we can use #ifdef logic
 * to get the terminal variables we need on each platform.
 * Fortunately, we only need three settings:
 * >> Height
 * >> Width
 * >> ANSI-Support
 *
 * ...but we're also neglecting terminal events such as resizing,
 * meaning we need to do a lot of pre-processing or completely split
 * some elements of the current cli class.
*/

int main(void) { 
return 0;
}
