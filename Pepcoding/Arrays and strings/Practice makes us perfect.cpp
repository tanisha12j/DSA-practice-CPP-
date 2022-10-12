Most programmers will tell you that one of the ways to improve your performance in competitive programming is to practice a lot of problems.
Our Chef took the above advice very seriously and decided to set a target for himself.
Chef decides to solve at least 1010 problems every week for 4 weeks.
Given the number of problems he actually solved in each week over 4 weeks as P_1, P_2, P_3,P_4, output the number of weeks in which Chef met his target.
  
Code -
  
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int count=0;
	int prblmsl;
	for(int i=0;i<4;i++){
	    cin>>prblmsl;
	    if(prblmsl>=10){
	        count++;
	    }
	}
	cout<<count;
	return 0;
}
