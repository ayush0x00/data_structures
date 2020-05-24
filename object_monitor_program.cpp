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
  void printId(){
    std::lock_guard<std::mutex> lock(_mtx);
    for(auto &v:_vehicles){
      std::cout << "Vehicle# " <<v.getID()<<" is now waiting in the queue"<< '\n';
    }
  }

  void pushback(Vehicle &&v){
    std::lock_guard<std::mutex> ulock(_mtx);
    std::cout << "Vehicle# " <<v.getID()<<" will be added to the queue " <<'\n';
    _vehicles.emplace_back(std::move(v));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));//for checking data races
  }
private:
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
  queue->printId();
  return 0;
}
