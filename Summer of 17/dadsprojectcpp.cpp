#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double FARE =1.0;

class Passenger	{
public:
	double kms;
	double money;
	string name;
  int bit;

	Passenger()	{
		kms=0.0;
		money=0.0;
		name="";
		bit=0;
	}

  void embark()	{
    cout<<"Please enter name\n";
    cin>>name;
    kms=0.0;
    money=0.0;
    bit=1;
  }
	void deletes()	{
		name="";
		kms=0.0;
		money=0.0;
		bit=0;
	}
  void disembark()	{
    cout<<name<<" has travelled "<<kms<<" & must pay "<<money<<"\n";
    deletes();
  }
	void replace(Passenger y)	{
		kms=y.kms;
		money=y.money;
		name=y.name;
		bit=y.bit;
		cout<<"replace";
	}
};



class Cab	{
private:
  int i;
public:
  Passenger people[6];
  int index,no_of_passengers,dist;
	Cab()	{
		index=0;
		no_of_passengers=0;
	}

  void calc()	{
    cout<<"Enter number of kms travelled\n";
    cin>> dist;
    for(i=0;i<index;i++)	{
      people[i].kms+=dist;
			people[i].money+=(dist*FARE/no_of_passengers);
    }
  }
  void print()	{
		cout << "No Name				kms money" << '\n';
    for(i=0;i<6;i++)	{
      cout << i+1<< '\t'<<people[i].name<< "\t\t"<<people[i].kms<<'\t'<< people[i].money<<"\t"<<people[i].bit<<'\n';
    }
  }
  void get_on()	{
    int i=0,n=0;
    cout<<"How many will get on the cab?\n";
    cin >>n;

    if(index+n>6) {
      cout<<"INVALID TOO MANY";
      cout<<"How many will get on the cab?\n";
      cin >>n;
    }
    for(i=index;index<i+n;index++,no_of_passengers++)	{
        people[index].embark();
    }

  }
	void changing_array()	{
		int i=0,j=0;
		for(i=0;i<index;i++)
		{
			for(j=0;j<index-i-1;j++)	{
				if(people[j].bit==0)	{
					people[j].replace(people[j+1]);
					people[j+1].deletes();
					cout << "x" <<i<<j<< '\n';
				}
			}
		}
		index=no_of_passengers;
	}
  void get_off()	{
    int i,j,n=0;
    cout<<"How many will get off the cab?\n";
    cin >>n;
    if(index-n<0)	{
      cout<<"INVALID TOO MANY";
      cout<<"How many will get off the cab?\n";
      cin >>n;
    }
    print();
    for(i=0;i<n;i++)	{
        cout<<"Who will disembark?(Give serial no)";
        cin>>j;
        (people[j-1]).disembark();
				no_of_passengers--;
    }
		changing_array();
	}
};



int main(int argc, char const *argv[])	{
  Cab cab1;
	
  cab1.get_on();
  while(cab1.no_of_passengers!=0)	{
    cab1.calc();
    cab1.get_off();
    cab1.get_on();
  }

  return 0;
}
