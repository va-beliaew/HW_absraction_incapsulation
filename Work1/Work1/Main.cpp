#include <iostream>
#include <fstream>
#include <string>

class places {
	std::string city;
	std::string street;
	int house;
	int apart;
public:
	
		void set_city(std::string s_city) {
			city = s_city;
		}
		void set_street (std::string s_street) {
			street = s_street;
		}
		void set_house (int hou) {
			house = hou;
		}
		void set_apart (int apar) {
			apart = apar;
		}
	std::string string() {
		return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apart) + '\n';
	}
};

int main() {
	std::ifstream in;
	int N;
	in.open("in.txt");
	if (in.is_open()) {
		in >> N;
	}
	else {
		std::cout << "Ошибка чтения файла!";
		return 0;
	}
	places* data = new places [N];
	std::string word;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= 4; ++j) {
			in >> word;
			if (j == 1) {
				data[i].set_city(word);
			}
			else if (j == 2) {
				data[i].set_street(word);
			}
			else if (j == 3) {
				data[i].set_house(std::stoi(word));
			}
			else if (j == 4) {
				data[i].set_apart(std::stoi(word));
			}
		}
		;
	}
	in.close();
	std::ofstream out("out.txt");
	for (int i = (N - 1); i >= 0; --i) {
		out << data[i].string();
	}
	out.close();
	delete[] data;
	return 0;
}