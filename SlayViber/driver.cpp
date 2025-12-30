#include "Slayviber.h"
#include <iostream>
using namespace std;

int main()
{
	//daviwyot default momxmareblit, romelic unda davaregistrirot
	SlayViber stumari;
	stumari.print();
	//daregistrirebuli momxmarebeli
	SlayViber nia("nia", "nia123", 2005);
	nia.print();
	//duplikatebi da warningebi
	SlayViber nia2("nia", "nia1234", 205); //duplikati
	nia2.print();
	stumari.visit(nia);
	cout << "nias profilis naxvis mere: " << endl;
	nia.print();
	//stumris registracia
	cout << "sheiyvane: gio" << endl;
	cout << "sheiyvane parolad: gio1234" << endl;
	SlayViber gio("gio", "gio1234", 1999);
	gio.print();
	//naxvis/visit punqcia
	cout << "dasafolloweblad daachiret 'Y'";
	nia.setFollowers(nia.getFollowers() + 1);
	cout << "dafollowebis shemdeg: " << endl;
	nia.print();
	//goLive punqcia
	nia.goLive();
	nia.print();
	//axali momxmarebelis registracia
	SlayViber ani("ani", "ani123", 2020);
	ani.print();
	//kolaboracia
	cout << "nias da anis kolaboracia" << endl;
	nia.kolaboracia(ani);
	nia.print();
	ani.print();
	//shezgudva
	ani.setShezgudva(true);
	ani.goLive();
	ani.setShezgudva(false);
	//ani liveshi
	ani.goLive();
	ani.print();
	//axla davtestod getterebi
	cout << "nias username: " << nia.getUsername() << endl;
	cout << "nias followers: " << nia.getFollowers() << endl;
	cout << "nia davaregistriret: " << boolalpha << nia.getIsRegistered() << endl;
	cout << "nia shezgudulia: " << boolalpha << nia.getHasShezgudva() << endl;
	cout << "nias strimi: " << boolalpha << nia.getStreaming() << endl;
	//self-visit funqciac
	gio.visit(gio);
	// vinc araa momxmarebeli imis live
	SlayViber ucxo;
	ucxo.goLive();
	//visitorebis naxva
	const vector<string>& niaVisitors = nia.getVisitors();
	cout << "nias visitorebi: " << niaVisitors.size() << endl;
	cout << "vizitorebi: ";
	for (size_t i{}; i < niaVisitors.size(); ++i) {
		cout << niaVisitors[i];
		if (i + 1 < niaVisitors.size()) {
			cout << ", ";
		}
	}
	cout << "yvelaperi warmatebit dasrulda." << endl;
}