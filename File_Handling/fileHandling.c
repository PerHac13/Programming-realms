#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){

    //Opening and closing of file
    FILE *fptr;  //declaration of location
    fptr=fopen("sample.dat","r+"); 
    // fopen("fileName","fileType")  ft r:exitingFileRead w:newFileWrite a:existingFileAppend r+:existingFile"w""r" w+:newFile"w""r" a+:exitingFile"r""a"
    
    if(fptr==NULL)
    printf("Error-Can't open the designated File\n");
    else
    printf("Accessed file\n");

    fclose(fptr);

    //Writing of file
    FILE *fwr;
    fwr=fopen("output.dat","w");
    for(int k=34;k<100;k++)
        fprintf(fwr,"%d, ",k);
        //  fprint is used to write in file
    fclose(fwr);

    //Reading of file
    FILE *frd;
    char ch,fname[50];
    printf("Enter the Input File name with extension:   ");
    gets(fname);
    if((frd=fopen(fname,"r"))==NULL)   //only reading purpose
        printf("\nError - Can't find the designated file\n");
    else{
        fscanf(frd,"%c",&ch);
        while(!feof(frd)){
            printf("%c",ch);
            fscanf(frd,"%c",&ch);
        }
    }
    fclose(frd);
    

    //Copying of dataFile
    char cpsrc[50],cpdest[50];
    FILE *fcps,*fcpd;
    printf("Enter the source file name: ");
    gets(cpsrc);
    fcps=fopen(cpsrc,"r");
    if(fcps==NULL){
        printf("\nError - Can't find the designated file\n");
        exit(1);
    }
    printf("Enter the destination file name: ");
    gets(cpdest);
    fcpd=fopen(cpdest,"w");
    if(fcpd==NULL){
        printf("\nError - Can't create the designated file\n");
        exit(1);
    }
    while(!feof(fcps)){
        ch=getc(fcps);
        putc(ch,fcpd);
    }
    fclose(fcps);
    fclose(fcpd); 
    /* close all open files*/







    return 0;
}