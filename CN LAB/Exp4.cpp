#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

bool sendPacket(int packet)
{

    if (rand() % 10 < 3)
    {
        cout << "Packet " << packet << " lost! Resending...\n";
        return false;
    }
    cout << "Packet " << packet << " sent successfully!\n";
    return true;
}

bool receiveAck(int packet)
{

    if (rand() % 10 < 2)
    {
        cout << "ACK for Packet " << packet << " lost! Resending packet...\n";
        return false;
    }
    cout << "ACK received for Packet " << packet << "!\n";
    return true;
}

int main()
{
    srand(time(0));

    int totalPackets = 5;
    int packet = 1;

    while (packet <= totalPackets)
    {
        bool sent = false, acked = false;

        while (!sent || !acked)
        {
            sent = sendPacket(packet);
            if (sent)
            {
                this_thread::sleep_for(chrono::milliseconds(500));
                acked = receiveAck(packet);
            }
            this_thread::sleep_for(chrono::milliseconds(500));
        }

        cout << "Packet " << packet << " successfully delivered.\n\n";
        packet++;
    }

    cout << "All packets successfully transmitted!\n";
    return 0;
}
