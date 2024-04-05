#include <iostream>
#include <vector>  //for rack and etc
#include <random>  // random tiles withdrawal from bag
#include <string>
#include <iomanip>
#include <fstream>   //for dictionary file
#include <unordered_set>  //for dictionary storage in unoredered set
#include <Windows.h>  //for colored text
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
struct tile {
	char letter;
	int number;
	int locx;
	int locy;

	tile() {
		letter='/';
		number = NULL;
		locx = NULL;
		locy = NULL;
	}
	tile(char a, int n) {
		this->letter = a;
		this->number = n;
		this->locx = NULL;
		this->locy = NULL;
	}
	void setLetter(char c) {
		letter = c;
	}
	char getLetter() {
		return letter;
	}
	void setNumber(int n) {
		number = n;
	}
	int getNumber() {
		return number;
	}
	void setLocX(int x) {
		locx = x;
	}
	int getLocX() {
		return locx;
	}
	void setLocY(int y) {
		locy = y;
	}
	int getLocY() {
		return locy;
	}
};

class bag {
	int initialcount;
	tile A = tile('A', 1);
	tile B = tile('B', 3);
	tile C = tile('C', 3);
	tile D = tile('D', 2);
	tile E = tile('E', 1);
	tile F = tile('F', 4);
	tile G = tile('G', 2);
	tile H = tile('H', 4);
	tile I = tile('I', 1);
	tile J = tile('J', 8);
	tile K = tile('K', 5);
	tile L = tile('L', 1);
	tile M = tile('M', 3);
	tile N = tile('N', 1);
	tile O = tile('O', 1);
	tile P = tile('P', 3);
	tile Q = tile('Q', 10);
	tile R = tile('R', 1);
	tile S = tile('S', 1);
	tile T = tile('T', 1);
	tile U = tile('U', 1);
	tile V = tile('V', 4);
	tile W = tile('W', 4);
	tile X = tile('X', 8);
	tile Y = tile('Y', 4);
	tile Z = tile('Z', 10);

	vector<tile> tilecollection;

public:
	bag() {
		initialcount = 0;
		for (int i = 0; i < 9; i++) { tilecollection.push_back(A); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(B); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(C); }
		for (int i = 0; i < 4; i++) { tilecollection.push_back(D); }
		for (int i = 0; i < 12; i++) { tilecollection.push_back(E); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(F); }
		for (int i = 0; i < 3; i++) { tilecollection.push_back(G); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(H); }
		for (int i = 0; i < 9; i++) { tilecollection.push_back(I); }
		for (int i = 0; i < 1; i++) { tilecollection.push_back(J); }
		for (int i = 0; i < 1; i++) { tilecollection.push_back(K); }
		for (int i = 0; i < 4; i++) { tilecollection.push_back(L); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(M); }
		for (int i = 0; i < 6; i++) { tilecollection.push_back(N); }
		for (int i = 0; i < 8; i++) { tilecollection.push_back(O); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(P); }
		for (int i = 0; i < 1; i++) { tilecollection.push_back(Q); }
		for (int i = 0; i < 6; i++) { tilecollection.push_back(R); }
		for (int i = 0; i < 4; i++) { tilecollection.push_back(S); }
		for (int i = 0; i < 6; i++) { tilecollection.push_back(T); }
		for (int i = 0; i < 4; i++) { tilecollection.push_back(U); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(V); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(W); }
		for (int i = 0; i < 1; i++) { tilecollection.push_back(X); }
		for (int i = 0; i < 2; i++) { tilecollection.push_back(Y); }
		for (int i = 0; i < 1; i++) { tilecollection.push_back(Z); }		
	}
	vector<tile> withdrawtiles(vector<tile> v,int initialC) {
		SetConsoleTextAttribute(hConsole, 0xB);
		if (tilecollection.size() == 98)
			cout << "\n Initial tiles count in the bag : " << tilecollection.size() << endl;
		if (initialC == 0) {
			int count = 0;
			while (count != 7) {
				if (tilecollection.size() >= 1) {
					random_shuffle(tilecollection.begin(), tilecollection.end());
					random_shuffle(tilecollection.begin(), tilecollection.end());
					v.push_back(tilecollection[0]);
					tilecollection.erase(tilecollection.begin());
					count++;
				}
				else { 
					break;
				}
			}			
		}
		else if (initialC != 0) {
			while (initialC != 7) {
				if (tilecollection.size() >= 1) {
					random_shuffle(tilecollection.begin(), tilecollection.end());
					random_shuffle(tilecollection.begin(), tilecollection.end());
					v.push_back(tilecollection[0]);
					tilecollection.erase(tilecollection.begin());
					initialC++;
				}
				else {
					break;
				}
			}
		}
		cout << "\n Tiles remaining in the bag : " << tilecollection.size() << endl;
		return v;
	}
};
class node {
	tile data;
	node* next;

public:
	node() {
		next = NULL;
	}
	node(node& a) {
		this->data = a.data;
		this->next = a.next;
	}
	void setData(tile d) {
		data.setLetter(d.getLetter());
		data.setNumber(d.getNumber());
		data.setLocX(d.getLocX());
		data.setLocY(d.getLocY());
	}
	tile getData() {
		return data;
	}
	void setNext(node* p) {
		next = p;
	}
	
