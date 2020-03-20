//
// Created by Administrator on 2020/3/18.
//
#include<stdio.h>

#ifdef WIN32
#include "getopt.h"
#else

#include <unistd.h>

#endif

#define APP_NAME    "getopt_demo"

/*
 * Brief: 显示帮助信息
 * Return: void
 * Param: void
 */
void display_usage()
{
    printf("Usage : %s [options]\n", APP_NAME);
    printf("\tThis ia a demo application of getopt\n");
    printf("options:\n");
    printf("\t-a\t\tshow all options\n");
    printf("\t-v\t\tshow app version\n");
    printf("\t-h\t\tshow this message and exit\n");
}

int main(int argc, char **argv) {
    int ch;

    opterr = 1;
    while ((ch = getopt(argc, argv, "ha:bv")) != -1) {
        switch (ch) {
            case 'a':
                printf("option a:'%s'\n", optarg);
                break;
            case 'b':
                printf("option b :b\n");
                break;
            case 'h':
                display_usage();
                break;
            default:
                printf("other option :%c\n", ch);
        }
    }

    printf("optopt +%c\n", optopt);
    //system("pause");
    return 0;
}
