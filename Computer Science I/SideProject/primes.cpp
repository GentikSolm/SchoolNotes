int i = 6;
if(userInput == 2 || userInput == 3) return true;
else if((userInput % 2 == 0)||(userInput % 3 == 0)) return false;
while(sqrt(userInput) >= i){
	if(userInput % (i-1)== 0 || userInput % (i+1)== 0)
	i+=6;
	return false;
}
