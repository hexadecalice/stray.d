#include <iostream> 

// This is where the prescribed #if-dev pre-processing will come in handy.
// Fortunately, I'm only developing a Linux prototype first.
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

// I'm afraid to go further with this because it might be time to mockup 
// our TUI and to specify the data structures and algorithms for these strings.
//
// Using the char* datatype would be abysmal since we're also implementing 
// ANSI Color Codes. Not that we need a million "\033[0m"'...  Oo-Rah.

int main(void) { 
    int fd = open("/dev/tty", O_WRONLY);
    winsize size;

    ioctl(fd, TIOCGWINSZ, &size);

    printf("\033[31m"); //Turn the foreground red.
    std::cout << "Columns: " << size.ws_col << ", Rows: " << size.ws_row << std::endl;
    printf("\033[0m"); //Default terminal settings.

    close(fd);

    return 0;
}
