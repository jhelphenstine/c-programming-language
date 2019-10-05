#include "tabs.h"

#define TAB 8

/* Utility function to count tabs in a string. Knowing this
        helps us set the right size for our detabbed char[] */
int count_tabs(char line[], int length)
{
        int tabs = 0;

        for (int i = 0; i < length; ++i){
                if(line[i] == '\t'){
                        ++tabs;
                }
        }
        return tabs;
}

/* Rewriting detab to return the length of the new line instead of void.
        All of the putchars now become storing operations */
int detab(char from[], char to[], int length)
{
        int tabwidth = 0;   /* width of any given tab in non_tabs spaces */
    int non_tabs = 0;   /* current number of non_tabs chars within tabstop */
        int k = 0;      /* new iterator for 2nd string */

    for (int i = 0; i < length; ++i){
        if (from[i] != '\t'){ 
            to[k] = from[i];
            ++non_tabs;         /* track non_tabs characters within a tabstop */
            if(non_tabs == TAB){
                non_tabs = 0;   /* non_tabs shouldn't exceed a tabstop */
            }
                        ++k;
        }
        else if (from[i] == '\t') {     /* we have a tab */
            tabwidth = TAB - non_tabs;  /* calculate actual tab width */
            for (int j = 0; j < tabwidth; ++j){
                to[k+j] = ' ';   /* pad with spaces to the tabstop */
                        }
                        k += tabwidth;  /* advance the new iterator */
            non_tabs = 0;   /* we have advanced to the next tabstop */
        }
    }
    //printf("\n");   /* newline -- not needed in this implementation */ 
        return k;               /* return the length */
}

