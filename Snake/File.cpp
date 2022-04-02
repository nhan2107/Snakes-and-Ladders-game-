#include "File.h"
void File::write(string s, player a, player b, turn c)
{
	ofstream f(s, ios::out | ios::binary);
	f.write((char*)&a, sizeof(a));
	f.write((char*)&b, sizeof(b));
	f.write((char*)&c, sizeof(c));
	f.close();
}
void File::open(string s, player& a, player& b, turn &c)
{
	ifstream f(s, ios::in | ios::binary);
	f.read((char*)&a, sizeof(a));
	f.read((char*)&b, sizeof(b));
	f.read((char*)&c, sizeof(c));
	f.close();
}
bool File::checkbinaryexist(string path)
{
	FILE* file;
	errno_t err;
	if ((err = fopen_s(&file, path.c_str(), "r")) == 0) 
	{
		fclose(file);
		return true;
	}
	return false;
}
void File::deleteoneline(string path, string eraseLine)
{
	string line;
	ifstream fin;
	fin.open(path);
	ofstream temp;
	const char* t = "temp.txt";
	temp.open(t);
	while (getline(fin, line))
	{
		if (line != eraseLine)
		{
			temp << line << endl;
		}
	}
	temp.close();
	fin.close();
	const char* p = path.c_str();
	remove(p);
	rename(t, p);
}