#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int MAX=100000;
	int Add[100000];
	int Sort_Data[100000];
	Sort_Data[0]=0;
	Sort_Data[1]=MAX;
	int Sort_Data_Counter=0;
	int Sort_Data_MAX=1;
	int Sort_Data_MAX_Next=1;
	int Compare;
	unsigned int Bit=1;
	Bit=Bit<<15;
	int Counter=0;
	int Counter_MAX;
//-------------------------
	srand((unsigned)time(NULL));
	printf("Input(rand()%10)=\n");
Loop_Input_Rand:
		Add[Counter]=rand()%30;
	if(Counter!=MAX){
		Counter++;
		goto Loop_Input_Rand;
	}
	printf("\n Sort=");
	goto GOTO_Sort_ON;
//--------------------------
Min_Loop:
	Sort_Data_Counter++;
	if(Sort_Data_Counter>Sort_Data_MAX){
		Bit=Bit>>1;
		if(Bit==0){
			goto End;
		}
		Sort_Data_Counter=0;
		Sort_Data_MAX=Sort_Data_MAX_Next;
	}
GOTO_Sort_ON:
	Counter=Sort_Data[Sort_Data_Counter];
	Sort_Data_Counter++;
	Counter_MAX=Sort_Data[Sort_Data_Counter];
	if(Counter_MAX==Counter){
		Sort_Data[Sort_Data_Counter]=Sort_Data[Sort_Data_MAX_Next];
		Sort_Data_Counter--;
		Sort_Data_MAX_Next--;
		Sort_Data[Sort_Data_Counter]=Sort_Data[Sort_Data_MAX_Next];
		if(Sort_Data_MAX_Next==Sort_Data_MAX){
			Sort_Data_MAX=Sort_Data_MAX-2;
		}
		goto GOTO_Sort_ON;
	}
//--------------------------
Sort_Loop:
	if(Add[Counter]&Bit){
		Compare=Add[Counter];
		Add[Counter]=Add[Counter_MAX];
		Add[Counter_MAX]=Compare;
		Counter_MAX--;
		if(Counter==Counter_MAX){
			if(Add[Counter_MAX]&Bit){
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Counter_MAX;
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Sort_Data[Sort_Data_Counter];
				Sort_Data[Sort_Data_Counter]=Counter_MAX-1;
				goto Min_Loop;
			}else{
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Counter_MAX+1;
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Sort_Data[Sort_Data_Counter];
				Sort_Data[Sort_Data_Counter]=Counter_MAX;
				goto Min_Loop;
			}
		}
		goto Sort_Loop;
	}
	Counter++;
	if(Counter==Counter_MAX){
		if(Sort_Data[Sort_Data_Counter]!=Counter_MAX){
			if(Add[Counter_MAX]&Bit){
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Counter_MAX;
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Sort_Data[Sort_Data_Counter];
				Sort_Data[Sort_Data_Counter]=Counter_MAX-1;
				goto Min_Loop;
			}else{
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Counter_MAX+1;
				Sort_Data_MAX_Next++;
				Sort_Data[Sort_Data_MAX_Next]=Sort_Data[Sort_Data_Counter];
				Sort_Data[Sort_Data_Counter]=Counter_MAX;
				goto Min_Loop;
			}
		}
		goto Min_Loop;
	}
	goto Sort_Loop;
//--------------------------
End:
	Counter=0;
Printf_Loop:
		printf("%d",Add[Counter]);
		printf("_");
		Counter++;
	if(Counter<=MAX){
		goto Printf_Loop;
	}


}
