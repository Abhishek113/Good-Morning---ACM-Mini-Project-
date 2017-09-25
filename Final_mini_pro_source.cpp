#include<iostream>
#include<iomanip>
using namespace std;
#include"Final_mini_pro.h"
#include"Final_mini_pro_impl.cpp"

int main()
{
    MicroWaveoven m;
	int ch,flag=0;
	while(ch!=0)
	{
		m.creatKeyboard();
		int n;
		cout<<"\n input : \n";
		cin>>n;
		if(n<=0)
		{
			cout<<"\n trying to enter zero...\n";
		}
		else
		{
			int num[n];
			for(int i=0;i<n;i++)
			{
        			cin>>num[i];
			}
                    cout<<"\n output :";
    				for(int i=0;i<n;i++)
                    {
                        if(num[i]>=1&&num[i]<=200)
                            {
                                cout<<"\n";
                                m.checkNumber(num[i]);
                            }
                        else
                            cout<<"\n\nSorry "<<num[i]<<" is invalid input...please check the given condition\n\n\t\t( 1<=k<=200 )\n\n";
                    }
		}
		cout<<"\n Do you want to continune?..\n\n (press 0 to exit..and 1 key to continue..)";
			cin>>ch;

	}
return 0;
}

