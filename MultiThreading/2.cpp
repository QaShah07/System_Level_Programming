#include<iostream>
#include<algorithm>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;
typedef long long int ll;
// function for EvenSum
void findEvenSum(ll start, ll end, ll *EvenSum)
{
	for(ll i=start;i<=end;i++)
	{
		if(!(i&1))
		{
			*EvenSum +=i;
		}
	}
}
// function for OddSum
void findOddSum(ll start, ll end, ll *OddSum)
{
	for(int i=start;i<=end;i++)
	{
		if(i&1)
		{
			*OddSum +=i;
		}
	}
}
// main function
int main(){
	ll start = 0, end = 1900000000;
	ll OddSum = 0,EvenSum=0;
	// for time calculating
	auto startTime = high_resolution_clock::now();
	// now implemaenting the thread concept
	std::thread t1(findEvenSum,start,end,&(EvenSum));
	std::thread t2(findOddSum,start,end,&(OddSum));
	// now call the thread
	t1.join();
	t2.join();
	// findEvenSum(start,end,&EvenSum);
	// findOddSum(start,end,&OddSum);
	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stopTime - startTime);
	cout<<"EvenSum: "<<EvenSum<<"\n";
	cout<<"OddSum: "<<OddSum<<"\n";
	cout<<"Sec: "<<duration.count()/1000000<<"\n";
	return 0;
}