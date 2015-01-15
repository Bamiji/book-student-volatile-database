/************************************************************
    Author: Banji Afolabi
    Language Used: C
    Compiler: guc
    IDE: Code::blocks
*************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>

//Function Prototypes
void mainmenu(), mainmenuaction(), addstudent(), addbook();
void del(), keepdel(), forpopping(), forbreaking();
void searchh(), keepsearch(), searchbooktitle(), searchbookid();
void searchstudentname(),searchstudentid(), searchstudentlv();
int flush_stdin();

int act, numberofbooks, numberofstudents, i, j, k, n, o, p;
int width, width2, nn, digits, nnn, ii;
int dontmatch, gottogo[50], done, searchid,searchsid;
int searchslv,c,cholder[51],indextodie,found,counter,strl;
int width3, width4, width5, digitss, nnnn, the_deleteds[50];
int the_deletedb[50], holdstudent,holdbook,its_here;
int tds=0, tdb=0, xo, actt, acttt;

char searchtitle[36], searchtitlee[36];
char searchname[40], searchnamee[40];

//Display Variables
char space[]=" ", space2[]="                                   ";
char space3[]="             ", space4[]="                             ";
char space5[] = "ID              ", verline[] = "|";

struct book{
char title[36];//come back to this later[FIXED]
int id;
}b[50];
struct student{
char name[40];
int level;
int idd;
}s[50];


//Main
int main(){

for(xo=0;xo<50;xo++){
 the_deletedb[xo]=-1;
 the_deleteds[xo]=-1;}

mainmenu();
return 0;
}

void mainmenu(){

printf("\no.......................o");
printf("\n|  MAIN MENU            |\no.......................o\n|1: Create book         |\n|2: Create student      |\n|3: Display book/student|");
printf("\n|4: Delete book/student |\n|5: Search book/student |\n|6: Exit                |\n");
printf("o.......................o\n");
mainmenuaction();

 }

void mainmenuaction(){

do{
printf("\nPlease enter a number from the main menu options: ");}
while( (scanf("%d",&act)==0) && flush_stdin() );

if(act==1){
addbook();
}
else if(act==2){
addstudent();
}
else if(act==3){

flush_stdin();
printf("\n1: Book\n2: Student\nWhich would you like to see? ");
scanf("%d",&act);

if(act==1){
printf("\no..............................................................................o");
printf("|  Number  |               Title               |              IDN              |");
printf("o..............................................................................o\n");

i=0;
o=1;
j=0;

while(i<50){

if(b[j].title[0]!='\0'){

strl = strlen(b[j].title) - 5;
width =strlen(space4)- strl;

digits=0;
nnn = b[j].id;
if(nnn==0){digits=1;}

while(nnn!=0){
    nnn/=10;
    digits++;}

width4 = 32 - digits;
width4/=2;

if (digits%2!=0){width3=width4;
                 width4++;}
else {width3=width4;}

printf("|     %d    |%s%*s |%*s%d%*s",o,b[j].title,width,space,width3,space,b[j].id,width4,verline);
j++;
o++;
}

else if (b[j].title[0]=='\0'){
    j++;}
    i++;}
printf("o..............................................................................o");}
if(act==2){
printf("\no..............................................................................o");
printf("| Number |                 Name                 |    Level    |       ID       |o");
printf("..............................................................................o\n");
i=0;
o=1;
j=0;
while(i<50){

if(s[j].name[0]!='\0'){
strl=strlen(s[j].name) - 4; //space control
width=strlen(space2) - strl;

digits=0;
nn = s[j].level;
while(nn!=0){

    nn/=10;
    digits++;
}
if(digits>3){
    while(digits!=3){
        s[j].level/=10;
digits=0;
nn = s[j].level;
while(nn!=0){

    nn/=10;
    digits++;
}
    }
}

digitss=0;
nnnn = s[j].idd;
while(nnnn!=0){

    nnnn/=10;
    digitss++;
}

width2=(strlen(space3))-digits;
width2/=2;
if (digits%2!=0){
    width5=width2;
    width2++;
}
else {
    width5=width2;
    width2+=2;
}
width4 = 16 - digitss;
//width4 = width4 - 2;
width4/=2;
if (digitss%2!=0){
    width3=width4;
    width4+=2;
}
else {
    width3=width4;
width4++;
}
printf("|    %d   |%s%*s%*s%d%*s%*s%d%*s",o,s[j].name,width,verline,width5,space,s[j].level,width2,verline,width3,space,s[j].idd,width4,verline);
j++;
o++;
}


else if (s[j].name[0]=='\0'){
    j++;}
    i++;}
printf("o..............................................................................o");}

mainmenu();
}
else if(act==4){
del();
}
else if(act==5){
searchh();
}
else if(act==6){

flush_stdin();

printf("\n1: YES\n2: NO\nAre you sure you want to exit? ");
scanf("%d",&act);

if(act==1){
EXIT_SUCCESS;
}
else {mainmenu();}}
else {
flush_stdin();
mainmenuaction();}}


//Functions

int flush_stdin(){
int ch;
do{
    ch = getchar();
}while(ch!=EOF && ch!='\n');
return 1;
}

void addbook(){
flush_stdin();
 for(xo=49;xo>-1;xo--){
        if(the_deletedb[xo]>-1){
            its_here=1;
            tdb--;
            break;
        }}
   if(its_here==1){
        holdbook=numberofbooks;
        numberofbooks=the_deletedb[xo];
        the_deletedb[xo]=-1;
        }
        if(numberofbooks==50){
    printf("\nBook Memory Full\n\n1:YES\n2:NO\nWould you like to delete some records to make space? ");
    scanf("%d",&actt);
    if(actt==1){
        del();
    }
    else{mainmenu();}
}
printf("\nPlease enter the book's\nTitle: ");
gets(b[numberofbooks].title);
printf("ID: ");
scanf("%d",&b[numberofbooks].id);

if(its_here==1){
    numberofbooks=holdbook;
    its_here=0;
}
else{if(b[numberofbooks].title[0] != ' ' && b[numberofbooks].title[0] != '\0'){
printf("\nBook Data Stored! \n");
numberofbooks++;}
else{printf("\nData Not Stored: illegal file name \n");
b[numberofbooks].title[0] = '\0';
}}

printf("\n1: Continue\n2: Back to Main Menu");
printf("\nWould you like to continue entering books? ");
scanf("%d",&act);
if(act==1){
    addbook();
}
else {mainmenu();}}

void addstudent(){
    flush_stdin();
    for(xo=49;xo>-1;xo--){
        if(the_deleteds[xo]>-1){
            its_here=1;
            tds--;
            break;
        }}
   if(its_here==1){
        holdstudent=numberofstudents;
        numberofstudents=the_deleteds[xo];
        the_deleteds[xo]=-1;
         }
if(numberofstudents==50){
    printf("\nStudent Memory Full\n1:YES\n2:NO\nWould you like to delete some records to make space? ");
    scanf("%d",&acttt);
    if(acttt==1){
        del();
    }
    else{mainmenu();}
}
printf("\nPlease enter the student's data\nFull Name: ");
gets(s[numberofstudents].name);
printf("Level: ");
scanf("%d",&s[numberofstudents].level);
printf("ID: ");
scanf("%d",&s[numberofstudents].idd);


if(its_here==1){
    numberofstudents=holdstudent;
    its_here=0;
}
else{if(s[numberofstudents].name[0] != ' ' && s[numberofstudents].name[0] != '\0'){
printf("\nStudent Data Stored!\n");
numberofstudents++;}
else{s[numberofstudents].name[0] = '\0';
printf("\nData Not Stored: illegal file name \n");
}
}
printf("\n1: Continue\n2: Back to Main Menu");
printf("\nWould you like to continue entering students? ");
scanf("%d",&act);
if(act==1){
    addstudent();
}
else {mainmenu();}}

void del(){
flush_stdin();
printf("\n1: Book\n2: Student\nWhich do you want to delete? ");
scanf("%d",&act);
if(act==1){
for(counter = 0; counter<50; counter++){
if(b[counter].title[0] != '\0'){
break;
}
switch(counter){
  case 49: printf("\nNo books in memory\n");
keepdel();
}
}
printf("\n1: By Title\n2: By ID\nHow do you want to find the book to be deleted? ");
scanf("%d",&act);
if(act==1){
    searchbooktitle();
   if(found == 1){ forpopping();}
}
if(act==2){
   searchbookid();
if(found == 1){ forpopping();}
}
}
else if(act==2){
for(counter = 0; counter<50; counter++){
if(s[counter].name[0] != '\0'){
break;
}
switch(counter){
  case 49: printf("\nNo students in memory\n");
 keepdel();
  }
}
printf("\n1: Name\n2: Level\n3: ID\nHow do you want to find the student to be deleted? ");
scanf("%d",&act);
if(act==1){
    searchstudentname();
    if(found == 1){ forbreaking();}
   }
if(act==2){
    searchstudentlv();
    if(found == 1){ forbreaking();}
  }
if(act==3){
    searchstudentid();
    if(found == 1){ forbreaking();}
  }
}

keepdel();
}

void keepdel(){
printf("\n1: Yes\n2: No\nKeep Deleting? ");
scanf("%d",&act);
if(act==1){
    del();
}
else{mainmenu();}}

void forpopping(){

printf("\nPlease enter the search result number of the book you want deleted: ");
scanf("%d",&indextodie);

if(indextodie<=c && indextodie > 0){
for(c=0;c<50;c++){
    if( c==indextodie){
b[cholder[c]].title[0] ='\0';
done=-11;
break;
    }

}}
else{
    printf("\nThe Search Result Number you entered does not belong to any result listed\n");}

if(done==-11){
    the_deletedb[tdb]=cholder[c];
    printf("\nBook(s) Deleted!\n");
    tdb++;
    done=0;
}

}

void forbreaking(){
printf("\nPlease enter the search result number of the student you want deleted: ");
scanf("%d",&indextodie);

if(indextodie<=c && indextodie > 0){
for(c=1;c<51;c++){
    if( c==indextodie){
s[cholder[c]].name[0]='\0';

done=-11;
break;
    }
}

}
else{
    printf("\nThe Search Result Number you entered does not belong to any result listed\n");
    }
if(done==-11){
    the_deleteds[tds]=cholder[c];
    printf("\nStudent(s) Data Deleted!\n");
    tds++;
    done=0;
}

}

void searchh(){
flush_stdin();
printf("\n1: Book\n2: Student\nWhat would you like to search for? ");
scanf("%d",&act);
if(act==1){

for(counter = 0; counter<50; counter++){
if(b[counter].title[0] != '\0'){
break;
}
switch(counter){
  case 49: printf("\nNo books in memory\n");
  keepsearch();
  }
}
printf("\n1: Title\n2: ID\nWhat would you like to search with? ");
scanf("%d",&act);
if(act==1){
    searchbooktitle();}
if(act==2){
searchbookid();}}
else if(act==2){
for(counter = 0; counter<50; counter++){
if(s[counter].name[0] != '\0'){
break;
}
switch(counter){
  case 49: printf("\nNo students in memory\n");
  keepsearch();
  }
}
printf("\n1: Name\n2: Level\n3: ID\nWhat would you like to search with? ");
scanf("%d",&act);
if(act==1){
    searchstudentname();}
if(act==2){
    searchstudentlv();}
if(act==3){
    searchstudentid();}
}

keepsearch();
}

void keepsearch(){
printf("\n1: Yes\n2: No\nKeep Searching? ");
scanf("%d",&act);
if(act==1){
  searchh();
}
else {mainmenu();}
}

void searchbooktitle(){
k=0;

flush_stdin();

printf("\nPlease enter the book title: ");
gets(searchtitle);
for(ii = 0; ii<36; ii++){
    searchtitle[ii]= tolower(searchtitle[ii]);
}
while(k<50){
for(ii = 0; ii<36; ii++){
    searchtitlee[ii]= tolower(b[k].title[ii]);
}
if(strcmp(searchtitle, searchtitlee)!=0 ){
        dontmatch=-1;
        gottogo[k]=-1;}
else {dontmatch=-2;
gottogo[k]=-2;
}
    k++;
}

     for(k=0;k<50;k++){
          if(gottogo[k]==-2){
                printf("\nBook(s) Found: \n");
             found = 1;
          break;

          }
switch(k){
    case 49:{printf("\nBook(s) Not Found\n");
        found = 0;
    break;
    }
    }}
c=1;
for(k=0;k<50;k++){
if(gottogo[k]==-2 && b[k].title[0] != '\0'){
printf("\n(%d)\n",c);
printf("Title: %s \nID: %d\n",b[k].title, b[k].id);
cholder[c]=k;
c++;
}
}
c--;
}

void searchbookid(){
   k=0;

printf("\nPlease enter the ID number: ");
scanf("%d",&searchid);

while(k<50){

if(searchid != b[k].id || b[k].id == -2){
        dontmatch=-1;
        gottogo[k]=-1;
}
else {
dontmatch=-2;
gottogo[k]=-2;
}
    k++;
}

     for(k=0;k<50;k++){
          if(gottogo[k]==-2){
                printf("\nBook(s) Found: \n");
                    found = 1;
          break;
          }
switch(k){
    case 49:{printf("\nBook(s) Not Found\n");
        found = 0;
    break;
    }
}}
c=1;
for(k=0;k<50;k++){
if(gottogo[k]==-2 && b[k].title[0] != '\0'){
printf("\n(%d)\n",c);
printf("Title: %s \nID: %d\n",b[k].title, b[k].id);
cholder[c]=k;
c++;
}
}
c--;}

void searchstudentname(){

flush_stdin();
printf("\nPlease enter the students full name: ");
gets(searchname);
k=0;
for(ii = 0; ii<40; ii++){
    searchname[ii]= tolower(searchname[ii]);
}
while(k<50){
for(ii = 0; ii<40; ii++){
    searchnamee[ii]= tolower(s[k].name[ii]);
}
if(0 != (strcmp(searchname, searchnamee))){
        dontmatch=-1;
        gottogo[k]=-1;}
if(strcmp(searchname, s[k].name)== 0){
        dontmatch=-2;
gottogo[k]=-2;
}
    k++;
}

     for(k=0;k<50;k++){
          if(gottogo[k]==-2){
                printf("\nStudent(s) Found: \n");
                    found = 1;
          break;
          }
switch(k){
    case 49:{printf("\nStudent(s) Not Found\n");
  //  mainmenu();
      found = 0;
  break; }
}}
c=1;
for(k=0;k<50;k++){
if(gottogo[k]==-2 && s[k].name[0] != '\0'){
printf("\n(%d)\n",c);
printf("Name: %s \nLevel: %d \nID: %d\n",s[k].name, s[k].level,s[k].idd);
cholder[c]=k;
c++;
}
}
c--;
}

void searchstudentlv(){
    k=0;

printf("\nPlease enter the Level: ");
scanf("%d",&searchslv);

while(k<50){

if(searchslv != s[k].level || s[k].level == -2){
        dontmatch=-1;
        gottogo[k]=-1;
}
else {dontmatch=-2;
gottogo[k]=-2;
}
    k++;
}

     for(k=0;k<50;k++){
          if(gottogo[k]==-2){
                printf("\nStudent(s) Found: \n");
             found = 1;
          break;
          }
switch(k){
    case 49:{printf("\nStudent(s) Not Found\n");
       found = 0;
   break;
    }
}}
c=1;
for(k=0;k<50;k++){
if(gottogo[k]==-2 && s[k].name[0] != '\0'){
printf("\n(%d)\n",c);
printf("Name: %s \nLevel: %d \nID: %d\n",s[k].name,s[k].level,s[k].idd);
cholder[c]=k;
c++;
}
}
c--;
}

void searchstudentid(){
    k=0;

printf("\nPlease enter the ID number: ");
scanf("%d",&searchsid);

while(k<50){

if(searchsid != s[k].idd || s[k].idd == -2){
        dontmatch=-1;
        gottogo[k]=-1;
}
else {dontmatch=-2;
gottogo[k]=-2;
}
    k++;
}

     for(k=0;k<50;k++){
          if(gottogo[k]==-2){
                printf("\nStudent Found: \n");
                    found = 1;
          break;
          }
switch(k){
    case 49:{printf("\nStudent Not Found\n");

       found = 0;
   break;
    }
}}
c=1;
for(k=0;k<50;k++){
if(gottogo[k]==-2 && s[k].name[0] != '\0'){
printf("\n(%d)\n",c);
printf("Name: %s \nLevel: %d \nID: %d\n",s[k].name,s[k].level,s[k].idd);
cholder[c]=k;
c++;
}
}
c--;
}
