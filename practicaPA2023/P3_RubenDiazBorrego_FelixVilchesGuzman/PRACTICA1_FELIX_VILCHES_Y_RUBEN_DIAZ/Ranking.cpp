#include "Ranking.h"

void Ranking::agregar(int puntos) {

	ofstream addFile("puntos.txt", ios::app);

	if (addFile.is_open()) {
		cout << "Nombre:" << endl;
		cin >> nombre;

		addFile << nombre << " " << puntos << endl;
	}
	addFile.close();
}

void Ranking::addToVector() {

	ifstream readFile("puntos.txt");

	while (readFile >> nombre >> puntos) {
		nombres.push_back(nombre);
		ptsVector.push_back(puntos);
	}
}


void Ranking::eliminarMinVec() {

	for (int i = 0; i < ptsVector.size(); i++)
	{
		if (ptsVector[i] < ptsVector[0]) {
			swap(ptsVector[0], ptsVector[i]);
			swap(nombres[0], nombres[i]);
		}
	}

	ptsVector.erase(ptsVector.begin());
	nombres.erase(nombres.begin());
}

void Ranking::ordenarRanking() {
	for (size_t i = 1; i < ptsVector.size(); ++i) {
		for (size_t j = 0; j < ptsVector.size() - 1; ++j) {
			if (ptsVector[j] < ptsVector[i]) {
				swap(ptsVector[j], ptsVector[i]);
				swap(nombres[j], nombres[i]);
			}
		}
	}
}

void Ranking::agregarFichero() {
	ofstream addFile("puntos.txt");
	if (addFile.is_open()) {
		for (int i = 0; i < nombres.size(); i++) {
			addFile << nombres[i] << " " << ptsVector[i] << endl;
		}
	}
	addFile.close();
}

void Ranking::visualizar() {

	ifstream readFile("puntos.txt");
	string text;
	if (readFile.is_open()) {
		cout << "RANKING - Top 5: " << endl;
		while (getline(readFile, text)) {
			cout << text << endl;
		}
	}
	readFile.close();
}

void Ranking::crearRanking(int puntos) {

	agregar(puntos);
	addToVector();
	if (nombres.size() > 5) { 
		eliminarMinVec();
	}
	ordenarRanking();
	agregarFichero();
	visualizar();
}