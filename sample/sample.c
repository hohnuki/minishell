#include "ease.h"

char *cmd[] = {"/bin/ls", "-l", "-a", NULL};//OK

int main(int argc, char **argv)
{
	execve(cmd[0], cmd, NULL);
	return 0;
}
