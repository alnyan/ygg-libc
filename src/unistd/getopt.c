#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Location of current symbol
static size_t optloc = 1;
int optind = 1;
int optopt;
int opterr = 1;
char *optarg;

int getopt(int argc, char *const argv[], const char *optstr) {
    (void) argc;
    optarg = NULL;
    optopt = -1;

    while (1) {
        if (optloc == 1 && (!argv[optind] || *argv[optind] != '-' || !strcmp(argv[optind], "-"))) {
            return -1;
        }
        if (optloc == 1 && (!strcmp(argv[optind], "--"))) {
            ++optind;
            return -1;
        }

        const char *arg = argv[optind];
        const char *p;
        optopt = arg[optloc];

        if (!arg[optloc]) {
            // Skip -
            optloc = 1;
            ++optind;
            continue;
        }

        ++optloc;
        p = strchr(optstr, optopt);

        if (!p) {
            if (opterr) {
                fprintf(stderr, "%s: unknown option: '-%c'\n", argv[0], optopt);
            }
            return '?';
        }

        if (p[1] == ':') {
            if (arg[optloc]) {
                // Rest of the string is considered argument
                ++optind;
                optarg = (char *) &arg[optloc];
            } else {
                // Next argv[] is considered argument
                if (optind == argc - 1) {
                    if (opterr) {
                        fprintf(stderr, "%s: option requires an argument: '-%c'\n", argv[0], optopt);
                    }
                    return -1;
                }

                optarg = argv[++optind];
                ++optind;
            }
            optloc = 1;
        }

        return optopt;
    }
}
