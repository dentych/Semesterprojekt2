
void initSwitchPort(unsigned char hvilkenPort); /*
hvilkenPort: 0=A, 1=B ...
*/
unsigned char switchStatus(unsigned char hvilkenPort); /*
hvilkenPort: 0=A, 1=B ...
tjekker om knappen er trykket ned
*/
unsigned char switchOn(unsigned char hvilkenPort, unsigned char switch_nr);/*
hvilkenPort: 0=A, 1=B ...
*/