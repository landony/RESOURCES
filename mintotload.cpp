/*
NAME : LW.Y
LUID : L20305910
COURSE : COSC 5313 ANALYSIS OF ALGORITHMS
PROGRAM : MINIMUM TOTAL LOAD
DUE DATE : 03/26/2014
PROGRAM NAME: mintotload.cpp

Program Description: This program must use only one optimal topological ordering in finding the Maximum Restrictive Cutset.

Programming Language: C++

Program Compilation : To compile the program on unix machine use command
g++ mintotload.cpp

Program Run: ./a.out

Program Completeness: Program is complete and without any bugs. It is running properly.

Task:
		Consider the following Flow Network:
		(1,2,10)
		(1,3,20)
		(1,4,12)
		(2,5,14)
		(3,5,10)
		(4,3,6)
		(4,6,16)
		(4,7,14)
		(5,6,11)
		(5,7,12)
		(6,7,15)
Note that each triple represents a weighted edge such that
the first number is the originating node, the second
the terminating node and the third its weight.


Write a well-structured program that does the following:
1. Find and print all topological orderings of nodes of the input Flow Network.

2. Find and print out an Optimal topological ordering.

3. Compute a Maximum Restrictive Cutset (which represents Minimum Total Load) and print out all its nodes.

4. And, print out the value of the Minimum Total Load itse

Requirement:
1. For the efficiency purpose, your program must use only one optimal topological ordering in finding the Maximum Restrictive Cutset.
2. If unable to use only one topological ordering, your program
must indicate so in the BEGINNING comments.

*/

#include<iostream>
#include<fstream>
using namespace std;

void ordergr(int arr[7][7],int no_of_high1,int vertex[7],int low);
void calld(int arr[7][7]);
void totminld(int arr[7][7],int vertex[7]);
int cked(int arr[7][7],int val[7]);
//int nodeState(int arr,int val[7]);
//int checkList(int vertex,int sa,int z);


////////////////////////////////////////////////////////////////////////////

void calld(int arr[7][7])
{
	int high1;	//vertex is ordering, ver is  vertex with no incoming edge
	int val[7];		//vertex of vertices with no incoming edges
	int minst[7];		//minst of corresponding vertices in val 1=moreout,0=balanced,-1=morein
	int x,y;
	int g1[7][7];
	int low=0;
	int vertex[7];
	int removend;
	for(int v=0;v<7;v++)
		for(int z=0;z<7;z++)
			g1[v][z]=arr[v][z];
	while(low!=7)
	{
		high1=cked(arr,val);
		if(high1>1)
		{
			for(x=0;x<high1;x++)
				minst[x]=nodeState(arr,val[x]);
			for(x=0;x<high1;x++)
				if(minst[x]==1)
					break;
			if(x<high1)
				removend=val[x];
			else
			{
				for(x=0;x<high1;x++)
					if(minst[x]==0)
						break;
				if(x<high1)
					removend=val[x];
				else
				{
					for(x=0;x<high1;x++)
						if(minst[x]==-1)
							break;
					if(x<high1)
						removend=val[x];
				}
			}
			vertex[low++]=removend;
			for(y=0;y<7;y++)
				arr[removend][y]=0;
			arr[removend][removend]=-1;
		}
		else
		{
			vertex[low++]=val[0];
			for(y=0;y<7;y++)
				arr[val[0]][y]=0;
			arr[val[0]][val[0]]=-1;
		}
	}
	cout<<"\nAn Optimal topological ordering is:\n";
	for(int x=0;x<7;x++)
	{
		cout<<vertex[x]+1;
		if(x!=6)
			cout<<"->";
	}
	cout<<endl;
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	totminld(g1, vertex);
}

////////////////////////////////////////////////////////////////////////////
int cked(int arr[7][7],int val[7])
{
	int x,y,high1=0;
	for(x=0;x<7;x++)
	{
		for(y=0;y<7;y++)
		{
			if(arr[y][x]!=0)
				break;
		}
		if(y==7)
			val[high1++]=x;
	}
	return(high1);
}

///////////////////////////////////////////////////////////////////////

void totminld(int arr[7][7],int vertex[7])
{
	int addition[7],max=-99999,maxIndex;
	int sa;
	int x,y,z,v;
	for(x=0;x<7;x++)
		addition[x]=0;
	cout<<"\nVertex  | Cutset\n";
	cout<<"--------+-------\n";
	for(x=0;x<7;x++)
	{
		sa=vertex[x];
		for(v=0;v<7;v++)
			addition[x]+=arr[sa][v];

		for(y=0;y<x;y++)
		{
			for(z=0;z<7;z++)
			{
				if(checkList(vertex,sa,z))
				addition[x]+=arr[vertex[y]][z];
			}

		}
		cout<<x+1<<"	   | "<<addition[x]<<endl;
	      if(addition[x]>max)
		max=addition[x];
	}
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\nMinimum Total Load value is =  "<<max<<"\n\n\n";
}

int main()
{
	int arr[7][7],vertex[7];
	int as1,as2;
	int x,y;
	ifstream is;
	is.open("input.txt");
	for(x=0;x<7;x++)
		for(y=0;y<7;y++)
			arr[x][y]=0;
	for(x=0;x<11;x++)
	{
		is>>as1>>as2;
		is>>arr[as1-1][as2-1];
	}
	is.close();
	cout<<"\rShowing input in 2D array\n";
	for(int x=0;x<7;x++)
	{
		cout<<endl;
		for(int y=0;y<7;y++)
			cout<<arr[x][y]<<"\t";
	}
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\nInput Flow Network for all topological orderings of nodes are:\n";
	ordergr(arr,7,vertex,0);
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	calld(arr);
	cout<<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

void ordergr(int arr[7][7],int no_of_high1,int vertex[7],int low)
{
	int high1; //vertex is ordering, high1 is  vertex with no incoming edge
	int val[7];		//vertex of vertices with no incoming edges
	int x,y;
	int g1[7][7];
	if(low==7)
	{
		for(int x=0;x<7;x++)
		{
			cout<<vertex[x]+1;
			if(x!=6)
				cout<<"-->";
		}
		cout<<endl;
		return;
	}
	high1=cked(arr,val);
	for(x=0;x<high1;x++)
	{
		for(int v=0;v<7;v++)
			for(int z=0;z<7;z++)
				g1[v][z]=arr[v][z];
		for(y=0;y<7;y++)
			g1[val[x]][y]=0;
		g1[val[x]][val[x]]=-1;
		vertex[low]=val[x];
		ordergr(g1,no_of_high1-1,vertex,low+1);
		vertex[low]=0;
	}
}
