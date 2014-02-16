#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define DIMES 10
#define QUARTERS 25
#define NICKLES 5
#define PENNIES 1

int getchange();

int main()
{
    int userchange = getchange();
    int Qcount, Dcount, Ncount, Pcount;
    
      
    //check quarters
    int usermoneyminusQ = 0;
    int userchangeremaining = userchange;
    for(Qcount = 0; userchangeremaining > 0; Qcount++)
    {
	    userchangeremaining = userchangeremaining - QUARTERS;
    }
    if(userchangeremaining !=0)
    {
        userchangeremaining = userchangeremaining + QUARTERS;
        usermoneyminusQ = userchangeremaining;
        if (Qcount > 0) 
            Qcount--;
    }  
    //printf("We gave the user %d quarters. We owe the user %d cents.\n",Qcount, usermoneyminusQ);
    
    
    //check dimes
    int usermoneyminusQD = 0;
    for(Dcount = 0; userchangeremaining > 0; Dcount++)
    {
	    userchangeremaining = userchangeremaining - DIMES;
    }
    if(userchangeremaining !=0)
    {
        userchangeremaining = userchangeremaining + DIMES;
        usermoneyminusQD = userchangeremaining;
        if (Dcount > 0)
            Dcount--;
    }
    //printf("We gave the user %d dimes. We owe the user %d cents.\n",Dcount, usermoneyminusQD);
    

    //check nickles
    int usermoneyminusQDN = 0;
    userchangeremaining = usermoneyminusQD;
    for(Ncount = 0; userchangeremaining > 0; Ncount++)
    {
	    userchangeremaining = userchangeremaining - NICKLES;
    }
    if(userchangeremaining !=0)
    {
        userchangeremaining = userchangeremaining + NICKLES;
        usermoneyminusQDN = userchangeremaining;
        if(Ncount > 0)
            Ncount--;
    }
    //printf("We gave the user %d nickles. We owe the user %d cents.\n",Ncount, usermoneyminusQDN);


    //check pennnies
    int usermoneyminusQDNP = 0;
    userchangeremaining = usermoneyminusQDN;
    for(Pcount = 0; userchangeremaining > 0; Pcount++)
    {
	    userchangeremaining = userchangeremaining - PENNIES;
    }
    
    usermoneyminusQDNP = userchangeremaining;
    
    //printf("We gave the user %d pennies. We owe the user %d cents.\n",Pcount, usermoneyminusQDNP);

    
    int totalcount = Qcount + Dcount + Ncount + Pcount;
    //printf("The total number of coins is:\n");
    printf("%d\n",totalcount);
}

int getchange()
{
    float usermoney;
    do
    {
        printf("How much change is owed?: ");
        usermoney = GetFloat();
    }
    while(usermoney < 0);
    float userdecimal = (usermoney - (int)usermoney);
    //printf("User's decimal amount was %f\n",userdecimal);
    
    float userchangef = round( 100.0*userdecimal);
    int userdollarsinchange = 100*(int)usermoney;
    int userchange = (int)userchangef+userdollarsinchange;
    return userchange;
    //printf("User's change was %d cents\n",userchange);
}
