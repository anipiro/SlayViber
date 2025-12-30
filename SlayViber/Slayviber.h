#pragma once
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
class SlayViber
{
private:
	string username, password;
	bool streaming, isRegistered, hasShezgudva;
	int followers;
	vector<string> visitors;

	static vector<string> usernames;
	static string generateDefaultUser();
	static void sarezervoUser(const string& s);
	static bool isUsernameTaken(const string& s);
	static int pctChange(int base, double pct);
	static mt19937& rng();

public:
	SlayViber();
	SlayViber(const string& username, const string& password, int followers = 0, bool hasShezgudva = false);
	const string& getUsername() const { return username; }
	const string& getPassword() const { return password; }
	bool getStreaming()const { return streaming; }
	int getFollowers()const { return followers; }
	bool getIsRegistered()const { return isRegistered; }
	bool getHasShezgudva()const { return hasShezgudva; }
	const vector<string>& getVisitors()const { return visitors; }

	void setShezgudva(bool a)
	{
		hasShezgudva = a;
		if (a) streaming = false;
	}
	void setStreaming(bool a) { streaming = a; }
	void setFollowers(int f) { followers = f; }
	void print()const;
	void visit(SlayViber& other);
	void registracia();
	void goLive();
	void kolaboracia(SlayViber& partner);
};