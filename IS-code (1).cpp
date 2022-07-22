#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0;

class Aditi 
{
    char roomNum[5], host[10], startTime[5], endTime[5], from[10], to[10], chairNum[6][6][10];

public:
  void hosting();
  void allotment();
  void checkIfEmpty();
  void show();
  void position(int i);
  void roomsAvailable();
}
room[10];

void vline(char ch)
{
  for (int i=0;i<60;i++)
  cout<<ch;
}

void Aditi::hosting()
{
  cout<<"Please select a room number: ";
  cin>>room[p].roomNum;
  cout<<"\nEnter host name: ";
  cin>>room[p].host;
  cout<<"\nStarting time: ";
  cin>>room[p].startTime;
  cout<<"\nEnding time: ";
  cin>>room[p].endTime;
  cout<<"\nFrom: ";
  cin>>room[p].from;
  cout<<"\nTo: ";
  cin>>room[p].to;
  room[p].checkIfEmpty();
  p++;
}

void Aditi::allotment()
{
  int c;
  char number[5];

  goUp:
  cout<<"Enter the room number you like: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(room[n].roomNum, number)==0)
    break;
  }

  while(n<=p)
  {
    cout<<"\nEnter the chair number you would prefer: ";
    cin>>c;
    if(c>36)
    {
      cout<<"\nPlease enter a number less than or equal to 36: ";
    }
    else
    {
      if (strcmp(room[n].chairNum[c/6][(c%6)-1], "Empty")==0)
      {
        cout<<"Kindly enter your name: ";
        cin>>room[n].chairNum[c/6][(c%6)-1];
        cout << "Congratulations!! Your chair is booked\n";
        break;
      }
      else
      {
        cout<<"This chair is already reserved.\n";
      }
    }

    if(n>p)
    {
      cout<<"Please, enter a correct room  number \n";
      goto goUp;
    }
  }
}

void Aditi::checkIfEmpty()
{
  for(int i=0; i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
      strcpy(room[p].chairNum[i][j], "Empty");
    }
  }
}

void Aditi::show()
{
  int n;
  char num[5];
  cout<<"Please enter your room number: ";
  cin>>num;
  for(n=0;n<=p;n++)
  {
    if(strcmp(room[n].roomNum, num)==0)
    break;
  }
  while(n<=p)
  {
    vline('*');
    cout<<"\nRoom no: "<<room[n].roomNum
    <<"\nHost: "<<room[n].host
    <<"\nStart time: "<<room[n].startTime
    <<"\nEnd time: "<<room[n].endTime
    <<"\nFrom: "<<room[n].from
    <<"\nTo: "<<room[n].to;
    cout << endl;
    vline('*');
    room[0].position(n);
    int a=1;
    for (int i=0; i<6; i++)
    {
      for(int j=0;j<6;j++)
      {
        a++;
        if(strcmp(room[n].chairNum[i][j],"Empty")!=0)
        cout<<"\nThe chair number "<<(a-1)<<" is reserved for "<<room[n].chairNum[i][j]<<".";
      }
    }
  break;
  }

  if(n>p)
  {
    cout<<"Please enter a correct room number: ";
  }
}

void Aditi::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<6;i++)
  {
    cout<<"\n";
    for (int j = 0;j<6; j++)
    {
      s++;
      if(strcmp(room[l].chairNum[i][j], "Empty")==0)
        {
          cout.width(5);
          cout<<s<<".";
          cout.width(10);
          cout<<room[l].chairNum[i][j];
          p++;
        }
        else
        {
          cout.width(5);
          cout<<s<<".";
          cout.width(10);
          cout<<room[l].chairNum[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" chairs empty in room number "<<room[l].roomNum;
  }
  
void Aditi::roomsAvailable()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"\nRoom no: "<<room[n].roomNum
    <<"\nHost: "<<room[n].host
    <<"\nStart time: "<<room[n].startTime
    <<"\nEnd  Time: "<<room[n].endTime
    <<"\nFrom: "<<room[n].from
    <<"\nTo: "<<room[n].to<<"\n\n";
    vline('*');
    cout << endl;
  }
}

int main()
{
  int a;
  while(1)
  {
    cout<<"\n\n";
    cout<<"\tPress 1 for hosting\n"
    <<"\tPress 2 for reserving your chair\n"
    <<"\tPress 3 to view details\n"
    <<"\tPress 4 to check availibilty of rooms\n"
    <<"\tPress 5 to exit console"
    <<"\n\n\tEnter the number of your choice: ";
    cin>>a;
  
    switch(a)
    {
      case 1:  room[p].hosting();
      break;
      case 2:  room[p].allotment();
      break;
      case 3:  room[0].show();
      break;
      case 4:  room[0].roomsAvailable();
      break;
      case 5:  exit(0);
    }
  }
  return 0;
}





