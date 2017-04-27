//CS362 Random Testing Quiz 2
//Xiaoli Sun
//April 27, 2017


How I develop the solution and how it works. 


For inputChar(): Initially I generated random number and got all random characters from ASCII table. But then I find that some characters (from 0 to 32) are not necessary. And it took too many time and iterations to reach to state 9. So that I decided to only generate random number from 32 to 126 to get random characters. The time to reach to state 9 was reduced to a reasonable range.

For inputString(): At first, I create a string array and generated chars as the same as inputChar, then store chars to array and return it. Then I found it took too many times to generate "reset". Finally I decided to only select random lower case alphabet characters from ASCII table which is from 97 to 122. This modification significantly reduce the number of iteration and time. I totally satisfy with the time and result. 