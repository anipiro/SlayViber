#include <iostream>
#include <random>
#include "Slayviber.h"
using namespace std;

vector<string>SlayViber::usernames;
mt19937& SlayViber::rng()
{
	static mt19937 gen(static_cast<unsigned>(time(0)));
	return gen;
}
bool SlayViber::isUsernameTaken(const string& s)
{
	return find(usernames.begin(), usernames.end(), s) != usernames.end();
}
void SlayViber::sarezervoUser(const string& s)
{
	usernames.push_back(s);
}
//davagenerirebinot axla default usernameic
string SlayViber::generateDefaultUser()
{
	uniform_int_distribution<int>dist(1000, 9999);
	string kandidati;
	do
	{
		kandidati = "user " + to_string(dist(rng()));
	} while (isUsernameTaken(kandidati));
	sarezervoUser(kandidati);
	return kandidati;
}
	//procentuli cvlilebebi
	int SlayViber::pctChange(int base, double pct)
	{
		double shecvlili = static_cast<double>(base) * pct;
		int delta = static_cast<int>((shecvlili >= 0) ? (shecvlili + 0.5) : (shecvlili - 0.5));
		return base + delta;
	}
	// konstruktori
	SlayViber::SlayViber()
	{
		username = generateDefaultUser();
		password = "";
		streaming = false;
		followers = 0;
		isRegistered = false;
		hasShezgudva = false;
	}

SlayViber::SlayViber(const string& s, const string& p, int f, bool shezguduli)
{
	if (isUsernameTaken(s))
	{
		cerr << "arsebobs ukve " << s << "mogenichat default username." << endl;
		username = generateDefaultUser();
	} else
	{
		username = s;
		sarezervoUser(username);
	}
	password = p;
	followers = max(0, f);
	streaming = false;
	isRegistered = true;
	hasShezgudva = shezguduli;
}
//daprintvis funqcia
void SlayViber::print() const
{
	cout << "Username: " << username << "\n" << "registirebuli: " << boolalpha << isRegistered << "\n" << "shezguduli" << boolalpha << hasShezgudva << "\n" << "followers: " << followers << "\n" << "streaming: " << boolalpha << streaming << "\n" << "bolo vizitorebi: ";
	if (visitors.empty())
	{
		cout << "arcerti";
	} else
	{
		for (size_t i{}; i < visitors.size(); ++i)
		{
			cout << visitors[i];
			if (i + 1 < visitors.size())
			{
				cout << ", ";
			}
		}
	}
}
//visit funqcia
// mokled this -> stumari, stumari momxmareblis eqaunts "stalkavs" da gamowerac sheudzlia
void SlayViber::visit(SlayViber& other)
{
	if (this == &other)
	{
		cout << "self checking your profile? " << endl;
		return;
	}
	other.visitors.push_back(this->username);
	//axla shezguduli informaciis chveneba
	cout << "shen naxe: " << other.username << "is profili." << endl;
	//mxolod registrirebulebs rom sheedzlot gamowera
	if (!this->isRegistered)
	{
		cout << "daregistirrebis gareshe ver gamoiwer";
		return;
	}
	if (this->hasShezgudva)
	{
		cout << "eqaunts aqvs shezgudva. ver gamoiwer";
		return;
	}
	//axla vkitxot martla tu unda gamowera
	cout << "gsurs gamowera? (y/n): ";
	char choice;
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		other.followers += 1;
		cout << "gamoiwere " << other.username;
	}
	else {
		cout << "ar gamoiwere ";
	}
}

// registaciis funqcia
//mivcet registraciis ufleba imat vinc ar arian daregistrirebulebi
void SlayViber::registracia()
{
	//magalitad tu ukve daregistrirebulia
	if (isRegistered)
	{
		cout << "registrirebuli xar" << endl;
		return;
	}

	cout << "registracia" << endl;

	while (true)
	{
		cout << "sheiyvanet username: ";
		string s;
		cin >> s;
		//shevamowmot axla misi sigrdzec
		if (s.size() < 3)
		{
			cout << "minimum sami unda iyos, dzalian moklea...";
			continue;
		}
		if (isUsernameTaken(s))
		{
			cout << "arsebobs ukve, scade sxva.";
			continue;
		}
		username = s;
		sarezervoUser(username);
		break;
	}
	//davayenot parolic
	while (true)
	{
		cout << "sheiyvanet paroli(4 simboloze meti): ";
		string p;
		cin >> p;

		if (p.size() < 4)
		{
			cout << "dzalian moklea paroli." << endl;
			continue;
		}
		password = p;
		break;
	}
	isRegistered = true;
	cout << "Welcome :) " << username << "!" << endl;
}
//GOLIVE FUNQCIA
void SlayViber::goLive()
{
	if (!isRegistered)
	{
		cout << "Gaiaret registracia!" << endl;
		return;
	}
	if (hasShezgudva) {
		cout << "shezguduli xart. ver gxvalt liveshi!" << endl;
		return;
	}

	streaming = true;
	cout << username << " gasulia liveshi!" << endl;
	//shemtxvevitobis an moigebs an waagebs
	uniform_int_distribution<int>coin(0, 1); // anu 0 iqneba wageba
	int shedegi = coin(rng());
	int before = followers;
	if (shedegi==1){
		uniform_int_distribution<int>gainPct(5, 40);
		//5%-40%
		int pct = gainPct(rng());
		followers = pctChange(followers, pct / 100.0);
		cout << "gamomwerebi +" << pct << "% (" << before << " -> " << followers << ")" << endl;
	}
	else {
		uniform_int_distribution<int>dropPct(0, 30);
		//0%-30%
		int pct = dropPct(rng());
		followers = max(0, pctChange(followers, -pct / 100.0));
		cout << "gamomwerebi -" << pct << "% (" << before << " -> " << followers << ")" << endl;
		// tu daaklda
		if (pct > 25) {
			hasShezgudva = true;
			streaming = false;
			cout << "sheizgudet";
			return;
		}
	}
	//damtavrda live
	streaming = false;
	cout << "live morcha" << endl;
}
//kolabis funqcia
void SlayViber::kolaboracia(SlayViber& partner)
{
	if (this == &partner)
	{
		cout << "self kolabi ar sheidzleba!" << endl;
		return;
	}
	//orive registrirebuli
	if (!this->isRegistered || !partner.isRegistered)
	{
		cout << "orive arian daregistrirebuli!" << endl;
		return;
	}
	//orive shezguduli
	if (this->hasShezgudva || partner.hasShezgudva)
	{
		cout << "shezgudva arcerts unda hqondes" << endl;
		return;
	}
	uniform_int_distribution<int>pct(2, 12);
	int aPct = pct(rng());
	int bPct = pct(rng());
	int aGain = static_cast<int>(partner.followers * (aPct / 100.0) + 0.5);
	int bGain = static_cast<int>(this->followers * (bPct / 100.0) + 0.5);
	this->visitors.push_back(partner.username);
	partner.visitors.push_back(this->username);
	int aBefore = this->followers;
	int bBefore = partner.followers;
	this->followers += aGain;
	partner.followers += bGain;
	this->streaming = false;
	partner.streaming = false;
	cout << "dasrulda" << this->username << " miigo " << aGain << aBefore << "->" << this->followers << partner.username << bGain << bBefore << partner.followers;
}