	node* getNext() {
		return next;
	}
	
};

class word {
	node* head;

public:
	word() {
		head = NULL;
	}
	node* gethead() {
		return head;
	}
	void IAS(tile a) {
		node* b = new node;
		b->setData(a);
		b->setNext(head);
		head = b;
	}
	void IAE(tile a) {
		node* b = new node;
		node* temp = head;
		if (head == NULL) {
			IAS(a);
		}
		else if (head != NULL) {
			while (temp->getNext() != NULL) {
				temp = temp->getNext();
			}
			b->setData(a);
			temp->setNext(b);
		}
	}
	void IAAP(tile a, int pos) {
		if (head == NULL || pos == 1) {
			IAS(a);
		}
		else {
			int size = 0;
			int count = 1;
			node* temp = head;
			if (temp == NULL)
				cout << "\nLinked List is empty";
			else if (temp != NULL) {
				while (temp != NULL) {
					temp = temp->getNext();
					size++;
				}
				if (pos > 0 && pos <= size) {
					node* b = new node;
					b->setData(a);
					temp = head;
					while (count != pos - 1 && temp != NULL) {
						temp = temp->getNext();
						count++;
					}
					b->setNext(temp->getNext());
					temp->setNext(b);
				}
			}
		}
	}
	int size() {
		int count = 0;
		node* temp = this->head;
		while (temp != NULL) {
			temp = temp->getNext();
			count++;
		}
		return count;
	}
};

