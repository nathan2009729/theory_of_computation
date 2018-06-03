#include <stdio.h>
#include <stdlib.h>
int main(){

    FILE *in = fopen("myhill-nerode-theorem.md","r");
    FILE *out = fopen("back.txt","w");
    
    int ch = 0;
    int counter = 0;
    if(!in){
        printf("read fail");
        exit(1);
    }
    if(!out){
        printf("create fail");
        exit(1);
    }
    while((ch = getc(in)) != EOF){
        /*if(ch == '$'){
            counter++;
            if(counter % 4 == 1 || counter % 4 == 0) ch = 39;
            fputc(ch,out);
        }*/
        if(counter > 100) break;
        else{
            putc(ch, out);
            if(ch>=65 && ch <=100){
                ch += 2;
                putc(ch, out);
            }
            counter++;
        }
    }
    /*for(ch = 33; ch <=100; ch++){
        putc(ch, out);
    }*/
    fclose(in); fclose(out);
    printf("ok\n");

}
