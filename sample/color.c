#include "../minishell.h"

int main(void)
{
	fprintf(stderr, CYAN"my name is hiroki!\n"STOP);
	fprintf(stderr, UNDERLINE"my name is ohnuki!\n"STOP);
	fprintf(stderr, MAGENTA"THIS IS A PEN.\n"STOP);
	return 0;
}
