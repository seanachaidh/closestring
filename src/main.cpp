/*
 * main.cpp
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


#include <iostream>
#include <getopt.h>

int test_flag = 0;

static struct option long_options[] = {
	{"test", no_argument, &test_flag, 1},
	{0,0,0,0}
};

using namespace std;
int main(int argc, char **argv)
{
	int option_index;
	int c;
	
	while((c = getopt_long(argc, argv, "", long_options, &option_index)) != -1){
		switch(c) {
		case 0:
			if(long_options[option_index].flag != 0){
				break;
			}
			cout << "Option " << long_options[option_index].name << endl;
		}
	}
	
	cout << "Testing: " << test_flag << endl;
	
	return 0;
}

