#include <iostream>
#include <ctime>
#define ll long long int
using namespace std;

void transmission(ll &i, ll &N, ll &tf)
{
  while (i <= tf)
  {
    int z = 0;
    for (int k = i; k < i + N && k <= tf; k++)
    {
      cout << "Sending Frame " << k << "..." << endl;
    }
    for (int k = i; k < i + N && k <= tf; k++)
    {
      int f = rand() % 2;
      if (!f)
      {
        cout << "Acknowledgment for Frame " << k << "..." << endl;
        z++;
      }
      else
      {
        cout << "Timeout!! Frame Number : " << k << " Not Received" << endl;
        cout << "Retransmitting Window..." << endl;
        break;
      }
    }
    cout << "\n";
    i = i + z;
  }
}

int main()
{
  ll tf, N = 0;
  srand(time(0));
  cout << "Enter the Total number of frames : ";
  cin >> tf;
  cout << "Enter the Window Size : ";
  cin >> N;
  ll i = 1;
  transmission(i, N, tf);

  return 0;
}