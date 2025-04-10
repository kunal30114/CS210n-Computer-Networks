#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int WINDOW_SIZE = 4;
const int TOTAL_FRAMES = 10;

struct Frame {
    int id;
    bool acknowledged;
};

void transmitFrame(Frame &frame) {
    cout << "Transmitting frame " << frame.id << "...\n";
    int chance = rand() % 10; 
    if (chance < 2) {
        cout<<"Timeout !! Frame Lost...."<<endl;
        cout << "Frame " << frame.id << " lost during transmission!\n";
        return;
    }
    frame.acknowledged = false;
    cout << "Frame " << frame.id << " successfully transmitted." << endl;
}

bool checkAck(Frame &frame) {
    int chance = rand() % 10; 
    if (chance < 2) {
        cout << "ACK for frame " << frame.id << " lost!\n";
        return false;
    }
    frame.acknowledged = true;
    cout << "ACK received for frame " << frame.id << endl;
    return true;
}

int main() {
    srand(time(0));
    vector<Frame> window;
    int frameIndex = 0;

    while (frameIndex < TOTAL_FRAMES || !window.empty()) {
        while (window.size() < WINDOW_SIZE && frameIndex < TOTAL_FRAMES) {
            Frame frame = {frameIndex, false};
            transmitFrame(frame);
            window.push_back(frame);
            frameIndex++;
        }
        
        for (auto it = window.begin(); it != window.end();) {
            if (!it->acknowledged && checkAck(*it)) {
                it = window.erase(it);
            } else {
                ++it;
            }
        }
        sleep(1);
    }
    
    cout << "All frames successfully transmitted and acknowledged!\n";
    return 0;
}
