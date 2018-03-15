#include <iostream>
#include <fstream>

//записва числа въведени от клавиатурата в байнарен файл
void writeNumbers(const char* fileName) {

	size_t n;
	std::cout << "How many numbers?\n";
	std::cin >> n;

	std::cout << "Enter numbers:\n";

	std::ofstream ofs(fileName, std::ios::binary);

	if (!ofs.is_open()) {

		std::cout << "error while opening\n";
		return;
	}

	int num;
	for (size_t i = 0; i < n; i++) {

		std::cin >> num;
		ofs.write((const char*)&num, sizeof(int));
	}

	if (ofs)
		std::cout << "successfully written!\n";

	ofs.close();

}

//прочита всяко трето число от байнари файл 
//и го отпечатва на стандартния изход
void readNumbers(const char* fileName) {

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open()) {

		std::cout << "error while opening!\n";
		return;
	}

	int num;
	//следим за достигане на края на файла
	while (!ifs.eof()) {

		ifs.read((char*)&num, sizeof(int));

		if (ifs.good()) {
			//ако последното четене е било успешно
			//местим get указателя на файловия поток 
			//с 8байта (прескачаме два int-а) спрямо текущата позиция
			ifs.seekg(2 * sizeof(int), std::ios::cur);
			std::cout << num << ' ';
		}
	}

	ifs.close();

}

int main() {

	writeNumbers("nums.bin");
	readNumbers("nums.bin");

	return 0;
}