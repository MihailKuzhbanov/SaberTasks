//bad practice, better use hpp
//не делайте так, работать будет, но прекомилированные заголовки работать не будут
//следует добавить заголовочники и подключать их
#include <SerializeIt.cpp>
#include <NoDups.cpp>

int main() {

	SerializationTest("\serialization");
	system("pause");
	RemoveDupsTest();
	system("pause");
}
