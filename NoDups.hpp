//Saber Interactive - 1
/*Напишите функцию, удаляющую последовательно дублирующиеся символы в строке:
	("AAA BBB ААА" -> "A B А")
void RemoveDups (char *pStr);
*/
#include <string>
#include <time.h>						//для работы со случайными числами в тестах

//функция удаления дубликатов соседей
//
//
void RemoveDups(char * pStr) {
	if (pStr == NULL) return;
	int n(0);
	int m(0);
	char * temp = new char[256];
	while (pStr[n] != '\0') {
		if (pStr[n] != pStr[n + 1]) {
			temp[m] = pStr[n];
			m++;
		}
		n++;
	}
	for (int i = 0; i < m; i++) {
		pStr[i] = temp[i];
	}
	pStr[m] = '\0';
}
