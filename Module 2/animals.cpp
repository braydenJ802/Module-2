#include "animals.h"

#include <iostream>

using namespace std;


Animal::Animal(const string& anim_type, const string& anim_sound,
	const string& land_or_sea, const string& fav_food, const float& lifespan, const float& weight,
	const float& gestation) : animal_type{ anim_type }, animal_sound{ anim_sound }, land_or_aquatic{ land_or_sea },
	favorite_food{ fav_food }, avg_lifespan{ lifespan }, avg_weight{ weight },
	gestational_period{ gestation } {}



void Animal::display_info() const {
	cout << endl;

};


//Do I need get functions?
float Animal::get_lifespan() {
	return avg_lifespan;
};
float Animal::get_avg_weight() {
	return avg_weight;
};
float Animal::get_gestational_period() {
	return gestational_period;

};

string Animal::get_animal_type() {
	return animal_type;
};
string Animal::get_animal_sound() {
	return animal_sound;
};
string Animal::get_aquatic_or_land() {
	return land_or_aquatic;
};
string Animal::get_favorite_food() {
	return favorite_food;
};
