#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "point.h"

namespace Processing
{
	enum Directions{
		D_N,
		D_E,
		D_S,
		D_W,
		D_NE,
		D_NW,
		D_SE,
		D_SW
	};

	class DBNode{
	public:
		//DBNode(int, std::string , int* );
		DBNode(int);
		DBNode(const DBNode&);
		int getNumber() const;
		std::string getContent() const;
		void setContent(std::string);

		int getNextNodeNumber(Directions) const;
		int getNextNodeNumber(int) const;
		void setNextNodeNumber(int, int);

	private:
		int number;
		std::string content;
		int* nextNodesNumbers;
	};

	class DataBase
	{
	public:
		DataBase();
		DataBase(std::string);
		~DataBase();

		std::vector<Directions> generatePath(PList);
		std::string findPath(std::vector<Directions>);
		void addPath(std::vector<Directions>, std::string);
		std::string getFilePath();
	private:
		void loadNodes();

		std::string filePath;
		std::vector<DBNode> nodes;
	};
}
#endif // DATABASE_H
