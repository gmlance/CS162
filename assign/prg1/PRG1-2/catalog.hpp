//
//  Header
//  
//
//  Created by Grant Lance on 1/16/20.

#ifndef gml_hpp
#define gml_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

struct wizard {
    std::string name;
    int id;
    std::string password;
    std::string posittion_title;
    float beard_length;
};

struct spell {
    std::string name;
    float success_rate;
    std::string effect;
};

struct spellbook {
    std::string title;
    std::string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell *s;
};


spellbook * create_spellbooks(int);

void get_spellbook_data(spellbok *, int, std::ifstream &);

spell * creat_spells(int);

void get_spell_data(spell *, int, std::ifstream &);

void delete_info(wizard **, int, spellbook **, int);

void delete_info(wizard **, spellbook **, int);



#endif /* funcdef_hpp */
