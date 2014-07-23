/****************************************
 * Hangman
 *
 * Author: Ryan Wood
 * Date: 7/19/14
 *
 * Description: Player 1 inputs a secret 
 * word to be guessed by Player 2. It 
 * operates much like hangman, though 
 * without the drawing part. Unfortunately
 * I could not figure out how to show
 * double letters, so I added a guessing
 * option for the 2nd player to compensate
 *
 * *************************************/


 #include<iostream>
 #include<string>
 #include<cctype>
 #include<cstdio>
 	using namespace std;
	 

		

		 

		 string ask_and_check(string &word,string &guess, int &guesses,string &blank){//My checking function
		       


			 for(int x = 0  ; x <= word.length() && guesses >= 0 ; x++){//This for loop iterates through and compares the guessed letter to the word 
			 	string y;
				y = word.at(x);
			
				
					if(y == guess){
					   cout<<"Correct! The letter: " <<guess << " Is in the word." <<endl <<endl;
						guesses--;
						  cout<<"The word so far...." <<endl;
						  blank.replace(x,1,y);//This replaces one of the "blank" characters with a letter that is a correct guess. My way of displaying the word thus far 
						  return blank;}//Returns the players progress towards getting the word
					else if(y != guess && x == word.length() - 1){
					    cout<<"Nope, not there!" <<endl;
						guesses--;
					    cout<<"The word so far...."<<endl;
						return blank;
						}//else
						 }//for
			             return blank;}//function
						
	
			 int main(){
		    
		    int guesses, j, k;
		    string blank, guess, sofar, word, prev, wordguess, miss, u ,t,o;//ALOT OF STRINGS! In order; what they do [shows progress, stores the guess, for calling the checking variable, stores the secret word, stores previous guesses, for guessing the word straight up, the last three variables are for showing what letters the player missed
		    char uppercheck;//used to check for uppercase and integers in the secret word
		    j = 0;//condition for allowing the user to pass the secret word inputting stage
		    o = "_";//Used to show the user what letters they missed, I will explain later on	
			
		   while(j!=1){//Checks the input to make sure it is lower case and free of integers
			cout<<"Player 1, your secret word please! No integers or uppercase letters!" <<endl;
			cin>>word;
				    for(int h = 0; h < word.length();++h){
					uppercheck = word.at(h);
					k = (word.length() - 1);
						if(isupper(uppercheck) != 0){//checks for uppercase and digits
							break;}
						else if(isdigit(uppercheck) != 0){
							break;}
						else if(h == k){
							j = 1;
							break;}			
										}	
										
						
											}   
												 
												
																
		for(int v = 0; v<99; v++){
			cout<<endl;}
				 															
		for(int p = 0; p<=word.length() - 1 ; p++){//setting up my display for word length and correct guesses
				blank.append("?");}  

		    guesses = word.length() + 3;//gives the player 3 guesses more than there are letters in the word
		    miss = word;
		
		while(guesses>0){
			cout<<"Your guesses so far: " <<prev <<endl;//reports back previous guesses
			cout<<"Guess a letter!" <<endl;
			cin>>guess;
			prev.append(guess);//stores previous guesses
				   

		 sofar =  ask_and_check(word,guess,guesses,blank);//calling the check function
			cout<<sofar <<endl;//reporting back the check functions return value
												
																			
		cout<<"Guess the word or hit enter to keep guessing letters"<<endl;//allows the user to try and guess the word
			cin.ignore(100,'\n');     //Allows the player
			getline(cin, wordguess);   //to skip guessing the word by hitting the enter key   
				 if(wordguess == word){//First win condition, if they guess it without finding all the letters
					cout<<"You have won! The word was: " <<word <<endl;
					return 0;}
							
						 
							

	        if(sofar == word){//If they guess all the letters, they also win... duh
			cout<<"You have won! The word was: " <<word <<endl;
				break;	}
		else if(guesses == 0){
			cout<<"You are out of guesses!"<<endl;
			cout<<"The secret word was: " <<word <<endl;//Gives the secret word
				for(int f = 0; f < prev.length(); f++){//Showing what letters were missed. Nested for loops iterate through guesses and the secret word itself. Any letters found in common are replaced by blank spaces. It is the best way I could think of to do this currently.
					u = prev.at(f);	
						for(int s = 0; s < word.length(); s++){
							t = word.at(s);
								if(u == t){
								  miss.replace(s,1,o);}
								else{
								  continue;}
										}
											}
												}
													}
			cout<<"You were missing the letters: " <<miss <<endl;
			 			return 0;
								}
						
					




		

			
