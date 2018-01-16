#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>

fstream f,ftemp;

class Details
{
    public:
	    int RoomNo;
	    char CName[20];
	    long int CMobNo;
}d,dtemp;

void Insert()
{
    int inserted=0, first=1, closedi=0;
    f.open("data.txt",ios::in);
    ftemp.open("temp.txt",ios::out);
    cout<< endl <<"Enter Room No. : ";
    cin>>dtemp.RoomNo;
    if(dtemp.RoomNo>=101 && dtemp.RoomNo<=110)
    {
       cout<< "Enter Customer's Name : ";
       gets(dtemp.CName);
       cout<< "Enter Customer's Mobile No. : ";
       cin>>dtemp.CMobNo;
       while(f.read((char*)&d,sizeof(d)))
       {
	    first=0;
	    if(d.RoomNo==dtemp.RoomNo)
	    {
		    cout<<"Room Already Full";
	    }
	    else if(d.RoomNo>dtemp.RoomNo && inserted==0)
	    {
		ftemp.write((char*)&dtemp,sizeof(dtemp));
		ftemp.write((char*)&d,sizeof(d));
		inserted=1;
	    }
	    else
	    {
	      ftemp.write((char*)&d,sizeof(d));
	    }
       }
       if(first==1)
       {
	    ftemp.write((char*)&dtemp,sizeof(dtemp));
       }
       ftemp.close();
       f.close();
       remove("data.txt");
       rename("temp.txt","data.txt");
       closedi=1;
    }
   else
    {
	cout<<"No such room in the Hotel.";
    }
    if(closedi==0)
    {
	f.close();
	ftemp.close();
    }
}

void Modify()
{	
    f.open("data.txt",ios::in);	
    f.seekg(0);
    int modified=0, closedm=0;
    char surem;
    ftemp.open("temp.txt",ios::out);
    cout<<"Modify Details of Room No. : ";
    cin>>dtemp.RoomNo;
    if(dtemp.RoomNo>=101 && dtemp.RoomNo<=110)
    {
       cout<< "Enter Customer's Name : ";
       gets(dtemp.CName);
       cout<< "Enter Customer's Mobile No. : ";
       cin>>dtemp.CMobNo;
       while(!f.eof())
       {
	    f.read((char*)&d,sizeof(d));
	    if(d.RoomNo==dtemp.RoomNo)
	    {
		cout<< "Are you sure you want to modify? (Y/N) : ";
		cin>>surem;
		modified=1;
		if(surem=='Y' || surem=='y')
		{
		    cout<< "Modifying...";
		    ftemp.write((char*)&dtemp,sizeof(dtemp));
		}
		else
		{
		    if(surem!='N' || surem!='n')
		    {
			cout<< "Invalid Input.";
		    }
		    else
		    {
			ftemp.write((char*)&d,sizeof(d));
		    }
		}
	    }
	    else
	    {
		ftemp.write((char*)&d,sizeof(d));
	    }
       }
       if(modified==0)
       {
	   cout<< "The Room is empty.";
       }
       f.close();
       ftemp.close();
       remove("data.txt");
       rename("temp.txt","data.txt");
       closedm=1;	
    }
    else
    {
	cout<<"No such room in the Hotel.";
    }
    if(closedm==0)
    {
    	f.close();
    	ftemp.close();
    }
}

void Delete()
{   
    f.open("data.txt",ios::in);			
    f.seekg(0);
    int notfound=1, closedd=0;
    char sured;
    ftemp.open("temp.txt",ios::out);
    cout<< "Details to be deleted of Room No. : ";
    cin>>dtemp.RoomNo;
    if(dtemp.RoomNo>=101 && dtemp.RoomNo<=110)
    {   while(!f.eof())
	{
	    f.read((char*)&d,sizeof(d));
	    if(dtemp.RoomNo!=d.RoomNo)
	    {
		ftemp.write((char*)&dtemp,sizeof(dtemp));
	    }
	    else
	    {
		cout<< "Are you sure you want to delete? (Y/N) : ";
		cin>>sured;
		notfound=0;
		if(sured=='Y' || sured=='y')
		{
			cout<< "Deleting...";
		}
		else
		{
		    if(sured!='N' || sured!='n')
		    {
			cout<< "Invalid Input.";
		    }
		    else
		    {
			ftemp.write((char*)&d,sizeof(d));
		    }
		}
	    }
	}
	if(notfound==1)
	{
	    cout<< "The room is already empty.";
	}
    f.close();
    ftemp.close();
    remove("data.txt");
    rename("temp.txt","data.txt");
    closedd=1; 
    }
    else
    {
	cout<< "No such room in the Hotel.";
    }
    if(closedd==0)
    {
	f.close();
	ftemp.close();
    }	
}

void Search()
{
    f.open("data.txt",ios::in);
    f.seekg(0);
    int found=0;
    cout<< "Details required of Room No. : ";
    cin>>dtemp.RoomNo;
    if(dtemp.RoomNo>=101 && dtemp.RoomNo<=110)
    {
	while(!f.eof())
	{
	    f.read((char*)&d,sizeof(d));
	    if(dtemp.RoomNo==d.RoomNo)
	    {
		cout<< "Room No. : "<< d.RoomNo << endl << "Customer's Name : ";
		puts(d.CName);
		cout<< endl << "Customer's Mobile No. : " << d.CMobNo;
		found=1;
            }
        }
        if(found==0)
        {
            cout<< "The Room is empty.";
        }
    }
    else
    {
        cout<< "No such room in the Hotel.";
    }
    f.close();		
}

int main()
{
    int choice=0;
    f.open("data.txt",ios::in);
    if(!f)
    {
	f.close();
	f.open("data.txt",ios::out);
	f.close();
	f.open("data.txt",ios::in);
    }
    f.close();
    while(choice!=5)
    {
	cout << "MENU" << endl << "1. Insert Record" << endl << "2. Modify Record" << endl << "3. Delete Record" << endl << "4. Show Records" << endl << "5. Exit" << endl << "Choice : ";
	cin >> choice;
	switch(choice)
	{
	    case 1: Insert();
		    break;
	    case 2: Modify();
		    break;
	    case 3: Delete();
		    break;
	    case 4: Search();
		    break;
	    case 5: cout<< "Thank You for using the Utility!";
		    break;
	    default: cout<<"Invalid Input";
	}
	cout<<endl<<endl;
    }
    return 0;
}