int checkcentre = 0;
const int n = 15;
class board : public tile,bag{
	bag bg;
	tile arr[n][n];
	int checkdirection;
public:
	board() {
		checkdirection = 0;
		int x = 0;
		int y = 0;
		while (x != 14) {
			while (y != 14) {
				arr[x][y].setLetter('/') ;
				y++;
			}
			x++;
			y = 0;
		}
	}
	vector<word> placeword(word w) {
		node* temp;
		word str;
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " you want to place downward or rightwards? press 0 for downward, 1 for rightward" << endl;
		SetConsoleTextAttribute(hConsole, 0xF);
		cin >> checkdirection;
		while ((checkdirection < 0) || (checkdirection > 1)) {
			if ((checkdirection < 0) || (checkdirection > 1)) {
				SetConsoleTextAttribute(hConsole, 0xC);
				cout << " Invalid input ! press 0 for downward, 1 for rightward again. " << endl;
			}
			SetConsoleTextAttribute(hConsole, 0xF);
			cin >> checkdirection;		
		}
		
		if (checkcentre == 0) {
			if (checkdirection == 0) {
				temp = w.gethead();
				string str = "";
				while (temp != NULL) {
					str = str + temp->getData().getLetter();
					temp = temp->getNext();
				}
				if (checkwordvalidatyindictionary(str) == 1) {
					temp = w.gethead();
					for (int i = 6; i < str.size() + 6; i++) {
						tile t;
						t.setLetter(temp->getData().getLetter());
						t.setNumber(temp->getData().getNumber());
						t.setLocX(i);
						t.setLocY(6);
						temp->setData(t);
						arr[i][6] = t;
						temp = temp->getNext();
					}
					SetConsoleTextAttribute(hConsole, 0xA);
					cout << " Word placed successfully !" << endl;
					checkcentre = 1;

					vector<word> s;
					s.push_back(w);
					return s;
				}
				else {
					SetConsoleTextAttribute(hConsole, 0xC);
					cout << " Word can't be placed !" << endl;

					vector<word> empty;
					return empty;
				}
			}
			else if (checkdirection == 1) {
				temp = w.gethead();
				string str = "";
				while (temp != NULL) {
					str = str + temp->getData().getLetter();
					temp = temp->getNext();
				}
				if (checkwordvalidatyindictionary(str) == 1) {
					temp = w.gethead();
					for (int i = 6; i < str.size() + 6; i++) {
						tile t;
						t.setLetter(temp->getData().getLetter());
						t.setNumber(temp->getData().getNumber());
						t.setLocX(6);
						t.setLocY(i);
						temp->setData(t);
						arr[6][i] = t;
						temp = temp->getNext();
					}
					SetConsoleTextAttribute(hConsole, 0xA);
					cout << " Word placed successfully !" << endl;
					checkcentre = 1;

					vector<word> s;
					s.push_back(w);
					return s;
				}
				else
				{
					SetConsoleTextAttribute(hConsole, 0xC);
					cout << " Word can't be placed !" << endl;
					vector<word> empty;				
					return empty;
				}
			}
		}
		else if (checkcentre == 1) {
			int checkspace = 0;
			int X = 0;
			int Y = 0;
			SetConsoleTextAttribute(hConsole, 0xE);
			cout << " Enter Row and Column numbers for letter ("<< w.gethead()->getData().getLetter()<<") of your intended word" << endl;
			while (X < 1 || X>15) {
				SetConsoleTextAttribute(hConsole, 0xE);
				cout << " Row : ";
				SetConsoleTextAttribute(hConsole, 0xF);
				cin >> X;
				if (X < 1 || X>15) {
					SetConsoleTextAttribute(hConsole, 0xC);
					cout << " Invalid index of Row ! Enter number between 1 to 15." << endl;
				}
			}
			while (Y < 1 || Y>15) {
				SetConsoleTextAttribute(hConsole, 0xE);
				cout << " Column : ";
				SetConsoleTextAttribute(hConsole, 0xF);
				cin >> Y;
				if (Y < 1 || Y>15) {
					SetConsoleTextAttribute(hConsole, 0xC);
					cout << " Invalid index of Column ! Enter number between 1 to 15." << endl;
				}
			}
			if (arr[X - 1][Y - 1].getLetter() == '/') {
				if (checkdirection == 0) {	
					vector<word> RETURNEDalladjacentwords = checkadjacentletters(w, X, Y, checkdirection);
					if (RETURNEDalladjacentwords.size() > 0) {
						temp = w.gethead();
						for (int i = X - 1; i < w.size() + X - 1; i++) {
							if (arr[i][Y - 1].getLetter() == '/' || arr[i][Y - 1].getLetter() == '\0') {
								tile t;
								t.setLetter(temp->getData().getLetter());
								t.setNumber(temp->getData().getNumber());
								t.setLocX(i);
								t.setLocY(Y - 1);
								temp->setData(t);
								arr[i][Y - 1] = t;
							}
							temp = temp->getNext();
						}
						SetConsoleTextAttribute(hConsole, 0xA);
						cout << " Word placed successfully !" << endl;
						return RETURNEDalladjacentwords;
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 0xC);
						cout << " Word can't be placed !" << endl;
						vector<word> s;
						return s;
					}
				}
				else if (checkdirection == 1) {
					vector<word> RETURNEDalladjacentwords = checkadjacentletters(w, X, Y, checkdirection);
					if (RETURNEDalladjacentwords.size() > 0) {
						temp = w.gethead();
						for (int i = Y - 1; i < w.size() + Y - 1; i++) {
							if (arr[X - 1][i].getLetter() == '/' || arr[X - 1][i].getLetter() == '\0') {
								tile t;
								t.setLetter(temp->getData().getLetter());
								t.setNumber(temp->getData().getNumber());
								t.setLocX(X - 1);
								t.setLocY(i);
								temp->setData(t);
								arr[X - 1][i] = t;
							}
							if (temp != NULL) {
								temp = temp->getNext();
							}
							else 
								break;
						}
						SetConsoleTextAttribute(hConsole, 0xA);
						cout << " Word placed successfully !" << endl;
						return RETURNEDalladjacentwords;
						
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 0xC);
						cout << " Word can't be placed !" << endl;
						vector<word> s;
						return s;
					}
				}
				
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 0xC);
				cout << " Cannot fit the 1st letter in the nonempty location !" << endl;
				vector<word> s;
				return s;
			}
		}
		checkcentre = 1;
	}
	vector<word> checkadjacentletters(word w, int x, int y, int dir) {
		vector<word> newwords;
		word copyw = w;
		int wordplacementpossiblity = 0;
		int adjacentwordsnotindictionary = 0;
		int inwaycheck = 0;
		int index = 0;
		node* temp1 = w.gethead();
		if (dir == 0) {
			for (int i = x-1; i < w.size() + x - 1; i++) {
				if (arr[i][y - 1].getLetter() == '/' || arr[i][y - 1].getLetter() == '\0') {
					if ((arr[i][y].getLetter() != '/' && arr[i][y].getLetter() != '\0') && (arr[i][y - 2].getLetter() != '/' && arr[i][y - 2].getLetter() != '\0')) {
						wordplacementpossiblity = 1;
						int u = y - 1;
						word n;
						arr[i][y - 1].setLetter('^');
						while (arr[i][u].getLetter() != '/' && arr[i][u].getLetter() != '\0') {
							u--;
						}
						u++;
						while (arr[i][u].getLetter() != '/' && arr[i][u].getLetter() != '\0') {
							if (arr[i][u].getLetter() == '^' && temp1!=NULL) {
								n.IAE(temp1->getData());
							}
							else {
								n.IAE(arr[i][u]);
							}
							u++;
						}
						node* temp = n.gethead();
						string str = "";
						while (temp != NULL) {
							str = str + temp->getData().getLetter();
							temp = temp->getNext();
						}
						if (checkwordvalidatyindictionary(str) == 1) {
							newwords.push_back(n);
						}
						else
						{
							cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
							adjacentwordsnotindictionary = 1;
						}
					}
					else
						if (arr[i][y].getLetter() != '/' && arr[i][y].getLetter() != '\0') {
							wordplacementpossiblity = 1;
							word n;
							int u = y;
							n.IAE(temp1->getData());
							while (arr[i][u].getLetter() != '/' && arr[i][u].getLetter() != '\0') {
								n.IAE(arr[i][u]);
								u++;
							}
							node* temp = n.gethead();
							string str = "";
							while (temp != NULL) {
								str = str + temp->getData().getLetter();
								temp = temp->getNext();
							}
							if (checkwordvalidatyindictionary(str) == 1) {
								newwords.push_back(n);
							}
							else
							{
								cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
								adjacentwordsnotindictionary = 1;
							}
						}
						else
							if (arr[i][y - 2].getLetter() != '/' && arr[i][y - 2].getLetter() != '\0') {
								wordplacementpossiblity = 1;
								word n;
								int u = y-2;
								while (arr[i][u].getLetter() != '/' && arr[i][u].getLetter() != '\0') {
									u--;
								}
								u++;
								while (arr[i][u].getLetter() != '/' && arr[i][u].getLetter() != '\0') {
									n.IAE(arr[i][u]);
									u++;
								}
								if (temp1 != NULL) {
									n.IAE(temp1->getData());
								}
								node* temp = n.gethead();
								string str = "";
								while (temp != NULL) {
									str = str + temp->getData().getLetter();
									temp = temp->getNext();
								}
								if (checkwordvalidatyindictionary(str) == 1) {
									newwords.push_back(n);
								}
								else
								{
									cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
									adjacentwordsnotindictionary = 1;
								}
							}
				}
				else
				{
					w.IAAP(arr[i][y - 1], index + 1);
					wordplacementpossiblity = 1;
					inwaycheck = 1;
				}
				index++;
				if (temp1 != NULL && inwaycheck==0) {
					temp1 = temp1->getNext();
				}
				inwaycheck = 0;
			}
			if (arr[x - 2][y - 1].getLetter() != '/' && arr[x - 2][y - 1].getLetter() != '\0') {
				wordplacementpossiblity = 1;
				int ind = 0;
				while (arr[x - 2 - ind][y-1].getLetter() != '/' && arr[x - 2 - ind][y - 1].getLetter() != '\0') {
					w.IAS(arr[x - 2 - ind][y - 1]);
					ind++;
				}
			}
			if (arr[x - 1 + index][y-1].getLetter() != '/' && arr[x - 1 + index][y - 1].getLetter() != '\0') {
				wordplacementpossiblity = 1;
				int ind = index;
				while (arr[x - 1 + ind][y - 1].getLetter() != '/' && arr[x - 1 + ind][y - 1].getLetter() != '\0') {
					w.IAE(arr[x - 1 + ind][y - 1]);
					ind++;
				}
			}
		}
		else if (dir == 1) {
			for (int i = y - 1; i < w.size() + y - 1; i++) {
				
				if (arr[x - 1][i].getLetter() == '/' || arr[x - 1][i].getLetter() == '\0') {
					if ((arr[x][i].getLetter() != '/' && arr[x][i].getLetter() != '\0') && (arr[x - 2][i].getLetter() != '/' && arr[x - 2][i].getLetter() != '\0')) {
						wordplacementpossiblity = 1;
						int u = x - 2;
						word n;
						arr[x - 1][i].setLetter('^');
						while (arr[u][i].getLetter() != '/' && arr[u][i].getLetter() != '\0') {
							u--;
						}
						u++;
						while (arr[u][i].getLetter() != '/' && arr[u][i].getLetter() != '\0') {
							if (arr[u][i].getLetter() == '^' && temp1!=NULL) {
								n.IAE(temp1->getData());
							}
							else {
								n.IAE(arr[u][i]);
							}
							u++;
						}
						node* temp = n.gethead();
						string str = "";
						while (temp != NULL) {
							str = str + temp->getData().getLetter();
							temp = temp->getNext();
						}
						if (checkwordvalidatyindictionary(str) == 1) {
							newwords.push_back(n);
						}
						else
						{
							cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
							adjacentwordsnotindictionary = 1;
						}
					}
					else
						if (arr[x][i].getLetter() != '/' && arr[x][i].getLetter() != '\0') {
							wordplacementpossiblity = 1;
							word n;
							n.IAE(temp1->getData());
							int u = x;
							while (arr[u][i].getLetter() != '/' && arr[u][i].getLetter() != '\0') {
								n.IAE(arr[u][i]);
								u++;
							}
							node* temp = n.gethead();
							string str = "";
							while (temp != NULL) {
								str = str + temp->getData().getLetter();
								temp = temp->getNext();
							}
							if (checkwordvalidatyindictionary(str) == 1) {
								newwords.push_back(n);
							}
							else
							{
								cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
								adjacentwordsnotindictionary = 1;
							}
						}
						else
							if (arr[x - 2][i].getLetter() != '/' && arr[x - 2][i].getLetter() != '\0') {
								wordplacementpossiblity = 1;
								word n;
								int u = x-2;
								while (arr[u][i].getLetter() != '/' && arr[u][i].getLetter() != '\0') {
									u--;
								}
								u++;
								while (arr[u][i].getLetter() != '/' && arr[u][i].getLetter() != '\0') {
									n.IAE(arr[u][i]);
									u++;
								}
								if (temp1 != NULL) {
									n.IAE(temp1->getData());
								}
								node* temp = n.gethead();
								string str="";
								while (temp != NULL) {
									str = str + temp->getData().getLetter();
									temp = temp->getNext();
								}
								if (checkwordvalidatyindictionary(str) == 1) {
									newwords.push_back(n);

								}
								else
								{
									cout << " *Adjacent words formation not possible as they are not in the dictionary !" << endl;
									adjacentwordsnotindictionary = 1;
								}
								
							}
				}
				else
				{
					w.IAAP(arr[x - 1][i], index + 1);
					wordplacementpossiblity = 1;
					inwaycheck = 1;
				}
				index++;
				if (temp1 != NULL && inwaycheck==0) {
					temp1 = temp1->getNext();
				}
				inwaycheck = 0;
			}
			if (arr[x - 1][y - 2].getLetter() != '/' && arr[x - 1][y - 1].getLetter() != '\0') {
				wordplacementpossiblity = 1;
				int ind = 0;
				while (arr[x - 1][y - 2 - ind].getLetter() != '/' && arr[x - 1][y - 2 - ind].getLetter() != '\0') {
					w.IAS(arr[x - 1][y - 2 - ind]);
					ind++;
				}
			}
			if (arr[x - 1][y - 1 + index].getLetter() != '/' && arr[x - 1][y - 1 + index].getLetter() != '\0') {
				wordplacementpossiblity = 1;
				int ind = index;
				while (arr[x - 1][y - 1 + ind].getLetter() != '/' && arr[x - 1][y - 1 + ind].getLetter() != '\0') {
					w.IAE(arr[x - 1][y - 1 + ind]);
					ind++;
				}
			}
		}
		node* temp2 = w.gethead();
		string str = "";
		while (temp2 != NULL) {
			str = str + temp2->getData().getLetter();
			temp2 = temp2->getNext();
		}
		if (checkwordvalidatyindictionary(str) == 1 && adjacentwordsnotindictionary == 0 && wordplacementpossiblity == 1) {
			newwords.push_back(w);
			return newwords;
		}
		else if(adjacentwordsnotindictionary == 1 ) {
			vector<word> empty;
			return empty;
		}
		else if (wordplacementpossiblity == 0) {
			SetConsoleTextAttribute(hConsole, 0xC);
			cout << " Entered letters doesnot join with pre-existing letters to make a complete word existing in dictionary !" << endl;
			vector<word> empty;
			return empty;
		}		
	}
	bool checkwordvalidatyindictionary(string w) {
		unordered_set<string> dictionary;

		ifstream file("CompleteDictionary.txt");
		if (file.is_open()) {
			string word;
			while (getline(file, word)) {
				dictionary.insert(word);
			}
			file.close();
		}
		else {
			SetConsoleTextAttribute(hConsole, 0xC);
			cout << "Unable to open the dictionary file." << endl;
			return 0;
		}

		if (dictionary.count(w) > 0) {
			SetConsoleTextAttribute(hConsole, 0xA);
			cout << "Word ("<<w<<") is in the dictionary." << endl;
			return 1;
		}
		else {
			SetConsoleTextAttribute(hConsole, 0xC);
			cout << "Word (" << w << ") is not in the dictionary." << endl;
			return 0;
		}
	}
	void displayboard() {
		SetConsoleTextAttribute(hConsole, 0xB);
		cout << "\n                                            <<<<   Board   >>>> " << endl;
		int index1 = 0;
		int index2 = 0;
		int dispcoloumn = 0;
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << "       ";
		while (dispcoloumn != 15) {
			cout << dispcoloumn +1<< ")     ";
			dispcoloumn++;
		}
		do{
			if (index1 >8 )
				cout << "\n       -----------------------------------------------------------------------------------------------------------\n " << index1+1 << " ) ";
			else if(index1==0)
				cout << "\n\n " << index1 + 1 << "  ) ";
			else
				cout << "\n       -----------------------------------------------------------------------------------------------------------\n " << index1 + 1 << "  ) ";
			do{
				if (index2 > 10)
					cout << " ";
				if (arr[index1][index2].getLetter() == '/' || arr[index1][index2].getLetter() == '\0') {
					cout << "     |";
				}
				else {
					SetConsoleTextAttribute(hConsole, 0xB);
					cout << "  " << arr[index1][index2].getLetter();
					SetConsoleTextAttribute(hConsole, 0xE);
					cout<< "  |";
				}
				index2++;
				if (index2 != 10) {
					cout << " ";
				}
				else
					cout << "  ";
			}while (index2 != 15);
			
			index1++;
			index2 = 0;
		}while (index1 != 15);
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << "\n       -----------------------------------------------------------------------------------------------------------\n " << endl;
		cout << arr[14][14].getLetter();
	}
	vector<tile> withdraw(vector<tile> v,int a) {
		return bg.withdrawtiles(v,a);
	}
};

