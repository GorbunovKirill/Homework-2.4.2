#include <iostream>
#include <fstream>


class Adress {
private:
	std::string city;
	std::string street;
	int house;
	int flat;

public:

	void set_adress(std::string gen_city, std::string gen_street, int gen_house, int gen_flat) {
		this->city = gen_city;
		this->street = gen_street;
		this->house = gen_house;
		this->flat = gen_flat;
	}

	std::string get_city() {
		return this->city;
	}
	std::string get_street() {
		return this->street;
	}
	int get_house() {
		return this->house;
	}
	int get_flat() {
		return this->flat;
	}

	Adress() {
		this->city = "неизвестно";
		this->street = "неизвестно";
		this->house = 0;
		this->flat = 0;
	};
};

void swapper(int size, bool swaped, Adress* first, Adress* second) {

	do {
		swaped = false;
		for (int i = 1; i < size; i++) {
			if (first[i - 1].get_city() < first[i].get_city())
			{
				second[i - 1].set_adress(first[i - 1].get_city(), first[i - 1].get_street(),
					first[i - 1].get_house(), first[i - 1].get_flat());

				first[i - 1].set_adress(first[i].get_city(),
					first[i].get_street(), first[i].get_house(), first[i].get_flat());
				first[i].set_adress(second[i - 1].get_city(), second[i - 1].get_street(),
					second[i - 1].get_house(), second[i - 1].get_flat());;
				swaped = true;
			}
		}

	} while (swaped);


}


int main() {
	setlocale(LC_ALL, "Russian");

	std::ifstream read("in.txt");
	if (!read.is_open()) {
		std::cout << "Ошибка" << std::endl;
		exit(1);
	}
	int size;
	std::string city_g;
	std::string street_g;
	int house_g;
	int flat_g;
	bool swaped = false;
	read >> size;
	Adress* first = new Adress[size];
	Adress* second = new Adress[size];


	for (int i = 0; i < size; i++) {
		read >> city_g;
		read >> street_g;
		read >> house_g;
		read >> flat_g;

		first[i].set_adress(city_g, street_g, house_g, flat_g);
	}


	swapper(size, swaped, first, second);


	std::ofstream write("out.txt");
	write << size << std::endl;
	for (int i = size - 1; i >= 0; i--) {

		write << first[i].get_city() << ", " << first[i].get_street() << ", " << first[i].get_house() << ", " << first[i].get_flat() << std::endl;

	}
	write.close();
	read.close();

	delete[] second;
	delete[] first;
	return 0;
}