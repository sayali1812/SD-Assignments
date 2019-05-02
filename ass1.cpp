/*
@author: rj
Topic: Set operations
*/

#include<iostream>
#define max 30
using namespace std;

void create(int set[])
{
    int n;
    cout << "How many elements you want to enter in set : ";
    cin >> n;
    set[0]=n;
    for(int i=1;i<=n;i++)
    {
        cin >> set[i];
    }
}

int member(int set[],int x)
{
    int n = set[0];
    for(int i=1;i<=n;i++)
    {
        if(x == set[i])
            return 1;
    }
    return 0;
}

void display(int set[])
{
    int n = set[0];
    for(int i=1;i<=n;i++)
    {
        cout << set[i] << "\t";
    }
    cout << "\n";
}
void uni(int set1[],int set2[],int set3[])
{
    set3[0] = 0;
    int n = set1[0];
    for(int i=1;i<=n;i++)
    {
        set3[i] = set1[i];
    }
    set3[0] = n;
    n = set2[0];
    for(int i=1;i<=n;i++)
    {
        if(!member(set3,set2[i]))
        {
            set3[0]++;
            set3[set3[0]] = set2[i];
        }
    }
}

void intersection(int set1[],int set2[],int set3[])
{
    set3[0] = 0;
    int n = set1[0];
    for(int i=1;i<=n;i++)
    {
        if(member(set2,set1[i]))
        {
            set3[0]++;
            set3[set3[0]] = set1[i];
        }
    }
}

void difference(int set1[],int set2[],int set3[])
{
    set3[0] = 0;
    int n = set1[0];
    for(int i=1;i<=n;i++)
    {
        if(!member(set2,set1[i]))
        {
            set3[0]++;
            set3[set3[0]] = set1[i];
        }
    }
}

void subset(int set1[],int set2[])
{
    int count;
    int n = set2[0];
    for(int i=1;i<=n;i++)
    {
        if(member(set1,set2[i]))
        {
            count++;
        }
    }
    if(count == set2[0])
        cout << "\nSET 2 is a subset of SET 1"<<endl;
    else
        cout << "\nSET 2 is not a subset of SET 1"<<endl;
}

void add_elem(int set[])
{
    int val;
    cout << "\nEnter the element you want to add : ";
    cin >> val;
    set[0]++;
    set[set[0]] = val;
}

void remove(int set[])
{
	int del,i;
	int n = set[0];
	cout << "\nEnter the element which you want to delete from the set : ";
	cin >> del;
	for(i=1;i<=n;i++)
	{
		if(set[i] == del)
	    	break;
	}
	if(i<=n)
	{
		set[0] -= 1;
		n = set[0];
		for(int j=i;j<=n;j++)
		{
			set[j]=set[j+1];
		}
	}
	else
		cout << "\nElement is not present in the set.."<<endl;
}

void search(int set[])
{
	int key;
	cout << "\nEnter the element you want to search in the set : ";
	cin >> key;
	if(member(set,key))
		cout << "\nElement is present in the list..." <<endl;
	else
		cout << "\nElement is not presnt in the list..." <<endl;
}

int main()
{
int set1[max],set2[max],set3[max];
int r;
cout << ".......SET OPERATIONS......"<<endl;
int ch;
do{
    cout << "\nMENU:-\n1.CREATE\n2.DISPLAY\n3.UNION\n4.INTERSECTION\n5.DIFFERENCE\n6.SUBSET\n7.ADD NEW ELEMENT\n8.REMOVE AN ELEMENT\n9.SEARCH AN ELEMENT\n10.SIZE OF SET\n11.EXIT"<<endl;
    cout << "Enter ur choice : ";
    cin >> ch;
    switch(ch)
    {
        case 1 : cout << "SET 1 :";
                 create(set1);
                 cout << "SET 2 :";
                 create(set2);
                 break;
        case 2 : cout << "\nDisplaying SET 1 : ";
                 display(set1);
                 cout << "\nDisplaying SET 2 : ";
                 display(set2);
                 break;
        case 3 : cout << "\nUnion of two sets :-"<<endl;
                 uni(set1,set2,set3);
                 display(set3);
                 break;
        case 4 : cout << "\nIntersection of two sets :-"<<endl;
                 intersection(set1,set2,set3);
                 display(set3);
                 break;
        case 5 : cout << "\nDifference of two sets :-"<<endl;
                 difference(set1,set2,set3);
                 display(set3);
                 break;
        case 6 : cout << "\nChecking subset : "<<endl;
                 subset(set1,set2);
                 break;
        case 7 : cout << "\nIn which set you want to add element? set1 or set2 : ";
                 cin >> r;
                 if(r==1)
		 		 {
                     add_elem(set1);
                     display(set1);
		    	 }
                 else
		 		 {
                     add_elem(set2);
                     display(set2);
				 }
                 break;
		case 8 : cout << "\nOn which set you want to perform this operation ? set1 or set2 : ";
                 cin >> r;
				 if(r==1)
		 		 {
                     remove(set1);
                     display(set1);
		    	 }
                 else
		 		 {
                     remove(set2);
                     display(set2);
				 }
                 break;
		case 9 : cout << "\nOn which set you want to perform this operation ? set1 or set2 : ";
                 cin >> r;
				 if(r==1)
		 	     	search(set1);
                 else
                     search(set2);
                 break;
		case 10 : cout << "\nSize of SET 1 is : " << set1[0] <<endl;
	 		      cout << "\nSize of SET 2 is : " << set2[0] <<endl;
        case 11 : cout << "\nExiting the program....!!!!"<<endl;break;
        default : cout << "\nPlease choose appropriate option....."<<endl;
    }
}while(ch!=11);

return 0;
}
