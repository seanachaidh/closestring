/*
 * ant.cpp
 * 
 * Copyright 2017 Pieter Van Keymeulen <pvankeymeulen@seanachaidh.be>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <ant.h>

Ant::Ant(AntColony* colony) {
	this->colony = colony;
}

Ant::~Ant() {
	
}

void Ant::updatePheromone() {
	for(int i = 0; i < colony->instance->getAlphabetSize(); i++) {
		for(int j = 0; j < colony->instance->getStringLength(); j++) {
			double old = colony->pheromone_matrix[i][j];
			int maxham = colony->instance->maxHammingDistance(found_solution.c_str());
			
			colony->pheromone_matrix[i][j] = old + (1-(maxham/colony->instance->getStringLength()));
		}
	}
}

void Ant::constructSolution() {
	string solution = "";
	for(int i = 0; colony->instance->getStringLength(); i++){
		char toadd = colony->chooseByChance(i);
		solution += toadd;
	}
	
	this->found_solution = solution;
}
