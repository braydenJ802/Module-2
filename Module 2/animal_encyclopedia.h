#ifndef animal_encyclopedia_h // prevents the header from being imported multiple times
#define animal_encyclopedia_h

#include <iostream>
#include <fstream>  // ifstream, ofstream
#include <list>
#include <map>
#include <string>

#include "animals.h"

using namespace std;

class Encyclopedia {

public:

	// Constructor that reads from a file to populate information on animals in an "encyclopedia"
	Encyclopedia(const string& filename);


	// Access information about a single animal 
	void read_animal_details(const string& animal_type) const;


	//Add animals to file, if so desired
	void add_animals_to_file(const string& animal_type, const string& animal_sound,
		const string& land_or_sea, const string& favorite_food, const int& avg_lifespan,
		const float& avg_weight, const float& gestational_period);


	// Save all animal information to a file
	void save_to_animal_file(const string& filename);


private:

	//create a map of animals and a list of their animal information
	map<string, list<Animal>> animals; //map<string(animal_type), list<Animal (class) (i.e. Animal Info)>> animals (animals_map -> animal_type: info list)

	//read animal information from the file
	void read_animal_info_from_file(const string& filename);

	//add more animal information to the file
	void save_file(const string& filename);


};


#endif //animal_encyclopedia.h