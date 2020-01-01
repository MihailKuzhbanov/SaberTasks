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

//вспомогательные функции для тестирования
std::string GenerateWord(int maxWordSize) {
	std::string str = "";
	int tempSize = (maxWordSize - rand() % maxWordSize);
	for (int i = 0; i < tempSize; i++) {
		str += (rand() % 25 + 'a');
	}
	str += '\n';
	return str;
}

void ShowCharArray(char * c) {
	int n(0);
	while (c[n] != '\0') {
		std::cout << c[n];
		n++;
	}
	std::cout << std::endl;
}

char * StringToChar(std::string s) {
	char * result = new char[s.length() + 1];
	for (int i = 0; i < s.length(); i++) {
		result[i] = s[i];
	}
	result[s.length()] = '\0';
	return result;
}

//тест удаления дубликатов
//считывание реализовано через потоки для удобства тестирования
//функция удаления дубликатов работает с указателем на массив символов
void RemoveDupsTest() {
	std::string input;
	std::cout << ">Enter test string: " << std::endl;
	std::cin >> input;
	char * cstr = StringToChar(input);
	RemoveDups(cstr);
	std::cout << ">Nearbly duplicates removed: " << std::endl;
	ShowCharArray(cstr);
	std::cout << std::endl;
}