static board b;
class player : public bag{
	int score;
	string name;
	vector<tile> rack;
	vector<word> allwords;

public:
	player() {
		name = "";
		score = 0;
	}
	void setname(string n) {
		name = n;
	}
	string getname() {
		return name;
	}
	void setRack(vector<tile> r) {
		rack = r;
	}
	vector<tile> getRack() {
		return rack;
	}
	void setScore(int s) {
		score = s;
	}
	int getScore() {
		return score;
	}
	void setAllwords(vector<word> words) {
		allwords = words;
	}
	vector<word> getAllwords() {
		return allwords;
	}
	int addword() {
		if (rack.empty()) {
			rack = b.withdraw(rack, 0);
		}
		SetConsoleTextAttribute(hConsole, 3);
		cout << "\n Rack of "<<name<<" : " << endl;
		displayrack();
		int check = 0;
		int index = 0;
		word w;
		char c = '^';
		vector<tile> copyrack = rack;
		while (c != '/') {
			SetConsoleTextAttribute(hConsole, 0xE);
			cout << " Enter your word(in capital letters) letter by letter and enter '/' to end your word OR enter '!' to pass the turn" << endl;
			SetConsoleTextAttribute(hConsole, 0xF);
			cin >> c;
			for (int i = 0; i < rack.size(); i++) {
				if ((c == rack[i].getLetter()) && (c != '/')) {
					int index1 = 0;
					while (index1 != copyrack.size()) {
						if (c == copyrack[index1].getLetter()) {
							index = i;
							check = 1;
							break;
						}
						index1++;
					}
					if (check == 1) {
						break;
					}
				}

			}
			if (c == '/') {
				break;
			}
			if (c == '!') {
				return 2;
			}
			else if (check == 1) {
				w.IAE(rack[index]);
				int index2 = 0;
				while (index2 != copyrack.size()) {
					if (rack[index].getLetter() == copyrack[index2].getLetter()) {
						copyrack.erase(copyrack.begin() + index2);
						break;
					}
					index2++;
				}
				check = 0;
			}
			else
			{
				SetConsoleTextAttribute(hConsole, 0xC);
				cout << " You do not have this letter tile in your rack OR you have already picked this tile ! Please enter letter again which is present in your rack." << endl;
			}			
		}
		word copyword;
		node* temp = w.gethead();
		while (temp != NULL) {
			copyword.IAE(temp->getData());
			temp = temp->getNext();
		}
		vector<word> wordsreturned = b.placeword(w);
		if (!wordsreturned.empty()) {
			word mainword = wordsreturned.back();
			if (mainword.gethead() != NULL) {
				subtractRack(copyword);
				rack = b.withdraw(rack, rack.size());
				SetConsoleTextAttribute(hConsole, 3);
				cout << "\n Updated rack of " << name << " : " << endl;
				displayrack();
				vector<word> ::iterator it = wordsreturned.begin();
				while (wordsreturned.size() != 0) {
					allwords.push_back(wordsreturned.front());
					wordsreturned.erase(wordsreturned.begin());
				}
				this->scorecount(mainword);
			}
			return 1;
		}
		else 
			return 0;
	}
	void subtractRack(word w) {
		node* temp = w.gethead();
		typename vector<tile>::iterator it = rack.begin();
		
		while (temp!=NULL) {
			while (it != rack.end()) {
				if (temp->getData().getLetter() == (*it).getLetter()) {
					rack.erase(it);
					break;
				}else
					it++;
			}
			it = rack.begin();
			temp = temp->getNext();
		}
	}
	void scorecount(word w) {
		node* temp = w.gethead();
		while (temp != NULL) {
			if (temp->getData().getLetter() != '/') {
				score = score + temp->getData().getNumber();
				temp = temp->getNext();
			}
		}
	}
	void displayrack() {
		int count = 0;
		typename vector<tile> ::iterator it = rack.begin();
		while (it!=rack.end()) {
			SetConsoleTextAttribute(hConsole, 3);
			cout << " " << count+1 << " ) " << rack[count].getLetter() << " (" << rack[count].getNumber() << ")" << endl;
			count++;
			it++;
		}
		cout << "\n";
	}
	void displayscore() {
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << "\n " << name << "'s Total Score : ";
		SetConsoleTextAttribute(hConsole, 0xA);
		cout<< this->score << endl;
	}
	void displayallwords() {
		int count = 1;
		int individualscore = 0;
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " " << name << "'s words with their individual scores in the bracket : "<< endl;
		vector<word>::iterator it = allwords.begin();
		while (it != allwords.end()) {
			cout << " " << count << " ) ";
			node* temp = (*it).gethead();
			while (temp != NULL) {
				cout << temp->getData().getLetter();
				individualscore = individualscore + temp->getData().getNumber();
				temp=temp->getNext();
			}
			cout << " (";
			SetConsoleTextAttribute(hConsole, 0xA);
			cout << individualscore;
			SetConsoleTextAttribute(hConsole, 0xE);
			cout<< ")" << endl;
			it++;
			count++;
			individualscore = 0;
		}
	}
	void dispBoard() {
		b.displayboard();
	}
};

