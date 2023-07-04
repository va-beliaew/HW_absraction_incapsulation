#include <iostream>
#include <fstream>
#include <string>

class Multiplicate {
	public:
		Multiplicate(std::string** adres) {

	}
		std::string print(std::string* adres) {
			std::string word;
			for (int i = 0; i < 3; ++i) {
				word += (adres[i] + ", ");
			}
			return (word + adres[3]);
}

};
class Sort {
public:
	Sort(int N, std::string** adres) {
	}
	void sort_swap (int N, std::string** adres) {
			for (int i = 0; i < (N-1); ++i) {
			for (int j = 0; j < ((N-1) - i); ++j) {
				if (adres[j][0].compare(adres[j + 1][0]) == 1) {
					swap(adres[j], adres[j + 1]);
				}
				else if (adres[j][0].compare(adres[j + 1][0]) == 0) {
					if (adres[j][1].compare(adres[j+1][1]) == 1) {
						swap(adres[j], adres[j + 1]);
							}
				}
			}
		}
	}

};

	
int main() {
	std::ifstream in;
	in.open("in.txt");
	int N;
	if (in.is_open()) {
		in >> N;
	}
	else {
		std::cout << "Ошибка открытия файла!";
		return 0;
	}
	std::string** adres = new std::string*[N];
	for (int i = 0; i < N; ++i) {
		adres[i] = new std::string[4];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			in >> adres[i][j];
		}
	}
	in.close();
	Sort Adres(N, adres);
	Adres.sort_swap(N, adres);
	Multiplicate Word(adres);
	std::ofstream out("out.txt");
	out << N << std::endl;
	for (int i = 0; i < N; ++i) {
		out << Word.print(adres[i]) << std::endl;
	}
	out.close();
	for (int i = 0; i < N; ++i) {

		delete[] adres[i];
	}
	delete[] adres;
	return 0;
}