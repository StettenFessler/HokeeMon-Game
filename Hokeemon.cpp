#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

// Specification C2- Virtual Class Creature
class Creature
{
  public:
    int hungerStat; // tracks hunger
    int boreStat;   // tracks boredom
    int reducer;    // reduces hunger or boredom when played with/ fed
    int happyCount; // counts how many time Hokeemon was happy
    string name;
    
    void menu();
    void listener();
    void player();
    void feeder();
    void passTime();
    void getName();
};

// Specification C3- Child Class
class Hokee1 : public Creature
{
  public:
    Hokee1()
    {
       hungerStat = rand() % 6;
       boreStat = rand() % 6;
    }
};

// Specification B3- Second Child Class
class IgnoredChild : public Creature
{
  public:
    IgnoredChild()
    {
      hungerStat = rand() % 6;
      boreStat = rand() % 6;
    }
};

int main() 
{
  srand (time(NULL));
  bool play;
  int choice;
  Hokee1 main;
  
  cout << "Welcome to the Hokeemon Game! In this game you will have your\n";
  cout << "very own Hokeemon. You must play with it and feed it to keep it alive\n\n"; 
  cout << "If your Hokeemon's hunger is greater than 10, it will die." << endl;
  cout << "If your Hokeemon's boredom is greater than 20, it will slip into an unresponsive state\n";
  cout << "ENTER ANY KEY TO CONTINUE" << endl;
    cin.ignore();
// Specification A1- Critter Name
  cout << "Enter your Hokemon's name: " << endl;
    cin.ignore();
    getline(cin, main.name);

  while (play == false)
  {
  cout << "============================================" << endl;
  cout << "Select an Option:" << endl;
  cout << "1. Listen (displays hunger & boredom levels) " << endl; 
  cout << "2. Play (reduces boredom)" << endl;
  cout << "3. Feed (reduces hunger) " << endl;
  cout << "4. Quit" << endl;;
  cout << "============================================" << endl;
    cin >> choice;

  if (choice == 1)
  {
    main.listener();
    main.passTime();
    play = false;
  }
  else if (choice == 2)
  {
    main.player();
    main.passTime();
    play = false;
  }
  else if (choice == 3)
  {
    main.feeder();
    main.passTime();
    play = false;
  }
  else if (choice == 4)
    exit(0);
// Specification B1- Validate Input
  else
  {
    cout << "Incorrect input, please enter 1- 4" << endl;
      cin >> choice;
  }
  }
}
// Specification C1- PassTime()
void Creature::passTime()
{
  hungerStat += 1;
  boreStat += 1;
// Checks if Hokeemon starved
  if (hungerStat > 10) 
  {
    cout << "\n************************************" << endl;
    cout << name << " starved to death! Game over." << endl;
    cout << "**************************************" << endl;
    exit(0);
  } 
// Checks if Hokeemon is unresponsive
  if (boreStat > 20) 
  {
    cout << "\n*********************************************************************" << endl;
    cout << name << " has slipped into an unresponsive catatonic state. Game over." << endl;
    cout << "*********************************************************************" << endl;
    exit(0);
  }
  
}
// Displays the creature's hunger and boredom levels
void Creature::listener()
{
  cout << "\n-----------------------------------------" << endl;
  cout << name << "'s hunger level is " << hungerStat << endl;
// Specification B2- Moods
  if (boreStat >= 0 && boreStat <= 4)
  {
    happyCount++;
    cout << name << "'s boredom level is " << boreStat << endl;
    cout << name << " is happy!" << endl;
    cout << name << " has been happy for " << happyCount << " total turns :)" << endl;
    
  }

  else if (boreStat >= 5 && boreStat <= 9)
  {
    cout << name << "'s boredom level is " << boreStat << endl;
    cout << name << " is feeling OK." << endl;
  }

  else if (boreStat >= 10 && boreStat <= 14)
  {
    cout << name << "'s boredom level is " << boreStat << endl;
    cout << name << " is frustrated... play with your Creature!" << endl;
  }

  else if(boreStat > 15)
  {
    cout << name << "'s boredom level is " << boreStat << endl;
    cout << name << " is mad, you really need to play with your play with your Creature!" << endl;
  }
  cout << "-----------------------------------------" << endl;
}

// Reduces the creature's boredom when it is played with
void Creature::player()
{
  reducer = 4;
  //  Boredom cannot be < 0
  if (reducer >= boreStat) 
  {
    reducer = boreStat;
    boreStat -= reducer;
  }
  else 
  {
    reducer = 4;
    boreStat -= reducer;
  }
  cout << "You played with " << name << "!" << endl;
  cout << name << "'s boredom was decreased by " << reducer << endl;
}

// Reduces the creature's hunger when it is fed. 
void Creature::feeder()
{
  reducer = 4;
  // Hunger cannot be < 0
  if (reducer >= hungerStat) 
  {
    reducer = hungerStat;
    hungerStat -= reducer;
  }
  else 
  {
    reducer = 4;
    hungerStat -= reducer;
  }
  cout << "You fed " << name << "!" << endl;
  cout << name << "'s hunger was decreased by " << reducer << endl;
}