int main() {
	SetConsoleTextAttribute(hConsole, 0xB);
	cout << "                     <<<<<<<<<<<<<<<<<<<<<<<<<< welcome to faizan's scrabble >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	SetConsoleTextAttribute(hConsole, 0xE);

	cout << "\n Enter number of players (min 2 | max 4): " << endl;
	int num = 0;
	while (num < 2 || num > 4) {
		SetConsoleTextAttribute(hConsole, 0xF);
		cin >> num;
		if (num < 2 || num > 4) {
			SetConsoleTextAttribute(hConsole, 0xC);
			cout << " Invalid input ! Enter 2, 3 or 4 number of players." << endl;
		}
	}
	player* players = new player[num];
	int count = 0;
	int turn = 0;
	int pass = 0;
	int checkplacement = 0;
	while (count != num) {
		string plrname;
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " Enter " << count + 1 << "# player's name : " << endl;
		SetConsoleTextAttribute(hConsole, 0xF);
		cin >> plrname;
		players[count].setname(plrname);
		count++;
	}
	while (true) {
		if (turn == num) {
			turn = 0;
		}
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " " << players[turn].getname() << "'s turn ->" << endl;
		players[turn].displayscore();
		checkplacement = players[turn].addword();
		if (checkplacement == 0) {
			SetConsoleTextAttribute(hConsole, 0xC);
			cout << " Try Again !" << endl;
		}
		else if (checkplacement == 2) {
			pass++;  //pass chain starts or continues
			if (pass == num + 1) {
				break;  //if pass chain comes back to the person who started the chain...game ends
			}
			else
				turn++;
		}
		else if (checkplacement == 1) {
			pass = 0;  //here the pass chain breaks
			SetConsoleTextAttribute(hConsole, 0xE);
			players[turn].displayscore();
			players[turn].displayallwords();
			players[turn].dispBoard();
			vector<tile> r = players[turn].getRack();
			if (r.size() == 0) {
				break;
			}
			else
				turn++;
		}
	}
	int scoreofleftovertiles = 0;
	vector<tile> leftoverRack;
	vector<player> finalresultofplayers;
	int sum = 0;
	int sum1 = 0;
	int highestScore = 0;
	int emptyrackplayerindex = 0;
	string nameofhighestscoreholder = "";
	int count1 = 0;
	while (count1 < num) {
		leftoverRack = players[count1].getRack();
		if (leftoverRack.size() == 0) {
			emptyrackplayerindex = count1;
		}
		typename vector<tile> ::iterator it = leftoverRack.begin();
		while (it != leftoverRack.end()) {
			scoreofleftovertiles = scoreofleftovertiles + (*it).getNumber();
			it++;
		}
		player p;
		p.setname(players[count1].getname());
		sum = players[count1].getScore() - scoreofleftovertiles;
		sum1 = sum1 + scoreofleftovertiles;

		if (sum > highestScore) {
			highestScore = sum;
			nameofhighestscoreholder = players[count1].getname();
		}
		p.setScore(sum);
		//p.setAllwords(players[count].getAllwords());
		finalresultofplayers.push_back(p);
		count1++;
		scoreofleftovertiles = 0;
	}

	if (pass == 0) {
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " *Game Ended due to empty rack of a player*" << endl;
		finalresultofplayers[emptyrackplayerindex].setScore(finalresultofplayers[emptyrackplayerindex].getScore() + sum1);
		typename vector<player> ::iterator itp = finalresultofplayers.begin();
		SetConsoleTextAttribute(hConsole, 0xF);
		while (itp != finalresultofplayers.end()) {
			cout << " " << (*itp).getname() << "'s Final Score : " << (*itp).getScore() << endl;
			itp++;
		}
		SetConsoleTextAttribute(hConsole, 0xB);
		cout << "              <<<<<<<<<<<<<<<  Winner of this game is *** " << nameofhighestscoreholder << " *** having highest score (" << highestScore + sum1 << ")  >>>>>>>>>>>>>>>>" << endl;

	}
	else if (pass > 0) {
		SetConsoleTextAttribute(hConsole, 0xE);
		cout << " *Game Ended by giving up the turns*" << endl;
		typename vector<player> ::iterator itp = finalresultofplayers.begin();
		SetConsoleTextAttribute(hConsole, 0xF);
		while (itp != finalresultofplayers.end()) {
			cout << " " << (*itp).getname() << "'s Final Score : " << (*itp).getScore() << endl;
			itp++;
		}
		SetConsoleTextAttribute(hConsole, 0xB);
		if (highestScore <= 0) {
			cout << "                ** No one is the winner as all the players have their scores less than or equal to zero  **" << endl;
		}else
			cout << "              <<<<<<<<<<<<<<<  Winner of this game is *** " << nameofhighestscoreholder << " *** having highest score (" << highestScore << ")  >>>>>>>>>>>>>>>>" << endl;

	}
}