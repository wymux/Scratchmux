#include <stdio.h>

#include "ping.h"
#include "utils.h"

void
print_help()
{
	printf("Usage: ping [-vh] <hostname>\nOptions:\n\t-v: verbose mode\n\t-h: print this help message\n");
}

opt_t
parse_opt(int ac, char **av)
{
	opt_t opt = {0, 0, 0, NULL};
	int i = 1;
	while (i < ac) {
		if (ft_strcmp(av[i], "-v") == 0) {
			opt.verbose = 1;
		}
		else if (ft_strcmp(av[i], "-h") == 0) {
			opt.help = 1;
			return opt;
		}
		else if (av[i][0] != '-') {
			opt.hostname = av[i];
		}
		else {
			opt.err = 1;
			fprintf(stderr, "Invalid option: %s\n", av[i]);
			return opt;
		}
		i++;
	}
	return opt;
}
