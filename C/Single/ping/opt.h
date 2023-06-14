typedef struct s_opt
{
	int verbose;
	int help;
	int err;
	char *hostname;
} opt_t;

void print_help();
opt_t parse_opt(int ac, char **av);
int handle_opt(opt_t opt);
