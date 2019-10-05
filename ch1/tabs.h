#ifndef TABS_H_INCLUDED
#define TABS_H_INCLUDED

#define TAB 8

int count_tabs(char line[], int length);
int detab(char from[], char to[], int length);

#endif
