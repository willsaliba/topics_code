#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <memory>
using namespace std;

string get_result_from_model(const char* cmd) {
    
    //open pipe to execute command & read its output
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    
    if (!pipe) printf("pipe failed to open");
    
    //read output from python code
    string result;
    array<char, 128> buffer;
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();  // Append buffer contents to result
    }
    
    return result;
}

int main() {

    string prompt = "Herbie Rapping";
    string action = "Generate";
    string randomness = "70";
    string filePath = "/Users/willsaliba/Documents/piano.wav";
    printf("Request Generated\n\n");

    //command to execute python code with args
    string cmd = "python3 theModel.py \"" + prompt + "\" \"" + action + "\" " + randomness + " \"" + filePath + "\"";

    //perform command & store result
    string newTrackPath = get_result_from_model(cmd.c_str());;

    //print response
    cout << "Response Recieved: " << newTrackPath << "\n\n";

    return 0;
}
