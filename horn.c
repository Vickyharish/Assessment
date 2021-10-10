#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
 const char *myfile="give filename";
 int bytes=0;
 int words=0;
 int lines=0;
 char buffer[1];
 int file=open(myfile,O_RDONLY);
 enum states { whitespace, word};
 int state= whitespace;	
 if(file == -1)
 {
   printf("cannot find the file:%s\n",myfile);
 }
 else
 {
   char last = ' ';
   while(read(file,buffer,1) ==1)
    {
    bytes++;
    if(buffer[0]== ' ' || buffer[0]=='\t')
    {
      state = whitespace;
    }
    else if (buffer[0]=='\n')
    {
      lines++;
      state=whitespace;
    }
    else
    {
      if(state==whitespace)
      {
         words++;
      }
      state=word;
    }
    last = buffer[0];
   }
  printf("%d %d %d %s\n",lines,words,bytes,myfile);
 }
}
