#include<iostream>
#include<iomanip>
using namespace std;
class MicroWaveoven
{
    int keyBoard[4][3],k,adjkeyboard[10][10];

        void adjMat(void);
        bool checkIndex(int,int);
		void findNumbers(int,int);
    public:
        void creatKeyboard(void);
        void checkData(int);
		void checkNumber(int);

};
