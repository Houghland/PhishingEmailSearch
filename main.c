/*

Lauren

Quiz 3 project

Due: 5/1/21

Description: Create a program that scans an email for possible phishing schemes and displays the word/phrase and its frequency in the email

*/


#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#include<string.h>

//strcuture for the email keywords/phrases
struct email{
    char *word;
    char *wordCapital;
    int commonRank;
    int total;
    int frequency;
    
};

//functions
//list of words/phrases
void createWordList (struct email[]);
void printResults(struct email data[]);

int main(int argc, const char * argv[]) {
    
    //decalre structure data
    struct email data [100];
    
    //call function to create list of words/phrases
    createWordList(data);
    
    //initialize a string srray for file
    char string[50];
    
    //open file (email) for reading
    FILE* filePtr = fopen("email.txt", "r");
    
    //check if file exists
    if (filePtr == NULL){
        puts("File could not be opened");
    }
    
    else {
        
        puts("Scanning email...\n");
        puts("Likeliness of words based on scale 1-3\n");
        puts("One point if it’s somewhat likely, two points if moderately likely, or three points if highly likely\n");
        puts("\n");
        
        while(fscanf(filePtr, "%s", string) == 1){
            
            for (int i = 0; i < 30; i++) {
                
                //compare string to the word
                if (strstr(string, data[i].word) != 0){
                    data[i].total += data[i].commonRank;
                    data[i].frequency ++;
                }//end if
                //compare string to word with capital letter
                else if(strstr(string, data[i].wordCapital) != 0){
                    data[i].total += data[i].commonRank;
                    data[i].frequency ++;
                }//end if
                
            }//end for
        }// end while
        
    }
    //print results
    printResults(data);
    //close file
    fclose(filePtr);
    
    return 0;
}

void printResults(struct email data[]){
    printf("()Word/Phrase\t Frequency\tTotal Points\n");
    printf("----------------------------------------------------\n");
    
    //total points
    int totalPoints = 0;
    //display frequency of word/phrase
    for (int i = 0; i< 30; i++){
        totalPoints += data[i].total;
        if(data[i].frequency > 0){
            printf("(%d)%s  \t\t\t%d   \t\t\t%d\n", data[i].commonRank, data[i].word, data[i].frequency, data[i].total);
        }//end if
    }
    
    //display total points from email
    printf("\n");
    printf("Total Points for Email: %d\n", totalPoints);
    
}

