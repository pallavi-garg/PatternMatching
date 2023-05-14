#include <iostream>
#include <string>
#include <vector>

#include "project.h"
#include "reader.h"
#include <chrono>
#include <thread>

typedef std::chrono::time_point<std::chrono::system_clock> time_type;

int main()
{
  std::string textPath = "text.txt";
  std::string patternPath = "words.txt";

  std::string T;
  std::vector<std::string> patterns;
  filereader* reader = new filereader();
  reader->read_file_multiline(patternPath, patterns);
  reader->read_file(textPath, T);
  delete reader;

  std::vector<std::string> algos = {"kmp", "bmh", "brute", "bitap", "rk"};
  
  for(std::string algo : algos)
  {
    int index = -1;
    int counter = 10;

    for(std::string P : patterns)
    {
      time_type start_time;
      time_type calculated_at;
      if (algo == "kmp")
      {
        start_time = std::chrono::system_clock::now();
        index = kmp(T, P);
        calculated_at = std::chrono::system_clock::now();
      }
      else if (algo == "bmh")
      {
        start_time = std::chrono::system_clock::now();
        index = bmh(T, P);
        calculated_at = std::chrono::system_clock::now();
      }
      else if (algo == "brute")
      {
        start_time = std::chrono::system_clock::now();
        index = brute(T, P);
        calculated_at = std::chrono::system_clock::now();
      }
      else if (algo == "bitap") 
      {
        start_time = std::chrono::system_clock::now();
        index = bitap(T, P);
        calculated_at = std::chrono::system_clock::now();
      }
      else if (algo == "rk")
      {
        start_time = std::chrono::system_clock::now();
        index = rk(T, P);
        calculated_at = std::chrono::system_clock::now();
      }

      std::chrono::duration<double> elapsed_seconds = calculated_at - start_time;
      if (index != -1)
      {
        std::cout<<algo<<", " << index <<", "<< P <<", "<<P.length()<<", "<<elapsed_seconds.count() * 1000<<std::endl; 
        --counter;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      if(counter == 0)
        break;
    }
  }
  return 0;
}