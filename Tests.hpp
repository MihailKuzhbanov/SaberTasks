#include <SerializeIt.hpp>
#include <NoDups.hpp>

//вспомогательные функции для тестирования
//
//
List GenerateList(int listSize, int wordSize) {
	List resultList;
	for (int i = 0; i < listSize; i++) {
		resultList.AddLast(GenerateWord(wordSize));
	}
	return resultList;
}

void ShowList(List list) {
	ListNode * tempHead = list.GetHead();
	ListNode * tempTail = list.GetTail();
	while (tempHead != tempTail) {
		std::cout << tempHead->GetData() << std::endl;
		tempHead = tempHead->GetNext();
	}
}

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

//тест (де)сериализизации
//в качестве аргумента путь к файлу для удобства тестирования
//функция сериализации работает с указателем на файл
void SerializationTest(std::string filePath) {
	List testList;
	List testListNew;
	std::string path = filePath;
	FILE * file;

	std::cout << "Serialization section" << std::endl;
	//открытие файла для записи в бинарном режиме
	if ((file = fopen(path.c_str(), "wb")) == NULL) {
		std::cout << "Cannot open file.\n";
		exit(1);
	}
	testList = GenerateList(10, 5);
	ShowList(testList);
	testList.Serialize(file);
	fclose(file);

	std::cout << "Deserialization section" << std::endl;
	//открытие файла для чтения в бинарном режиме
	if ((file = fopen(path.c_str(), "rb")) == NULL) {
		std::cout << "Cannot open file.\n";
		exit(1);
	}
	testListNew.Deserialize(file);
	fclose(file);
	std::cout << std::endl;
	ShowList(testListNew);
}
