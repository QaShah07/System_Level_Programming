// JOIN NOTES
// 1. Once a thread is started we wait for this thread by calling join() function on thread object.
// 2. Double join will result into program termination
// 3. If neede we should check thread is joinable before joining.

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

void run(int count) {
	while (count-- > 0) {
		cout << "shah and akansha" << endl;
	}
	std::this_thread::sleep_for(chrono::seconds(3));
}

int main() {
	// for time calculating
	auto startTime = high_resolution_clock::now();



	// now implemaenting the thread concept
	std::thread t1(run, 10);
	cout<<"main() before"<<endl;
	// now call the thread
		t1.join();
	if(t1.joinable())
	{
		t1.join();
	}
	cout<<"main() after "<<endl;


	auto stopTime = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(stopTime - startTime);
	cout << "Sec: " << duration.count() << "\n";
	return 0;
}
