#include<iostream>
#include<iomanip>
using namespace std;
void MicroWaveoven::creatKeyboard(void)
{
    int r,c;
    int d=1;
    for(r=0;r<=3;r++)
    {
        for(c=0;c<=2;c++)
        {
            keyBoard[r][c]=d;
            d++;
        }
    }
    keyBoard[3][1]=0;
	keyBoard[3][0]=10;
	keyBoard[3][2]=10;
    adjMat();
}
void MicroWaveoven::adjMat(void)
{
    for(int r=0;r<10;r++)
    {
        for(int c=0;c<10;c++)
        {
            bool flag=0;
            flag = checkIndex(r,c);
            if(flag==1)
                adjkeyboard[r][c]=1;
            else
                adjkeyboard[r][c]=0;
        }
    }

}
bool MicroWaveoven::checkIndex(int num1,int num2)
{
    int a,b,r1,c1;
    for(int r=0;r<=3;r++)
    {
        for(int c=0;c<=2;c++)
        {
            if(keyBoard[r][c]==num1)
            {
                a=r;b=c;
                break;
            }
        }
    }
     for(int r=0;r<=3;r++)
    {
        for(int c=0;c<=2;c++)
        {
            if(keyBoard[r][c]==num2)
            {
                r1=r;c1=c;
                break;
            }
        }
    }
    if(r1<a||c1<b)
        return 0;
    else
        return 1;
}


void MicroWaveoven::checkNumber(int n)
{
	int d1,d2,d3;
	k=n;
	if(k>=1&&k<=200)
	{
		if(k>=100)
		{
			d1=k%10;
			k=k/10;
			d2=k%10;
			k=k/10;
			d3=k%10;
			k=n;
			if(adjkeyboard[d3][d2]==1)
			{
				if(adjkeyboard[d2][d1]==1)
				{
					cout<<"\n"<<k;
				}
				else
				{
					findNumbers(d2,d1);
				}
			}
		}
		else
		{
            if(10<=k&&k<=99)
		    {
                d1=k%10;
                k=k/10;
                d2=k%10;
                k=n;
                if(adjkeyboard[d2][d1]==1)
                {
                    cout<<"\n"<<k<<"\n";
                }
                else
                {
                    findNumbers(d2,d1);
                }
            }k=n;
		}
		if(k<10)
			cout<<"\n"<<k;

	}
	else
	{
		cout<<"\n"<<"sorry you number is out of range..1<=k<=200";
	}

}
void MicroWaveoven::findNumbers(int d2,int d1)
{
	int arr[10],check=d2,i=0,d3,x;
	do
	{
		for(int c=check;c<=9;c++)
		{
			if(adjkeyboard[d2][c]==1)
			{
				arr[i]=c;
				i++;
			}
		}
		if(adjkeyboard[d2][0]==1)
		{
			arr[i]=0;
			i++;
		}

		arr[i]=100;
	}while(arr[i]!=100);
	//for(i=0;arr[i]!=100;i++)
		//cout<<arr[i]<<"\n";

	int sub[10],j=0,z;
	i=0;
	//for(j=0;j!=10;j++)
		//sub[j]=0;

	int temp;
	do
	{
		 int k1=0;
		do
		{
			if(d1>arr[k1])
			{
				temp=d1-arr[k1];
			}
			else
			{
				temp = arr[k1]-d1;
			}
			sub[j]=temp;
			j++;
			k1++;
		}while(arr[k1]!=100);sub[j]=200;
	}while(sub[j]!=200);
	//for(j=0;sub[j]!=200;j++)
		//cout<<"\n"<<sub[j];
	for(i=0;sub[i]!=200;i++)
	{

		for(j=i+1;sub[j]!=200;j++)
		{
			if(sub[i]>sub[j])
			{
				temp=sub[j];
				sub[i]=sub[j];
				sub[j]=temp;
			}
		}
	}
	//for(i=0;sub[i]!=200;i++)
		//cout<<"\n"<<sub[3];
	z=k+sub[0];

	x=z;
	if(z>=1&&z<=200)
	{
		if(z>=100)
		{
			d1=z%10;
			z=z/10;
			d2=z%10;
			z=z/10;
			d3=z%10;
			z=x;
			if(adjkeyboard[d3][d2]==1)
			{
				if(adjkeyboard[d2][d1]==1)
				{
					cout<<"\n"<<z;
				}
				else
				{
					z=k-sub[0];
					cout<<"\n"<<z;
				}
			}
		z=x;
		}
		else if(10<=z&&z<=99)
		{
			d1=z%10;
			z=z/10;
			d2=z%10;
			z=x;
			if(adjkeyboard[d2][d1]==1)
			{
				cout<<"\n"<<z<<"\n";
			}
			else
			{
				z=k-sub[0];
				cout<<"\n"<<z;
			}

		}
	}
}

