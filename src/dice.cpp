#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//enumeration constants represent game status
enum Status {CONTINUE, WON, LOST};

int rollDice(void);//function prototype

int main(void)
{
	int sum ; // sum of rolled dice
	int myPoint; //Player Must make this point to win 

	enum Status gameStatus; //can Contain CONTINUE, WON , LOST

	//Randomize random number generator using current time
	srand(time(NULL));

	sum = rollDice(); //first Roll of dice

	//determine game status based on sum of dice
	switch(sum)
	  {
	
	//win on first roll
	case 7: //7 is a winner
	case 11: //11 is winner
		gameStatus= WON; break;
	
	//lose on first call
	case 2:
	case 3:
	case 12:
		gameStatus = LOST; break;

	//remember point
	default:
		gameStatus= CONTINUE;//Player should keep rolling
		myPoint = sum; //remember the point
		printf("Point is %d\n",myPoint);
		break;
	  }//end switch

	//While Game not completed
	while(CONTINUE==gameStatus)
	  {//Player Should Keep Rolling The Dice
	    sum=rollDice();

	    //determine Game status
	    if(sum==myPoint){//Player Should Keep Rolling
	      gameStatus=WON; //Game Over Player Won
	      
	    }//Endif

	    else{
	      if(7==sum){//Lose by rolling 7
		gameStatus= LOST;//game over, Player Won
		
	      }//End if
	    }//End Else
	  }//End While

	//Display Won Or lost message
	if(WON==gameStatus){// Did Player win
	  puts("Player Wins");
	}//End if
	else{//Player lost
	  puts("Player Lost");
	}//end else
}//End Main

//Roll Dice , Calculate sum and display result
int rollDice(void)
{
  int die1; //first die
  int die2; //second die
  int workSum; //sum of dice

  die1 = 1 +(rand()%6);//Pick a random die1 value
  die2 = 1+ (rand()%6); //Pick a random die2 value
  workSum = die1+ die2;

  //display result of this roll
  printf("Player Rolled %d+%d= %d\n", die1, die2, workSum);
  return workSum;//return sum of dice
  
}//End of funtion rollDice
