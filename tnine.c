#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 101
#define MAX_CONTACTS 200

void upper_to_lower(char *current_letter){//funkce meni velka pismena na mala

    if (*current_letter>='A' && *current_letter<='Z')
    {
        *current_letter+=32;
    }
}



void change_to_tnine(char *given){ //funkce meni znaky abecedy v kontaktu na odpovidajici cisla T9

if (*given>='a' && *given<='c')
{
    *given = '2';
}else
if (*given>='d' && *given<='f')
{
    *given = '3';
}else
if (*given>='g' && *given<='i')
{
    *given = '4';
}else  
if (*given>='j' && *given<='l')
{
    *given = '5';
}else    
if (*given>='m' && *given<='o')
{
    *given = '6';
}else
if (*given>='p' && *given<='s')
{
    *given = '7';
}else
if (*given>='t' && *given<='v')
{
    *given = '8';
}else
if (*given>='w' && *given<='z')
{
    *given = '9';
}else
if (*given=='+')
{
    *given = '0';
}

}

int find_contact(char list[MAX_CONTACTS][MAX_LENGTH],char contacts[MAX_CONTACTS][MAX_LENGTH], char *set_numbers, int number_of_lines){
int length_list, length_set_number=strlen(set_numbers);
int found = 0;
for (int row = 0; row < number_of_lines+1; row++){
length_list = strlen(list[row]);

for (int column = 0; column <= length_list; column++) { 
        int match = 1;
        for (int j = 0; j< length_set_number; j++) {
            if (list[row][column+j] != set_numbers[j]) {  // porovnává T9 transformované kontakty s čísly
                match = 0;
                break;
            }
        }
        if (match) {
            if (row % 2 == 0) { //tisk kontaktu, pokud se shoduje se zadanym argumentem
                    fprintf(stdout,"%s, %s\n", contacts[row], contacts[row + 1]);
                    row++; 
                    found = 1; 
                    break;
                } else {
                    fprintf(stdout,"%s, %s\n", contacts[row - 1], contacts[row]);
                    found = 1; 
                    break;
                }
            
         
         
        }
    }
}
    if (!found) {
        fprintf(stdout,"Not found\n");
    }
    return found;



}


int main(int argc, char *argv[])
{
char list[MAX_CONTACTS][MAX_LENGTH];
int ch;
int row=0, column=0, idx3=0;
int number_of_contacts = 0;
int number_of_lines=0;
char contacts[MAX_CONTACTS][MAX_LENGTH];
 
            
        while ((ch = getchar()) != EOF)
        {

            list[row][column]=ch;
            contacts[row][column]=ch;
            upper_to_lower(&list[row][column]);
            upper_to_lower(&contacts[row][column]);
            change_to_tnine(&list[row][column]);
           
           
          

          
            if (list[row][column]=='\n')
            {
                list[row][column] = '\0';
                contacts[row][column] = '\0';
                row++;
                column=0;
                idx3++;
                number_of_lines++;
            }else column++;
            if (idx3==2)
            {
                idx3=0;
                number_of_contacts++;
            }//rozdeleni kontaktu do matice
            
            if (column> MAX_LENGTH-1) //Error hlidajici maximalni delku kontaktu
            {
                fprintf(stderr,"\nError: Contact name is too long.(Maximum 100 characters)\n");
                return 0;
            }
            
            
            
        //precteni souboru, pokud byl zadan v argumentu a nasledne zapsani

    number_of_contacts++;
    }




row=0;   
if (argc !=2){
    while (row<number_of_lines)
        {
            printf("%s, %s\n",contacts[row], contacts[row+1]);
            row+=2;
        }
}//tisk kontaktu, pokud nebyl zadan argument




row=0;
 if (argc == 2)
    {
    char *set_numbers = argv[1];
    while (set_numbers[row] != '\0')
    {
        if (!((set_numbers[row]>='0' && set_numbers[row]<='9') || (set_numbers[row]=='+')))
        {
        fprintf(stderr,"Error: Wrong argument.\n");
        return 1;
        }//Error osetrujici zadany argument pro vyhledavani
        row++;

    }
    
    
   find_contact(list,contacts,set_numbers,number_of_lines);

 }
    

if (argc>2)
{
    fprintf(stderr,"Error: Too much arguments.\n");
    return 1;
}//Pokud je vice argumentu vypise Error


return 0;
}
