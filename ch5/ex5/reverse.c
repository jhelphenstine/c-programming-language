/* reverse: reverse a string
    @params:    int length      -- strlen() results
                char *target    -- string to reverse
                int start       -- position to start from (usually 0)
*/
void reverse(int length, char target[], int x){
    if(x < (length/2)){
        /* We aren't past the halfway mark yet */
        char swap;
        swap = target[x];
        target[x] = target[length-(x+1)];
        target[length-(x+1)] = swap;
        (x)++;
        reverse(length, target, x);
    }
    else{
        return;
    }
}