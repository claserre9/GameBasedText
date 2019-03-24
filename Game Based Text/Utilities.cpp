#include "Utilities.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include "Room.h"
#include "Player.h"


using namespace std;
void displayStory() {
	//Story goes here
	 
	cout << "########################## STALAG ESCAPE #####################" <<endl;
	cout << "     During korean war, you are a usmarine, who fell over     " << endl;
	cout << "     enemy airspace, and held as a prisoner of war behind     " << endl;
	cout << "     enemy lines at korean Stalag (POW camp). As you move     " << endl;
	cout << "    through the camp, you collect items to help you escape,   " << endl;
	cout << "    learn a few korean words, and find different potential    " << endl;
	cout << "    escape routes, but there is only one way to succeed.If    " << endl;
	cout << "   you take the wrong escape route or are miss-prepared,you   " << endl;
	cout << "  will be captured and the game is over. You have an assault  " <<endl;
	cout << "  pack that can hold 4 items. You start the game with a pack  " << endl;
	cout << " of cigarettes inside your pack.  You have 24 hours to escape " << endl;
	cout << "     before the korean arrives to cut you loose then send     " << endl;
	cout << "       you on a forced wintertime march to another camp.      " << endl;
	cout << "##############################################################" <<endl;
	cout << endl;

}
void displayMap() {

	cout << "                                                                       " << endl;
	cout << "                             Korean CAMP' MAP                          " << endl;
	cout << "                                                                       " << endl;
	cout << " ##################################################################### " << endl;
	cout << " #     ---------------           ---------------                     # " << endl;
	cout << " #     |             |           |             |                     # " << endl;
	cout << " #     | Barracks    |   =====>  | Messhall    |                     # " << endl;
	cout << " #     |             |           |             |                     # " << endl;
	cout << " #     ---------------           ---------------                     # " << endl;
	cout << " #                                     ||                            # " << endl;
	cout << " #                                     ||                            # " << endl;
	cout << " #                                     ||                            # " << endl;
	cout << " #     ------------------         ----------------                   # " << endl;
	cout << " #     |                |         |              |                   # " << endl;
	cout << " #     | Running Fields |  <===== | School house |                   # " << endl;
	cout << " #     |                |         |              |                   # " << endl;
	cout << " #     ------------------         ----------------                   # " << endl;
	cout << " #               ||                                                  # " << endl;
	cout << " #               ||                                    Desert        # " << endl;
	cout << " #               ||                             |*  *  *  *  *  *  * # " << endl;
	cout << " #    ___________________________               |*  *  *  *  *  *  * # " << endl;
	cout << " #                               |              |*  *  *  *  *  *  * # " << endl;
	cout << " #               Tunnel             =========>  |*  *  *  *  *  *  * # " << endl;
	cout << " #    ___________________________|              |*  *  *  *  *  *  * # " << endl;
	cout << " #                                              |*  *  *  *  *  *  * # " << endl;
	cout << " #                                              |*  *  *  *  *  *  * # " << endl;
	cout << " #                                              |*  *  *  *  *  *  * # " << endl;
	cout << " ##################################################################### " << endl;
	
}

void MenuWithMap(Player& player, Room* & room){
	int choice = 0;
	string element;
	do {
		cout << "\nWhich action do you want to perform : " << endl;
		cout << "1 - Display map" << endl;
		cout << "2 - Search in the room" << endl;
		cout << "3 - Take a specific a item in the room" << endl;
		cout << "4 - Show inventory" << endl;
		cout << "5 - Continue to escape ... \n" << endl;
		cin >> choice;
		
		switch (choice) {
			case 1: displayMap(); 
				break;
			case 2: 
				player.search(); 
				break;
			case 3: 
				cout << "What's the object you wanna take in this room: " << endl;
				cin >> element;
				player.take(element); 
				room->removeItem(element);
				break;
			case 4:
				player.getInventory();
				break;
			case 5:break;
			default:cout << "Unknown choice" << endl; break;
		}
	} while (choice != 5);
}

void Menu(Player& player, Room* & room) {
	
	int choice = 0;
	string element;
	do {
		vector<string> usmarineItems = player.get_items_taken();
		if (find(usmarineItems.begin(), usmarineItems.end(), "Map") != usmarineItems.end()) {
			choice = 4;
			MenuWithMap(player, room);
			break;
		}
		cout << "\nWhich action do you want to perform : " << endl;
		cout << "1 - Search in the room" << endl;
		cout << "2 - Take a specific a item in the room" << endl;
		cout << "3 - Show inventory" << endl;
		cout << "4 - Continue to escape ... \n" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			player.search();
			break;
		case 2:
			cout << "What's the object you wanna take in this room: " << endl;
			cin >> element;
			player.take(element);
			room->removeItem(element);
			break;
		case 3:
			player.getInventory();
			break;
		case 4:break;
		default:cout << "Unknown choice" << endl; break;
		}
	} while (choice != 4);
}

void figthscene_1(Player & player, Caporal & caporal, Room* & room){
	int choice = 0;
	do {
		cout << "\nWhich action do you want to perform : " << endl;
		cout << "1 - Use your hand to fight" << endl;
		vector<string> usmarineItems = player.get_items_taken();
		if (find(usmarineItems.begin(), usmarineItems.end(), "Knife") != usmarineItems.end())
			cout << "2 - Use Knife to kill him quickly" << endl;
		cin >> choice;

		switch (choice) {
		case 1: 
			cout << "\nYou win the fight, but you are slightly injured!!";
			player.setHealth(player.getHealth()-caporal.getHealth());
			caporal.setHealth(0);
			room->addIteminList("Key");
			choice = 2;
			break;
		case 2 : 
			cout << "\n\nYou kill the korean caporal!!";
			caporal.setHealth(0);
			room->addIteminList("Key");
			choice = 2;
			break;
		default:cout << "Unknown choice" << endl; break;
		}
	} while (choice!=2);

}


