#include <iostream>
#include <future>
#include <mutex>
#include <memory>
#include <thread>
#include <algorithm>
#include <vector>
#include <chrono>

class Vehicle{
public:
  Vehicle(int id):_id(id){}
  int getID(){return _id;}
private:
  int _id;
};

class waitingvehicles{
public:
  waitingvehicles(){}
  Vehicle popback(){
    std::unique_lock<std::mutex> ulock(_mtx);// unique lock is needed for _condn.wait()
    _condn.wait(ulock,[this]{return !_vehicles.empty();});//pass unique lock to condition condition_variable
/* as soon as the thread wakes up(spurious wake up by OS or after receiving a signal of notify_one/notify_all)
the condition is checked so as to make sure that it was not a spurious wake up but rather a call was made
using notify one*/

    Vehicle v=std::move(_vehicles.back());
    _vehicles.pop_back();

    return v;
  }


  void pushback(Vehicle &&v){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::lock_guard<std::mutex> ulock(_mtx);
    std::cout << "Vehicle# " <<v.getID()<<" will be added to the queue " <<'\n';
    _vehicles.push_back(std::move(v));
    _condn.notify_one(); //notify client(popback function) after pushing new vehicle into vector
    std::this_thread::sleep_for(std::chrono::milliseconds(500));//for checking data races
  }
private:
  std::condition_variable _condn;
  std::mutex _mtx;
  std::vector<Vehicle> _vehicles;
};

int main(){
  std::shared_ptr<waitingvehicles> queue(new waitingvehicles);
  std::vector<std::future<void>> futures;
  for(int i=0;i<10;i++){
    Vehicle v(i);
    futures.emplace_back(std::async(std::launch::async,&waitingvehicles::pushback,queue,std::move(v)));//queue acts as an object
  }
  std::for_each(futures.begin(),futures.end(),[](std::future<void> &ftr){
    ftr.wait();
  });

  std::cout << "Collecting results...." << '\n';
  while(true){
    //popback is waiting for a new element to be available in queue
    Vehicle v=queue->popback();
    std::cout << "Vehicle# " <<v.getID()<<" has been removed from queue "<< '\n';
  }
  return 0;
}
