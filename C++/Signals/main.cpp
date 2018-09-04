#include <csignal>
#include <iostream>
#include <signal.h>

#define WINDOWS_SIGNAL_HANDLER
#ifdef LINUX_SIGNAL_HANDLER
// SIGINT handler
void int_handler(int x)
{
	std::cout << "In interrupt handler" << std::endl; // after pressing CTRL+C you'll see this message
}

int main()
{
	signal(SIGINT, SIG_DFL);
	std::cout << "Press ctrl+c now\n";
	std::cin.get();
	

	return 0;
}
#endif

#ifdef WINDOWS_SIGNAL_HANDLER
#include <iostream>

#include <stdlib.h>  
#include <signal.h>  
#include <tchar.h>  

void SignalHandler(int signal)
{
	if (signal == SIGABRT) {
		
		std::cout << "SIGABRT encountered. Abort protocol initiated" << std::endl;
		abort();
		exit(signal);
	}
	else {
		// ...  
	}
}

int main(void)
{
	typedef void(*SignalHandlerPointer)(int);

	SignalHandlerPointer previousHandler;
	previousHandler = signal(SIGABRT, SignalHandler);
}
#endif