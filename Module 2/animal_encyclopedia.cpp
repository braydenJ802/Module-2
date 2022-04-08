#include "animal_encyclopedia.h"
#include "animals.h"

#include <iostream>
#include <string> //stof

using namespace std;


//Public methods
Encyclopedia::Encyclopedia(const string& filename) {
    //we begin by pulling animal information from a file
    read_animal_info_from_file(filename);
}

void Encyclopedia::read_animal_details(const string& animal_type) const {

    //search for an animal's info list within map
    auto iterator = animals.find(animal_type);

    if (iterator == animals.end()) { // the animal was not found
        return;
    }

    auto& info_list = iterator->second; // access the list of information on the specific animal


    for (const auto& Animal : info_list) {
         
        Animal.display_info(); //display  
        break;
        
    }

}

void Encyclopedia::add_animals_to_file(const string& animal_type, const string& animal_sound,
    const string& land_or_sea, const string& favorite_food, const float& avg_lifespan, const float& avg_weight,
    const float& gestational_period) {

    //Add a new animal
    Animal animal(animal_type, animal_sound, land_or_sea, favorite_food, 
        avg_lifespan, avg_weight, gestational_period);

    // This will add a new animal to the map (key-> animal_type name, value-> animal info list).
    animals[animal_type].push_back(animal);

    //You can see that this is how the  are populated into our map 
    // from the initial reading of a file as well (within the "read_messages_from_file" function)
}



void Encyclopedia::save_to_animal_file(const string& filename) {
    //we save our message by writing to the file
    save_file(filename);
}




//Private methods
void Encyclopedia::read_animal_info_from_file(const string& filename) {

    ifstream fin(filename); // open the file

    if (fin.fail()) {
        cout << "Error, unable to open file " << filename << endl;
        return;
    }

    while (!fin.fail()) {

        string animal_type;
        string animal_sound;
        string land_or_sea;
        string favorite_food;
        string avg_lifespan_str;
        string avg_weight_str;
        string gestational_period_str;
        getline(fin, animal_type, '|');
        getline(fin, animal_sound, '|');
        getline(fin, land_or_sea, '|');
        getline(fin, favorite_food, '|');
        getline(fin, avg_lifespan_str, '|');
        getline(fin, avg_weight_str, '|');
        getline(fin, gestational_period_str, '\n');
        float avg_lifespan = stof(avg_lifespan_str);
        float avg_weight = stof(avg_weight_str);
        float gestational_period = stof(gestational_period_str);

        if (!fin.fail()) {
            Animal animal(animal_type, animal_sound, land_or_sea, favorite_food,
                avg_lifespan, avg_weight, gestational_period);
            animals[animal_type].push_back(animal);
        }
    }

    fin.close();
}

void Encyclopedia::save_file(const string& filename) {

    // open a file for writing
    ofstream fout(filename);
    if (fout.fail()) {
        cout << "Unable to write to " << filename << endl;
        return;
    }

    for (auto& each : animals) {
        for (auto& information : each.second) {
            fout << information.get_lifespan() << "|"
                << information.get_avg_weight() << "|"
                << information.get_gestational_period() << "|"
                << information.get_animal_type() << "|"
                << information.get_animal_sound() << "|"
                << information.get_aquatic_or_land() << "|"
                << information.get_favorite_food() << endl;
        }
    }

    fout.close();
}
