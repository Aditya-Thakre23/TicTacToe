#include<stdio.h>
#include<stdlib.h>
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void display()
{
	system("clear");
	printf("*****Tic Tac Toe*****\nPlayer 1(X) and Player 2(O)\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", arr[0], arr[1], arr[2]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", arr[3], arr[4], arr[5]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n", arr[6], arr[7], arr[8]);
	printf("     |     |     \n");
}

int checkWinner(){
	int status=0;
	if(arr[0]==arr[1] && arr[1]==arr[2])//Row wise check
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[3]==arr[4] && arr[4]==arr[5])
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[6]==arr[7] && arr[7]==arr[8])
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[0]==arr[3] && arr[3]==arr[6])//Column wise check
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[1]==arr[4] && arr[4]==arr[7])
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[2]==arr[5] && arr[5]==arr[8])
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[0]==arr[4] && arr[4]==arr[8])//Diagonal Check
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[2]==arr[4] && arr[4]==arr[6])
		status = arr[0]=='X' ? 1 : 2;
	else if(arr[0]!='1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' && arr[6]!='7' && arr[7]!='8' && arr[8]!='9')
		status = 0;//Draw
	else
		status = -1;//Ongoing
	return status;	
}
int main(void)
{
	int player = 1, status, choice;
	char c;
	do{
		display();
		player = player%2? 1:2;
		printf("\n Enter your choice Player %d: \n", player);
		scanf("%d", &choice);
		c = player==1 ? 'X' : 'O';
		if(choice==1 && arr[0]=='1')
			arr[0] = c;
		else if(choice==2 && arr[1]=='2')
			arr[1] = c;
		else if(choice==3 && arr[2]=='3')
			arr[2] = c;
		else if(choice==4 && arr[3]=='4')
			arr[3] = c;
		else if(choice==5 && arr[4]=='5')
			arr[4] = c;
		else if(choice==6 && arr[5]=='6')
			arr[5] = c;
		else if(choice==7 && arr[6]=='7')
			arr[6] = c;
		else if(choice==8 && arr[7]=='8')
			arr[7] = c;
		else if(choice==9 && arr[8]=='9')
			arr[8] = c;
		else{
			printf("Invalid choice!! \n");
			player--;
		}
		status = checkWinner();
		player++;
	}while(status==-1);
	display();
	if(status==1)
		printf("Player 1 wins!!\n");
	else if(status==2)
		printf("Player 2 wins!!\n");
	else
		printf("Draw!!\n");
	
	return 0;
}
