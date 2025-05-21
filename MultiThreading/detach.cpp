// DEATACH NOTES
// 0. this is used to detach newly created thread from the parent thread.
// 1. always check before detaching a thead that it is joinable otherwise we may end up double deataching and double detach() will result into termination
// 2. IF we have detached thread and main fucntion is returning then the deatached thread exevution is suspended
#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
// function where we have to test 
void run(int count) {
	while (count-- > 0) {
		cout << "shah and akansha" << endl;
	}
	std::this_thread::sleep_for(chrono::seconds(5));
	cout<<"thread fininshed"<<endl;
}

int main() {
	// // for time calculating
	// auto startTime = high_resolution_clock::now();



	// now implemaenting the thread concept
	std::thread t1(run,10);
	cout<<"main()"<<endl;
	// now call the thread
	t1.detach();
	cout<<"main() after"<<endl;

	// auto stopTime = high_resolution_clock::now();
	// auto duration = duration_cast<seconds>(stopTime - startTime);
	// cout << "Sec: " << duration.count() << "\n";
	return 0;
}
