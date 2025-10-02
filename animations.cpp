#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<math.h>
using namespace std;
const int max_column = 100;
const double pi = 3.14;
int R = 79, C = 208;
void MySleep(double n)
{
	for (;n < 100000;n += 0.1);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void DrawCirle(int Cr, int Cc, int r, char sym = -37)
{

	for (double t = 0; t <= 360; t++)
	{
		double  thita = t * pi / 180;
		int cr = r * sin(thita) + Cr;
		int cc = r * cos(thita) + Cc;
		gotoRowCol(cr, cc);
		cout << sym;

	}

}
void DrawSemiCircleD(int Cr, int Cc, int r, char sym = -37)

{

	for (double t = 0; t <= 180; t++)
	{
		double  thita = t * pi / 180;
		int cr = r * sin(thita) + Cr;
		int cc = r * cos(thita) + Cc;
		gotoRowCol(cr, cc);
		cout << sym;

	}

}
void DrawSemiCircleA(int Cr, int Cc, int r, char sym = -37)

{

	for (double t = 0; t <= 180; t++)
	{
		double  thita = t * pi / 180;
		int cr = r*(-1) * sin(thita) + Cr;
		int cc = r*-1 * cos(thita) + Cc;
		gotoRowCol(cr, cc);
		cout << sym;

	}

}
void CircleChRadius(int Cr, int Cc, char sym = -37)
{
	while (true)
	{
		for (int r = 1;r < Cr;r++)
		{
			DrawCirle(Cr, Cc, r);
			MySleep(200);
			DrawCirle(Cr, Cc, r, ' ');
		}
		for (int r = Cr - 1;r >= 1;r--)
		{
			DrawCirle(Cr, Cc, r);
			MySleep(200);
			DrawCirle(Cr, Cc, r, ' ');
		}
	}
}
void Cliff(int R,int C,char sym=-37)
{
	for (int i = 0;i < C/4;i++)
	{
		gotoRowCol(R/5, i);
		cout << sym;
	}
	for (int i = R/5;i < R;i++)
	{
		gotoRowCol(i, C / 4);
		cout << sym;
	}
	for (int i = C / 4;i < C;i++)
	{
		gotoRowCol(R-15,i);
		cout << sym;
	}
}
void PrintCartoon(int R,int C)
{
	gotoRowCol((R / 5) - 1, (C / 4) - 4);
	cout << "/ \\";
	gotoRowCol((R / 5) - 2, (C / 4) - 3);
	cout << "|";
	gotoRowCol((R / 5) - 3, (C / 4) - 4);
	cout << "\\O/";
}
void DrawRect(int Cr, int Cc, int s,char sym=-37)
{
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(Cr, Cc + i);
		cout << sym;
	}
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(Cr, Cc - i);
		cout << sym;
	}
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(Cr + i, Cc - s / 2);
		cout << sym;
	}
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(Cr + i, Cc + s / 2);
		cout << sym;
	}
	for (int i = 0;i <= s;i++)
	{
		gotoRowCol(Cr + s / 2, (Cc-s/2) + i);
		cout << sym;
	}
}
void Smiley1(int Cr, int Cc, char sym = -37)
{
	DrawCirle(Cr, Cc, 25);
	DrawCirle(Cr-13, Cc - 12,4);
	DrawCirle(Cr - 13, Cc + 12, 4);
	DrawSemiCircleD(Cr+5, Cc, 10);

}
void Smiley2(int Cr, int Cc, char sym = -37)
{
	DrawCirle(Cr, Cc, 25);
	DrawCirle(Cr - 10, Cc - 10, 6);
	DrawCirle(Cr - 10, Cc + 10, 6);
	DrawCirle(Cr, Cc , 3);
	DrawSemiCircleA(Cr - 10, Cc - 10, 9);
	DrawSemiCircleA(Cr - 10, Cc + 10, 9);
	DrawRect(Cr + 8, Cc, 16);
	

}
void DrawSpiral(int Cr, int Cc, int n, char sym = -37)
{
	float arminter = (R/2.0) / n;
	float delta = arminter / 360;
	for(float r=1;r<R/2;)
	for (double t = 0; t <= 360; t++)
	{
		double  thita = t * pi / 180;
		int cr = r * sin(thita) + Cr;
		int cc = r * cos(thita) + Cc;
		gotoRowCol(cr, cc);
		cout << sym;
		r += delta;
	}

}
void Wait(double n)
{
	for (;n < 100000000;n += 1);
}
void StoneThrowing(int R,int C,char sym=-37)
{
	int ir = (R / 5) - 3, ic = (C / 4) - 1;
	int v = 5;
	
	for (double t = 0;true;t += 0.01)
	{
		int pr = ir + 4.9 * t * t;
		int pc = ic + v * t;
		if (pr < R-15)
		{
			
			gotoRowCol(pr, pc);
			cout << sym;
			MySleep(1000);
			int ppr = pr, ppc = pc;
			gotoRowCol(ppr, ppc);
			cout << ' ';
		}
		else
		{
			gotoRowCol(pr-1, pc);
			cout << sym;
			break;
		}
		
	}
}
void StoneThrowingMany(int R, int C, char sym = -37)
{
	int ir = (R / 5) - 3, ic = (C / 4) - 1;
	int v[1000]={5,35,6,10,20};
	for (int i = 0;i < 5;i++)
	{
		for (double t = 0;true;t += 0.01)
		{
			int pr = ir + 4.9 * t * t;
			int pc = ic + v[i] * t;
			if (pr < R - 15)
			{

				gotoRowCol(pr, pc);
				cout << sym;
				MySleep(1000);
				int ppr = pr, ppc = pc;
				gotoRowCol(ppr, ppc);
				cout << ' ';
			}
			else
			{
				gotoRowCol(pr - 1, pc);
				cout << sym;
				break;
			}

		}
	}
}
void PrintN(int cr, int cc, int s, char sym = -37)
{
	for (int i = 0;i < s/2;i++)
	{
		gotoRowCol(cr + i, cc+i);
		cout << sym;
	}
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(cr - i, cc-i);
		cout << sym;
	}
	for (int i = 1;i <= s;i++)
	{
		gotoRowCol((cr - s / 2)+ i, cc-s/2);
		cout << sym;
	}
	for (int i = 1;i <= s;i++)
	{
		gotoRowCol((cr + s / 2) - i, cc + s/2);
		cout << sym;
	}
}
void PrintM(int cr,int cc,int s,char sym=-37)
{
	for (int i = 0;i < s / 8;i++)
	{
		gotoRowCol(cr, cc+i);
		cout << sym;
	}
	for (int i = 0;i < s / 8;i++)
	{
		gotoRowCol(cr, cc - i);
		cout << sym;
	}
	for (int i = 1;i <= s/2;i++)
	{
		gotoRowCol(cr - i, (cc - s/8) - i);
		cout << sym;
	}
	for (int i = 1;i <= s;i++)
	{
		gotoRowCol(((cr - (s/2)) + i), (cc-s/8) - s/2);
		cout << sym;
	}
	for (int i = 1;i <= s / 2;i++)
	{
		gotoRowCol(cr - i, (cc + s / 8) + i);
		cout << sym;
	}
	for (int i = 1;i <= s;i++)
	{
		gotoRowCol((cr - s/2) + i, (cc + s / 8) + s/2);
		cout << sym;
	}
}
void PrintA(int cr, int cc,int s, char sym = -37)
{
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(cr, cc + i);
		cout << sym;
	}
	for (int i = 0;i < s / 2;i++)
	{
		gotoRowCol(cr, cc - i);
		cout << sym;
	}
	for (int i = 1;i <= s/2;i++)
	{
		gotoRowCol(cr -i, (cc-s/2)+i);
		cout << sym;
	}
	for (int i = 1;i <= s / 2;i++)
	{
		gotoRowCol(cr-i, (cc + s / 2)-i);
		cout << sym;
	}
	for (int i = 1;i <= s / 2;i++)
	{
		gotoRowCol(cr + i, (cc-s/2) - i+1);
		cout << sym;
	}
	for (int i = 1;i <= s / 2;i++)
	{
		gotoRowCol(cr + i, (cc + s / 2) + i-1);
		cout << sym;
	}
}
void PrintMMax(int cr, int cc,int R, int s, char sym = -37)
{
	
	for (s = 8;s < R;s++)
	{
		PrintM(cr, cc, s);
		MySleep(50);
		PrintM(cr, cc, s, ' ');
	}
}
void PrintAMax(int cr, int cc,int R, int s, char sym = -37)
{
	for (;s < R;s++)
	{
		PrintA(cr, cc, s);
		MySleep(50);
		PrintA(cr, cc, s,' ');
	}
}
void PrintNMax(int cr, int cc,int R, int s, char sym = -37)
{
	for (;s < R;s++)
	{
		PrintN(cr, cc, s);
		MySleep(50);
		PrintN(cr, cc, s,' ');
	}
}
void SineWave(int s,int cr, int a, int w, int C, char sym = -37)
{
	double ChTheta = (double (360 * w)) / C;
	double STheta = s;
	for (int c = 0;c < C;c++)
	{
		int r = a *(-1)* sin(STheta * 3.14 / 180)+ cr;
		gotoRowCol(r, c);
		cout << sym;
		STheta += ChTheta;
	}
}
void SineWaveName(int s, int cr, int a, int w, int C,char L[],int size)
{
	double ChTheta = (double(360 * w)) / C;
	double STheta = s;
	int i = 0;
	for (int c = 0;c < C;c++,i++)
	{
		int r = a * (-1) * sin(STheta * 3.14 / 180) + cr;
		gotoRowCol(r, c);
		if (i >= size)
		{
			i = 0;
		}
		cout << L[i];
		STheta += ChTheta;
	}
}
void SineWaveMoving(int cr, int a, int w, int C, char sym = -37)
{
	int s=0;
	while (true)
	{

		SineWave(s, R / 2, 15, 2, C);
		SetClr(3);
		MySleep(1);
		SineWave(s, R / 2, 15, 2, C, ' ');
		s++;
	}
}
void SineWaveMovingName(int cr, int a, int w, int C, char L[], int size)
{
	int s = 0;
	while (true)
	{

		SineWaveName(s, R / 2, 15, 2, C, L, size);
		SetClr(3);
		MySleep(1);
		SineWave(s, R / 2, 15, 2, C, ' ');
		s++;
	}
}
void SineWaveChAmp( int cr, int w, int C,int R, char sym = -37)
{
	double ChTheta = (double(360 * w)) / C;
	double STheta;
	int s = 0;
	while (true)
	{
		for (double a = 2;a < R/2;s++,a+=0.1)
		{
			SineWave(s, cr, a, 2, C);
			SineWave(s, cr, a, 2, C, ' ');
		}
		for (double a = R/2 - 1;a >= 2;a-=0.1,s++)
		{
			SineWave(s, cr, a, 2, C);
			SineWave(s, cr, a, 2, C, ' ');
		}
	}
}
void Print2DArray(int R, int C,int  A[][max_column])
{
	for (int i = 0;i < R;i++)
	{
		for (int j = 0;j < C;j++)
		{
			cout <<setw(3)<< A[i][j];
		}
		cout << endl;
	}
}
void RectangularNumberAll(int dim,int A[][max_column])
{
	int Ch = 0;
	for (int r = dim;r >= 0;r -= 2)
	{
		int sum = 1;
		for (int j = Ch;j < dim - 1-Ch;j++)
		{
			A[Ch][j] = sum++;
		}
		for (int i = Ch;i < dim - 1-Ch;i++)
		{
			A[i][dim - 1-Ch] = sum++;
		}
		for (int j = dim - 1-Ch;j > Ch;j--)
		{
			A[dim - 1-Ch][j] = sum++;
		}
		for (int i = dim - 1-Ch;i > Ch;i--)
		{
			A[i][Ch] = sum++;
		}
		Ch++;
	}
}
void CWRectangular(int dim, int A[][max_column], int r)

