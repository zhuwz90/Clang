//
// Created by Administrator on 2020/3/18.
//

#ifndef C_GETOPT_H
#define C_GETOPT_H

extern   char *optarg;
extern   int opterr;
extern   int optind;
extern   int optopt;

int getopt(int argc, char * const argv[], const char *optstring);

#endif //C_GETOPT_H
