#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){

    /*  Concept of Binary files */
    /*  "r":"rt" "w":"wt" by default t: textFile 
        For binaryFile we use :-- "rb" "wd" 
        textFileSystem doesn't work on ML files like .exe,.obj,.com
        while binaryFile system can handle it in different manner
        textFiles can also be stored and processed as binaryFile but not vice-versa
        main diff: 1. The storage of new line \n for t is 2bytes while 1 for b  2. the eof character  */

    FILE *fp;
    char ch;
    int cnt=0;
    fp= fopen("sample.dat","rb");
    if(fp==NULL){
        printf("Error-Can't open the designated File\n");
    }else{
        ch = getc(fp);
        do{
            cnt++;
            ch=getc(fp);
        }while(!feof(fp));
    }
    fclose(fp);
    printf("Number of Character = %d\n",cnt);



    /* Store 10001 t0 11000 in a binaryFile using fwrite */
    FILE *ffw;
    ffw= fopen("binval.dat","wb");
    if(ffw==NULL){
        printf("Error-Can't open the designated File\n");
    }else{
        for(int i=10001;i<=11000;i++)
            fwrite(&i,sizeof(int),1,ffw);
    }
    fclose(ffw);
    

    /*   Accessing the file randomly   */

    /* in this we are using fseek(File *fstream,long offset,int reference_posn)*/
    // fstream : file pointer
    // offset : bytes fro the location whence
    //reference_posn: SEEK_SET(wrt begin of file), SEEK_CUR(wrt curr location of file pointer), SEEK_END(wrt end of file)

    FILE *fstream;
    fstream=fopen("alphabet.dat","w");
    for(int k=65;k<=90;++k){
        fprintf(fstream,"%c",k);
    }
    fclose(fstream);

    FILE *fstream1;
    fstream1=fopen("alphabet.dat","r");
    fseek(fstream1,0,SEEK_SET);
    fscanf(fstream1,"%c",&ch);
    printf("\n First char : %c\n",ch);
    fseek(fstream1,13,SEEK_SET);
    fscanf(fstream1,"%c",&ch);
    printf("\n 14th char : %c\n",ch);
    fseek(fstream1,-1,SEEK_END);
    fscanf(fstream1,"%c",&ch);
    printf("\n LAST char : %c\n",ch);
    fclose(fstream1);

    //to access alternate characters
    fstream1=fopen("alphabet.dat","r");
    fseek(fstream1,0,SEEK_SET);
    for(int a=1;a<=13;++a){
        fscanf(fstream1,"%c",&ch);
        printf("%c ",ch);
        fseek(fstream1,1,SEEK_CUR);
    }
    fclose(fstream1);

    return 0;
}