{
	int Ch = r;

	int sum = 1;
	for (int j = Ch;j < dim - 1 - Ch;j++)
	{
		A[Ch][j] = sum++;
	}
	for (int i = Ch;i < dim - 1 - Ch;i++)
	{
		A[i][dim - 1 - Ch] = sum++;
	}
	for (int j = dim - 1 - Ch;j > Ch;j--)
	{
		A[dim - 1 - Ch][j] = sum++;
	}
	for (int i = dim - 1 - Ch;i > Ch;i--)
	{
		A[i][Ch] = sum++;
	}

	
}
void ACWRectangular(int dim, int A[][max_column], int r)
{
	int Ch = r;

	int sum = (dim-1-(2*Ch))*4;
	for (int j = Ch;j < dim - 1 - Ch;j++)
	{
		A[Ch][j] = sum--;
	}
	for (int i = Ch;i < dim - 1 - Ch;i++)
	{
		A[i][dim - 1 - Ch] = sum--;
	}
	for (int j = dim - 1 - Ch;j > Ch;j--)
	{
		A[dim - 1 - Ch][j] = sum--;
	}
	for (int i = dim - 1 - Ch;i > Ch;i--)
	{
		A[i][Ch] = sum--;
	}
}

void Bonus(int s, int cr, int a, int w, int C, char sym = -37)
{
	double ChTheta = (double(360 * w)) / C;
	double STheta = s;
	for (int c = 0;c < C/2;c++)
	{
		int r = a * (-1) * sin(STheta * 3.14 / 180) + cr;
		gotoRowCol(r, c);
		cout << sym;
		STheta += ChTheta;
	}
	STheta = s;
	for (int c = C / 2;c < C;c++)
	{
		int r = a * (-1) * sin(STheta * 3.14 / 180) + cr;
		gotoRowCol(r, c);
		cout << sym;
		STheta += ChTheta;
	}
	for (int r = R / 6;r <= R - 6;r++)
	{
		gotoRowCol(r, 0);
		cout << sym;
	}
	for (int r = R / 6;r <= R - 6;r++)
	{
		gotoRowCol(r, C/2);
		cout << sym;
	}
	for (int r = R / 6;r <= R - 6;r++)
	{
		gotoRowCol(r, C-1);
		cout << sym;
	}
	cr = R - 6;
	STheta = s;
	for (int c = 0;c < C / 2;c++)
	{
		int r = a * (-1) * sin(STheta * 3.14 / 180) + cr;
		gotoRowCol(r, c);
		cout << sym;
		STheta += ChTheta;
	}
	STheta = s;
	for (int c = C / 2;c < C;c++)
	{
		int r = a * (-1) * sin(STheta * 3.14 / 180) + cr;
		gotoRowCol(r, c);
		cout << sym;
		STheta += ChTheta;
	}
}
void Fan1(char sym=-37)
{
	int size = 5;
	for (int ln = 1;ln <= size;ln++)
	{
		for (int sp = 1;sp <= ln - 1;sp++)
		{
			cout << " ";
		}
		for (int p = 1;p <= (size*2)-(ln*2-1);p++)
		{
			cout << sym;
		}
		cout << endl;
	}
	for (int ln = 2;ln <= size;ln++)
	{
		for (int sp = 1;sp <= size-ln;sp++)
		{
			cout << " ";
		}
		for (int p = 1;p <= (ln*2)-1;p++)
		{
			cout << sym;
		}
		cout << endl;
	}
}
void Fan2(char sym = -37)
{
	int size = 5;
	int ctl = 2;
	for (int ln = 1;ln <= size;ln++)
	{
		for (int s = 1;s <= ln;s++)
		{
			cout << char(-37);
		}
		for (int sp = 1;sp <= (2 * size) - ctl;sp++)
		{
			cout << " ";

		}
		for (int s = 1;s <= ln;s++)
		{
			cout << char(-37);
		}
		ctl += 2;
		cout << endl;
	}
	ctl = 2;
	for (int ln = 2;ln <= size;ln++)
	{
		for (int s = 1;s <= size - (ln - 1);s++)
		{
			cout << char(-37);
		}
		for (int sp = 1;sp <= ctl;sp++)
		{
			cout << " ";

		}
		for (int s = 1;s <= size - (ln - 1);s++)
		{
			cout << char(-37);
		}
		ctl += 2;
		cout << endl;
	}
}
void TtoB(int rs, int re,int c, char sym = '*')
{
	for (;rs < re;rs++)
	{
		gotoRowCol(rs, c);
		cout << sym;
		MySleep(200);
	}
}
void BtoT(int rs, int re, int c, char sym = '*')
{
	for (;rs > re;rs--)
	{
		gotoRowCol(rs, c);
		cout << sym;
		MySleep(200);
	}
}
void LtoR(int cs, int ce, int r, char sym = '*')
{
	for (;cs < ce;cs++)
	{
		gotoRowCol(r, cs);
		cout << sym;
		MySleep(200);
	}
}
void RtoL(int cs, int ce, int r, char sym = '*')
{
	for (;cs > ce;cs--)
	{
		gotoRowCol(r, cs);
		cout << sym;
		MySleep(200);
	}
}
void RectSpiral()
{
	while (true)
	{
		for (int r = 1;r <= (R / 2)-1;r++)
		{
			LtoR(r-1, C - r, r-1);
			TtoB(r-1, R - r, C - 1-(r - 1));
			RtoL(C -r, r-1, R - r);
			BtoT(R - r, r-1, r-1);
		}
		MySleep(1);
		for (int r = R / 2;r >= 0; r--)
		{
			LtoR(r - 1, C - r - 1, r - 1,' ');
			TtoB(r - 1, R - r - 1, C - 1 - (r - 1),' ');
			RtoL(C - r, r - 1, R - r,' ');
			BtoT(R - r, r - 1, r - 1,' ');

		}
	}

}
void RectSpiralWithSpace(int space)
{

	while (true)
	{
		int delta = R / (space*2);

		for (int r=1;r <= delta;r ++)
		{
			LtoR((r-1)*space, C - 1-(r-1)*space, (r-1)*space);
			TtoB((r-1)*space, R - 1 - (r - 1) * space, C - 1 - (r - 1) * space);
			RtoL(C - 1 - (r - 1) * space, (r-1)*space, R - 1 - (r - 1) * space);
			BtoT(R - 1-(r-1)*space, (r-1)*space, (r - 1) * space);
		}
		MySleep(1);
		for (int r=delta;r >= 1; r --)
		{
			LtoR((r - 1) * space, C - 1 - (r - 1) * space, (r - 1) * space,' ');
			TtoB((r - 1) * space, R - 1 - (r - 1) * space, C - 1 - (r - 1) * space,' ');
			RtoL(C - 1 - (r - 1) * space, (r - 1) * space, R - 1 - (r - 1) * space,' ');
			BtoT(R - 1 - (r - 1) * space, (r - 1) * space, (r - 1) * space,' ');
		}
	}
	
}
void RectSpiralWithRemove(int arms)
{

	while (true)
	{
		int delta = (R / 2) / arms;
		int c = 0;
		int r = 0;

		for (;r < R / 2;c += delta, r += delta)
		{
			LtoR(c, C - c-1, r);
			TtoB(r, R - r-1, C - c-1);
			RtoL(C - c-1, c, R - r-1);
			BtoT(R - r-1, r, c);
			LtoR(c, C - c-1, r, ' ');
			TtoB(r, R - r-1, C - c-1, ' ');
			RtoL(C - c-1, c, R - r-1, ' ');
			BtoT(R - r-1, r, c, ' ');
		}
	}

}
int main()	
{
	int choice,sizeL=7;
	int A[max_column][max_column] = {};
	char L[max_column] = { '-','M','A','N','N','A','N' };
	cout << "Enter choice:" << endl;
	cin >> choice;
	if (choice == 1)
	{
		SineWave(90,R / 2, 15, 2, C);
		_getch();
	}
	if (choice == 3)
	{
		SineWaveMoving(R / 2, 15, 2, C);
	}
	if (choice == 5)
	{
		SineWaveChAmp(R / 2, 2, C, R);
	}
	if (choice == 6)
	{
		RectangularNumberAll(7, A);
		Print2DArray(7, 7, A);
	}
	if (choice == 7)
	{
		ACWRectangular(7, A, 2);
		CWRectangular(7, A, 0);
		Print2DArray(7, 7, A);
	}
	if (choice == 8)
	{
		int s;
		cout << "Enter scale:" << endl;
		cin >> s;
		PrintA(R/2, C/2, s);
		_getch();
	}
	if (choice == 9)
	{
		while (true)
		{
			SetClr(1);
			PrintMMax(R/2, C/2,R, 8);
			SetClr(2);
			PrintAMax(R/2, C/2,R, 8);
			SetClr(3);
			PrintNMax(R/2, C/2,R, 8);
			SetClr(4);
			PrintNMax(R/2, C/2,R, 8);
			SetClr(5);
			PrintAMax(R/2, C/2,R, 8);
			SetClr(6);
			PrintNMax(R/2, C/2,R, 8);
		}
	}
	
	if (choice == 12)
	{
		DrawCirle(R / 2, C / 2, 10);
		_getch();
	}
	if (choice == 13)
	{
		
		for (int i = 1000;true;i+=500)
		{
			system("cls");
			Fan1();
			MySleep(i);
			system("cls");
			Fan2();
			MySleep(i);
		}
		
		
	}
	if (choice == 14)
	{
		CircleChRadius(R / 2, C / 2);
	}
	if (choice == 15)
	{
		Smiley1(R / 2, C / 2);
		_getch();
	}
	if (choice == 16)
	{
		Smiley2(R / 2, C / 2);
		_getch();
	}
	if (choice == 17)
	{
		DrawSpiral(R / 2, C / 2, 6);
		_getch();
	}
	if (choice == 18)
	{
		RectSpiral();
	}
	if (choice == 19)
	{
		RectSpiralWithSpace(5);
	}
	if (choice == 20)
	{
		RectSpiralWithRemove(6);
	}
	if (choice == 21)
	{
		SineWaveName(0, R / 2, 15, 2, C, L, sizeL);
		_getch();
	}
	if (choice == 22)
	{
		SineWaveMovingName(R / 2, 15, 2, C, L, sizeL);
	}
	if (choice == 23)
	{
		PrintCartoon(R, C);
		Cliff(R, C);
		StoneThrowing(R, C);
		_getch();
	}
	if (choice == 24)
	{
		PrintCartoon(R, C);
		Cliff(R, C);
		StoneThrowingMany(R, C);
		_getch();
	}
	if (choice == 0)
	{
		Bonus(0, R / 6, 8, 1, C);
		_getch();
	}
}
