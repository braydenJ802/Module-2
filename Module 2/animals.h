#ifndef animals_h // prevents the header from being imported multiple times
#define animals_h

#include <iostream>

using namespace std;

class Animal {

private:


	Animal(const string& anim_type, const string& anim_sound,
		const string& land_or_sea, const string& fav_food, const int& lifespan, const float& weight,
		const float& gestation); //constructor for Animal Class

	float avg_lifespan;
	float avg_weight;
	float gestational_period; 

	string animal_type;
	string animal_sound;
	string land_or_aquatic;
	string favorite_food;


public:
	float get_lifespan(void);
	float get_avg_weight(void);
	float get_gestational_period(void);

	string get_animal_type(void);
	string get_animal_sound(void);
	string get_aquatic_or_land(void);
	string get_favorite_food(void);


	// Display the contents of the information accessed (tell about the animal)
	void display_info() const;
};



#endif //animals_h