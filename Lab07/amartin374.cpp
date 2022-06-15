#include<iostream>
#include<climits>
using namespace std;

void cutRod(int *price, int rod_length){ //Setting variables and a pointer named price
int *value= new int[rod_length+1]; //Having the price be stored in the value array once the rod piece is cut
int *lastRodLength= new int[rod_length+1]; //Storing the length from the last rod piece in the array
value[0] = 0; // 0 length of a rod has to have a value of zero 
int i, x; //variables for the nest loop

//Having the table value[] be built from bottom to top which results in the last entry of the table.
for (i = 1; i<=rod_length; i++){ // A for loop in which we loop from 1 to the length of the rod (cant be 0)
int max_value = INT_MIN; // All this does is set Max_value to INT_MIN or "negative infinity" which is equivalent to INT_MIN
int BestRodLength = -1; // Initializing bestrodlength which is then changed to length x
for (x = 1; x <= i; x++){ // for loop iteration in order to update the max_value             
if(max_value < price[x] + value[i-x]){ //comparing negative infinity to the price at index x + value[i-x].     
max_value = price[x] + value[i-x]; //max value is updated since the bestrodlength is going to be updated 
BestRodLength=x; //BestRodLength is updated to the value of x at the iteration of which max_value is updated since there was a new max_value calculated.
		} //done updating variables
	} //done iterating and comparing
value[i] = max_value; //After each iteration of the "x" loop, value stores a new value which equals max_value
lastRodLength[i] = BestRodLength; //This array essentially stores the lengths since max_value is updated
}

//Best price for the cutting rod
cout << value[rod_length] << endl; // maximum price of all of the cuts 
i = rod_length; // setting i to the length of the rod

//Displaying the rod length 
while(i > 0){ // rod length has to be greater than 0
cout << lastRodLength[i] <<  "  "; //print value of array at index i
i = i-lastRodLength[i]; //Subtracting the rodlength from the sum of the lastrodlength in order for it to equal 0 and in order to as well stop the while loop 
}
cout << "-1\n"; //output requirement from the pdf 
delete value; //to free space
delete lastRodLength; // to free space (usually used on bigger projects tho)
}

//Main
int main (int argc, char **argv){ // argument count as an int and argument values as pointer to pointer to char
int rod_length; //Holding the size of the length
cin>>rod_length; // user input of rod_length
int *price = new int[rod_length+1]; //new array pointer for each length of the rod
price[0]=0; // establish the price of 0 length as 0 
for(int i=1; i<=rod_length; i++) // A for loop in which we loop from 1 to the length of the rod
cin>>price[i]; // Getting all the prices from the each of the cuts of the rod lengths
cutRod(price,rod_length); //calls cutrod using the parameters price and rod length 
return 0; //returning the integer value, making sure it works basically without error.  
}