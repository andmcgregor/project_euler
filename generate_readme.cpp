#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <chrono>

bool fileExists(std::string filename)
{
  std::ifstream infile(filename.c_str());
  return infile.good();
}

void compile(std::string filename)
{
  system((std::string("g++ --std=c++11 ") + filename).c_str());
}

std::string run(std::string filename)
{
  // Run program and save output to string (http://stackoverflow.com/a/478960/1386324)
  char buffer[128];
  std::string result = "";
  std::shared_ptr<FILE> pipe(popen("./a.out", "r"), pclose);
  if (!pipe) throw std::runtime_error("popen() failed!");
  while (!feof(pipe.get())) {
    if (fgets(buffer, 128, pipe.get()) != NULL)
      result += buffer;
  }

  result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());

  return result;
}

int main(int argc, char** argv)
{
  std::ofstream readme;
  std::string filename, prefix;
  std::string readmeContents;

  readmeContents += "#Project Euler\n| Problem | Result | Execution Time |\n| --- | --- | --- |\n";

  for (int i = 1; i < 1000; i++) {
    if (i < 10)
      prefix = "00";
    else if (i < 100)
      prefix = "0";
    else
      prefix = "";

    filename = prefix + std::to_string(i) + ".cpp";

    if (fileExists(filename)) {
      compile(filename);

      auto start_time = std::chrono::high_resolution_clock::now();

      std::string result = run(filename);

      auto current_time = std::chrono::high_resolution_clock::now();

      double elapsed = double(std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count()) / 1000.0;

      readmeContents += "| Problem " + std::to_string(i) + " | " + result + " | " + std::to_string(elapsed) + "|\n";
    }
  }

  readme.open("README.md", std::ofstream::out | std::ofstream::trunc);
  readme << readmeContents;
  readme.close();

  return 0;
}