void createWordList (struct email data []){
    
    data[0].word = "free";
    data[0].wordCapital = "Free";
    data[0].commonRank= 2;
    data[0].frequency = 0;
    data[0].total = 0;
    
    data[1].word = "label";
    data[1].wordCapital = "Label";
    data[1].commonRank = 1;
    data[1].frequency = 0;
    data[1].total = 0;
    
    data[2].word = "invoice";
    data[2].wordCapital = "Invoice";
    data[2].commonRank = 1;
    data[2].frequency = 0;
    data[2].total = 0;
    
    data[3].word = "post";
    data[3].wordCapital = "Post";
    data[3].commonRank = 1;
    data[3].frequency = 0;
    data[3].total = 0;
    
    data[4].word = "document";
    data[4].wordCapital = "Document";
    data[4].commonRank = 3;
    data[4].frequency = 0;
    data[4].total = 0;
    
    data[5].word = "postal";
    data[5].wordCapital = "Postal";
    data[5].commonRank = 1;
    data[5].frequency = 0;
    data[5].total = 0;
    
    data[6].word = "calculation";
    data[6].wordCapital = "Calculation";
    data[6].commonRank = 2;
    data[6].frequency = 0;
    data[6].total = 0;
    
    data[7].word = "copy";
    data[7].wordCapital = "Copy";
    data[7].commonRank = 3;
    data[7].frequency = 0;
    data[7].total = 0;
    
    data[8].word = "fedex";
    data[8].wordCapital = "Fedex";
    data[8].commonRank = 1;
    data[8].frequency = 0;
    data[8].total = 0;
    
    data[9].word = "financhial";
    data[9].wordCapital = "Financhial";
    data[9].commonRank = 1;
    data[9].frequency = 0;
    data[9].total = 0;
    
    data[10].word = "statement";
    data[10].wordCapital = "Statement";
    data[10].commonRank = 1;
    data[10].frequency = 0;
    data[10].total = 0;
    
    data[11].word = "claim";
    data[11].wordCapital = "Claim";
    data[11].commonRank = 3;
    data[11].frequency = 0;
    data[11].total = 0;
    
    data[12].word = "notification";
    data[12].wordCapital = "Notification";
    data[12].commonRank = 2;
    data[12].frequency = 0;
    data[12].total = 0;
    
    data[13].word = "irs";
    data[13].wordCapital = "Irs";
    data[13].commonRank = 3;
    data[13].frequency = 0;
    data[13].total = 0;
    
    data[14].word = "delivery";
    data[14].wordCapital = "Delivery";
    data[14].commonRank = 2;
    data[14].frequency = 0;
    data[14].total = 0;
    
    data[15].word = "ticket";
    data[15].wordCapital = "Ticket";
    data[15].commonRank = 1;
    data[15].frequency = 0;
    data[15].total = 0;
    
    data[16].word = "urgent";
    data[16].wordCapital = "Urgent";
    data[16].commonRank = 1;
    data[16].frequency = 0;
    data[16].total = 0;
    
    data[17].word = "affordable";
    data[17].wordCapital = "Affordable";
    data[17].commonRank = 1;
    data[17].frequency = 0;
    data[17].total = 0;
    
    data[18].word = "act now";
    data[18].wordCapital = "Act now";
    data[18].commonRank = 2;
    data[18].frequency = 0;
    data[18].total = 0;
    
    data[19].word = "bonus";
    data[19].wordCapital = "Bonus";
    data[19].commonRank = 1;
    data[19].frequency = 0;
    data[19].total = 0;
    
    data[20].word = "call now";
    data[20].wordCapital = "Call now";
    data[20].commonRank = 2;
    data[20].frequency = 0;
    data[20].total = 0;
    
    data[21].word = "tax";
    data[21].wordCapital = "Tax";
    data[21].commonRank = 3;
    data[21].frequency = 0;
    data[21].total = 0;
    
    data[22].word = "compare rates";
    data[22].wordCapital = "Compare rates";
    data[22].commonRank = 1;
    data[22].frequency = 0;
    data[22].total = 0;
    
    data[23].word = "instant";
    data[23].wordCapital = "Instant";
    data[23].commonRank = 2;
    data[23].frequency = 0;
    data[23].total = 0;
    
    data[24].word = "risk free";
    data[24].wordCapital = "Risk free";
    data[24].commonRank = 2;
    data[24].frequency = 0;
    data[24].total = 0;
    
    data[25].word = "refund";
    data[25].wordCapital = "Refund";
    data[25].commonRank = 3;
    data[25].frequency = 0;
    data[25].total = 0;
    
    data[26].word = "terms";
    data[26].wordCapital = "Terms";
    data[26].commonRank = 1;
    data[26].frequency = 0;
    data[26].total = 0;
    
    data[27].word = "unlimited";
    data[27].wordCapital = "Unlimited";
    data[27].commonRank = 1;
    data[27].frequency = 0;
    data[27].total = 0;
    
    data[28].word = "purchase";
    data[28].wordCapital = "Purchase";
    data[28].commonRank = 1;
    data[28].frequency = 0;
    data[28].total = 0;
    
    data[29].word = "guarantee";
    data[29].wordCapital = "Guarantee";
    data[29].commonRank = 3;
    data[29].frequency = 0;
    data[29].total = 0;
    
    data[30].word = "call now";
    data[30].wordCapital = "Call now";
    data[30].commonRank = 1;
    data[30].frequency = 0;
    data[30].total = 0;
    
}
