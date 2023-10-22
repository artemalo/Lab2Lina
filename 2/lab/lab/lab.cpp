#include "TFigure.h"
#include "TPawn.h"

using namespace std;

int main()
{
	bool boardAtack[LEN][LEN];
	for (int i = 0; i < LEN; i++)
		for (int j = 0; j < LEN; j++)
			boardAtack[i][j] = 0;


	boardAtack[0][0] = 1;
	TPawn a(black, 'a', 1);
	//a.AddFigure();


	int k = LEN - 1;
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			cout << boardAtack[j][k] << " ";
		}
		--k;
		cout << '\n';
	}
}